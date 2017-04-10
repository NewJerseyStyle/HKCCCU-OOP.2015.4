#include <iostream>
#include <fstream>
#include <functional>
#include "Source.h"
#include "Jungle_Chess.h"
#include "Header.h"
#include "MyForm.h"
#include "SaveDialog.h"
#include "Tuto.h"
#include "QuitQuest.h"
#include "sha1.h"

#define KEYLEN  40

using namespace System;
using namespace System::Windows::Forms;

Game JC;
extern int _FLAG;
extern int _SIDE0;
extern int _SIDE1;
void save();
void load();

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SendMessageCallback((HWND)-1,CB_ADDSTRING,0,0,0,0);
	do{
		Jungle_Chess::MyForm Startform;
		Application::Run(%Startform);
		switch(Startform.choice){
		case 3:
			JC.ai.AI_FLAG=true;
			//new AI
			break;
		case 4:
			//new Player vs Player
			break;
		case 5:
			JC.ai.AI_FLAG=true;
			_FLAG=3;//decription
			//read AI saved
			break;
		case 6:
			_FLAG=3;//decription
			//read PvP saved
			break;
		default:
			std::cerr<<"Game Interrupted";
			exit(1);
			break;
		}
		do{
			Jungle_Chess::Jungle_Chess form;
			if(_FLAG==1||_FLAG==2){
				_SIDE0=0;
				_SIDE1=0;
				vector<player>().swap(JC.players);
				vector<Animal>().swap(JC.animals);
				JC.board.clear();
			}
			if(_FLAG!=3){
				JC.initializing();
			}else{
				load();
				form.LoadDisplay();
				if(_FLAG==2) break;
			}
			if(_FLAG==1||_FLAG==2||_FLAG==3){
				_FLAG=0;
			}
			form.display();
			try
		    {
			   Application::Run(%form);
			}catch ( ObjectDisposedException^ e )
			{
				cerr<<"System.ObjectDisposedException ERROR";
			}
		}while(_FLAG==1);
	}while(_FLAG==2);
}

System::Void Jungle_Chess::Jungle_Chess::display(){//Xu Yuan : 5405 9605
	for(int i=0;i!=BOARD_X;i++){
		for(int j=0;j!=BOARD_Y;j++){
			if(JC.board.grids[i][j].occupant.alive==true)
			{
				switch(JC.board.grids[i][j].occupant.power){
				case 1:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Rat_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Rat_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 2:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Cat_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Cat_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 3:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Wolf_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Wolf_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 4:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Dog_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Dog_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 5:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Leopard_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Leopard_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 6:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Tiger_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Tiger_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 7:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Lion_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Lion_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				case 8:
					{
						if(JC.board.grids[i][j].occupant.owner.name==JC.players[0].name)
						{
							this->Elephant_B->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
						else
						{
							this->Elephant_R->Location = System::Drawing::Point(7+i*MoveHorizontal, 10+j*MoveVertical);
						}
					}
					break;
				default:
					break;
				}
			}
		}
	}
	++JC.currentIndex;
	JC.currentIndex&=1;
	if(JC.currentIndex==1){
		this->GreenDot->Location = System::Drawing::Point(111, 376);
		_TURN='B';//B for blue
	}
	else{
		this->GreenDot->Location = System::Drawing::Point(111, 81);
		_TURN='R';//R for red
	}
	if(JC.rule.getWinner(JC.board).name!=JC.players[0].name&&JC.rule.getWinner(JC.board).name!=""){
		this->CONTINUE->Visible=true;
		this->VICTORY->Visible=true;
		this->VICTORY->Load("./Pic/Red victory.png");
		//this->name->Load("./Pic/");
	}
	else{
		if(JC.rule.getWinner(JC.board).name!=""){
			this->CONTINUE->Visible=true;
			this->VICTORY->Visible=true;
			this->VICTORY->Load("./Pic/Blue victory.png");
		}
	}
	if((JC.ai.AI_FLAG==true)&&(JC.currentIndex==1)){
		int id=0,x=0,y=0,newX=0,newY=0;
		JC.currentIndex=0;
		JC.ai.decideMove(id,x,y,newX,newY,JC.board);
		this->ShowMove(x,y,newX,newY);
	}
}

System::Void Jungle_Chess::Jungle_Chess::Save_Click(System::Object^  sender, System::EventArgs^  e){//Jasper Lo :5401 8936
	SaveDialog^ saving = gcnew SaveDialog();
	saving->Show();
	save();
}

System::Void Jungle_Chess::Jungle_Chess::Tutorial_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	Tuto^ t = gcnew Tuto();
	t->Show();
		 }

System::Void Jungle_Chess::Jungle_Chess::searchAVmove(int x, int y){// Xu Yuan : 5405 9605
	int posX = (x-7)/MoveHorizontal;
	int posY = (y-10)/MoveVertical;
	int flag=0;
	int leftxy_upxy_rightxy_downxy[8];
	this->left->Visible=false;
	this->up->Visible=false;
	this->right->Visible=false;
	this->down->Visible=false;
	if(!JC.board.grids[posX][posY].occupant.alive) return;
	JC.rule.searchMove(posX, posY, JC.board, leftxy_upxy_rightxy_downxy);
	if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
	{
		flag=1;
	}
	posX = 7+leftxy_upxy_rightxy_downxy[0]*MoveHorizontal;
	posY = 10+leftxy_upxy_rightxy_downxy[1]*MoveVertical;
	if(posX>=0&&posY>=0)
	{
		if(flag)
		{
			this->left->Load("./Pic/AvailableMovementBlue.fw.png");
		}
		else
		{
			this->left->Load("./Pic/AvailableMovementRed.png");
		}
		this->left->Location = System::Drawing::Point(posX, posY);
		this->left->Visible=true;
	}
	posX = 7+leftxy_upxy_rightxy_downxy[2]*MoveHorizontal;
	posY = 10+leftxy_upxy_rightxy_downxy[3]*MoveVertical;
	if(posX>=0&&posY>=0)
	{
		if(flag)
		{
			this->up->Load("./Pic/AvailableMovementBlue.fw.png");
		}
		else
		{
			this->up->Load("./Pic/AvailableMovementRed.png");
		}
		this->up->Location = System::Drawing::Point(posX, posY);
		this->up->Visible=true;
	}
	posX = 7+leftxy_upxy_rightxy_downxy[4]*MoveHorizontal;
	posY = 10+leftxy_upxy_rightxy_downxy[5]*MoveVertical;
	if(posX>=0&&posY>=0)
	{
		if(flag)
		{
			this->right->Load("./Pic/AvailableMovementBlue.fw.png");
		}
		else
		{
			this->right->Load("./Pic/AvailableMovementRed.png");
		}
		this->right->Location = System::Drawing::Point(posX, posY);
		this->right->Visible=true;
	}
	posX = 7+leftxy_upxy_rightxy_downxy[6]*MoveHorizontal;
	posY = 10+leftxy_upxy_rightxy_downxy[7]*MoveVertical;
	if(posX>=0&&posY>=0)
	{
		if(flag)
		{
			this->down->Load("./Pic/AvailableMovementBlue.fw.png");
		}
		else
		{
			this->down->Load("./Pic/AvailableMovementRed.png");
		}
		this->down->Location = System::Drawing::Point(posX, posY);
		this->down->Visible=true;
	}
}

System::Void Jungle_Chess::QuitQuest::button1_Click(System::Object^  sender, System::EventArgs^  e) {//Wong Po Yee : 5407 0357
	exit(0);
}

System::Void Jungle_Chess::Jungle_Chess::Quit_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	QuitQuest^ quitQuest = gcnew QuitQuest();
	quitQuest->Show();
}

System::Void Jungle_Chess::Jungle_Chess::ShowMove(int x, int y, int newX, int newY)
{
	int posX = (newX-7)/MoveHorizontal;
	int posY = (newY-10)/MoveVertical;
	x=(x-7)/MoveHorizontal;
	y=(y-10)/MoveVertical;
	if(!JC.rule.CheckMove(x, y, posX, posY, JC.board))
	{
		if(this->Cover->Visible||((JC.ai.AI_FLAG==true)&&(JC.currentIndex==0)))
		{
			if(JC.board.grids[posX][posY].occupant.alive)
			{
				if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name){
					JC.animals[(JC.board.grids[posX][posY].occupant.power-1)*2].alive=false;
					++_SIDE0;
					newX=13+((_SIDE0-1)%2)*63;
					newY=414+((_SIDE0-1)/2)*60;
				}else{
					JC.animals[(JC.board.grids[posX][posY].occupant.power*2)-1].alive=false;
					++_SIDE1;
					newX=13+((_SIDE1-1)%2)*63;
					newY=114+((_SIDE1-1)/2)*60;
				}
				switch(JC.board.grids[posX][posY].occupant.power){
				case 1:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Rat_B->Parent = this->panel1->Parent;
						this->Rat_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Rat_R->Parent = this->panel1->Parent;
						this->Rat_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 2:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Cat_B->Parent = this->panel1->Parent;
						this->Cat_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Cat_R->Parent = this->panel1->Parent;
						this->Cat_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 3:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Wolf_B->Parent = this->panel1->Parent;
						this->Wolf_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Wolf_R->Parent = this->panel1->Parent;
						this->Wolf_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 4:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Dog_B->Parent = this->panel1->Parent;
						this->Dog_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Dog_R->Parent = this->panel1->Parent;
						this->Dog_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 5:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Leopard_B->Parent = this->panel1->Parent;
						this->Leopard_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Leopard_R->Parent = this->panel1->Parent;
						this->Leopard_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 6:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Tiger_B->Parent = this->panel1->Parent;
						this->Tiger_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Tiger_R->Parent = this->panel1->Parent;
						this->Tiger_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 7:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Lion_B->Parent = this->panel1->Parent;
						this->Lion_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Lion_R->Parent = this->panel1->Parent;
						this->Lion_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				case 8:
					if(JC.board.grids[posX][posY].occupant.owner.name==JC.players[0].name)
					{
						this->Elephant_B->Parent = this->panel1->Parent;
						this->Elephant_B->Location = System::Drawing::Point(newX, newY);
					}
					else
					{
						this->Elephant_R->Parent = this->panel1->Parent;
						this->Elephant_R->Location = System::Drawing::Point(newX, newY);
					}
					break;
				default:
					break;
				}
			}
			JC.board.grids[posX][posY].occupant.alive=JC.board.grids[x][y].occupant.alive;
			JC.board.grids[x][y].occupant.alive=false;
			JC.board.grids[posX][posY].occupant.name=JC.board.grids[x][y].occupant.name;
			JC.board.grids[x][y].occupant.name="";
			JC.board.grids[posX][posY].occupant.owner.name=JC.board.grids[x][y].occupant.owner.name;
			JC.board.grids[x][y].occupant.owner.name="";
			JC.board.grids[posX][posY].occupant.power=JC.board.grids[x][y].occupant.power;
			JC.board.grids[x][y].occupant.power=0;
			display();

#ifdef DEBUG
		cout<<endl;
		cout<<"\tx\ty\tName\tOwner\tID\n";
		for(int i=0;i<BOARD_X;i++)
		{
			for(int j=0;j<BOARD_Y;j++)
			{
				if(JC.board.grids[i][j].occupant.alive)
					cout<<"\t"<<i<<"\t"<<j<<"\t"<<JC.board.grids[i][j].occupant.name<<"\t"<<JC.board.grids[i][j].occupant.owner.name<<"\t"<<JC.board.grids[i][j].id<<endl;
			}
		}
#endif
		}
	}
	this->Cover->Visible=false;
	//this->left->Load("");
	this->left->Visible=false;
	//this->up->Load("");
	this->up->Visible=false;
	//this->right->Load("");
	this->right->Visible=false;
	//this->down->Load("");
	this->down->Visible=false;
}
System::Void Jungle_Chess::Jungle_Chess::LoadDisplay(){//Xu Yuan : 5405 9605
	int newX=0, newY=0;
	int side_0, side_1;
	side_0=0;
	side_1=0;
	for(vector<Animal>::iterator iter = JC.animals.begin(); iter != JC.animals.end(); ++iter){
		if(iter->alive==false)
		{
			if(iter->owner.name==JC.players[0].name){
				++side_0;
				newX=13+((side_0-1)%2)*63;
				newY=414+((side_0-1)/2)*60;
			}else{
				++side_1;
				newX=13+((side_1-1)%2)*63;
				newY=114+((side_1-1)/2)*60;
			}
			switch(iter->power){
			case 1:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Rat_B->Parent = this->panel1->Parent;
					this->Rat_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Rat_R->Parent = this->panel1->Parent;
					this->Rat_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 2:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Cat_B->Parent = this->panel1->Parent;
					this->Cat_B->Location = System::Drawing::Point(newX, newY);
				}
			else
				{
					this->Cat_R->Parent = this->panel1->Parent;
					this->Cat_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 3:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Wolf_B->Parent = this->panel1->Parent;
					this->Wolf_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Wolf_R->Parent = this->panel1->Parent;
					this->Wolf_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 4:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Dog_B->Parent = this->panel1->Parent;
					this->Dog_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Dog_R->Parent = this->panel1->Parent;
					this->Dog_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 5:
				if(iter->owner.name==JC.players[0].name)
				{
				this->Leopard_B->Parent = this->panel1->Parent;
					this->Leopard_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Leopard_R->Parent = this->panel1->Parent;
					this->Leopard_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 6:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Tiger_B->Parent = this->panel1->Parent;
					this->Tiger_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Tiger_R->Parent = this->panel1->Parent;
					this->Tiger_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 7:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Lion_B->Parent = this->panel1->Parent;
					this->Lion_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Lion_R->Parent = this->panel1->Parent;
					this->Lion_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			case 8:
				if(iter->owner.name==JC.players[0].name)
				{
					this->Elephant_B->Parent = this->panel1->Parent;
					this->Elephant_B->Location = System::Drawing::Point(newX, newY);
				}
				else
				{
					this->Elephant_R->Parent = this->panel1->Parent;
					this->Elephant_R->Location = System::Drawing::Point(newX, newY);
				}
				break;
			default:
				break;
			}
		}
	}
}

System::Void Jungle_Chess::Jungle_Chess::left_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	if(this->Cover->Visible)
	{
		this->ShowMove(this->Cover->Location.X, this->Cover->Location.Y, this->left->Location.X, this->left->Location.Y);
	}
}

System::Void Jungle_Chess::Jungle_Chess::up_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	if(this->Cover->Visible)
	{
		this->ShowMove(this->Cover->Location.X, this->Cover->Location.Y, this->up->Location.X, this->up->Location.Y);
	}
}

System::Void Jungle_Chess::Jungle_Chess::right_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	if(this->Cover->Visible)
	{
		this->ShowMove(this->Cover->Location.X, this->Cover->Location.Y, this->right->Location.X, this->right->Location.Y);
	}
}

System::Void Jungle_Chess::Jungle_Chess::down_Click(System::Object^  sender, System::EventArgs^  e) {//Hung Tsz Yiu :54055993
	if(this->Cover->Visible)
	{
		this->ShowMove(this->Cover->Location.X, this->Cover->Location.Y, this->down->Location.X, this->down->Location.Y);
	}
}

string hashing(const char* fileName){//Xu Yuan : 5405 9605
    ifstream  file;
	streampos size;
	char* memblock;
	file.open(fileName, ios::in|ios::binary|ios::ate);//fstream::binary
	if (file.is_open())
    {
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
		file.read (memblock, size);
		file.close();
    }
	string tmp(memblock);
	tmp = sha1(tmp);
	delete[] memblock;
	return tmp;
}

void save(){//Hung Tsz Yiu :54055993
    ofstream fout;
    fout.open("save.txt");
    for (int i=0;i<16;i++)
    {
        fout << "<" << JC.animals[i].alive <<">" << endl;
		fout << "<" << JC.animals[i].name <<">" << endl;
		fout << "<" << JC.animals[i].owner.name <<">" << endl;
		fout << "<" << JC.animals[i].power <<">" << endl;
    }
	fout << "<" << _FLAG <<">" << endl;
	fout << "<" << _SIDE0 <<">" << endl;
	fout << "<" << _SIDE1 <<">" << endl;
    for (int i=0;i<BOARD_X;i++)
    {
        for(int j=0;j<BOARD_Y;j++)
        {
			fout << "<" << JC.board.grids[i][j].id <<">" << endl;
			fout << "<" << JC.board.grids[i][j].occupant.alive <<">" << endl;
			fout << "<" << JC.board.grids[i][j].occupant.name <<">" << endl;
			fout << "<" << JC.board.grids[i][j].occupant.owner.name <<">" << endl;
			fout << "<" << JC.board.grids[i][j].occupant.power <<">" << endl;
			fout << "<" << JC.board.grids[i][j].owner.name <<">" << endl;
        }
    }
	fout << "<" << JC.currentIndex <<">" << endl;
	fout << "<" << JC.players[0].name <<">" << endl;
	fout << "<" << JC.players[1].name <<">" << endl;
    fout.close();
	string tmp;
	tmp=hashing("save.txt");
    fout.open("save.txt", ios::app);
	fout << "<" << tmp <<">";
    fout.close();
}

bool verifying(){
	ifstream fin;
	ofstream fout;
	string line;
	fin.open("xml.load");
	if(!fin.is_open()) {
		return false;
	}
    fin.seekg(-1,ios_base::end);                // go to one spot before the EOF

    bool keepLooping = true;
    while(keepLooping) {
        char ch;
        fin.get(ch);                            // Get current byte's data

        if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
            fin.seekg(0);                       // The first line is the last line
            keepLooping = false;                // So stop there
        }
        else if(ch == '\n') {                   // If the data was a newline
            keepLooping = false;                // Stop at the current position.
        }
        else {                                  // If the data was neither a newline nor at the 0 byte
            fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
        }
    }
	getline(fin,line);
	fin.close();
#ifdef DEBUG
	System::String^ temp = gcnew String(line.c_str());
	MessageBox::Show(temp);
#endif
	fin.open("xml.load");
	fout.open("~xml.tmp");
	fin.seekg(0,ios_base::beg);
	string tmp="<>";
	while(tmp!=line)
	{
		getline(fin, tmp);
		if(tmp!=line) fout<<tmp<<endl;
	}
	fout.close();
	fin.close();
	line.erase(0, 1);
	line.erase(line.end()-1, line.end());
	string theHash = hashing("~xml.tmp");
	remove("~xml.tmp");
#ifdef DEBUG
	System::String^ msg = gcnew String(theHash.c_str());
	MessageBox::Show(msg);
#endif
	if(line!=theHash) return false;
	return true;
}

void load(){//Hung Tsz Yiu :54055993
    ifstream fin;
	string tmp;
	if(!verifying()){
		MessageBox::Show("ERROR, Saved file damaged");
		_FLAG=2;
		return;
	}
    fin.open("xml.load");
    //while(!fin.eof())
    //{
        for (int i=0;i<16;i++)
        {
			getline(fin, tmp);
			tmp.erase(0, 1);
			tmp.erase(tmp.end()-1, tmp.end());
#ifdef DEBUG
			cout<<"alive: "<<tmp<<endl;
#endif
			JC.animals[i].alive = tmp=="1" ? true : false;
			getline(fin, tmp);
			if(tmp=="<>"){
				JC.animals[i].name = "";
			}else{
				tmp.erase(0, 1);
				tmp.erase(tmp.end()-1, tmp.end());
#ifdef DEBUG
			cout<<"name: "<<tmp<<endl;
#endif
				JC.animals[i].name = tmp;
			}
			getline(fin, tmp);
			if(tmp=="<>"){
				JC.animals[i].owner.name = "";
			}else{
				tmp.erase(0, 1);
				tmp.erase(tmp.end()-1, tmp.end());
#ifdef DEBUG
			cout<<"owner: "<<tmp<<endl;
#endif
				JC.animals[i].owner.name = tmp;
			}
			getline(fin, tmp);
			tmp.erase(0, 1);
			tmp.erase(tmp.end()-1, tmp.end());
#ifdef DEBUG
			cout<<"power: "<<tmp<<endl;
#endif
			JC.animals[i].power = stoi(tmp,nullptr,0);
        }
		getline(fin, tmp);
		tmp.erase(0, 1);
		tmp.erase(tmp.end()-1, tmp.end());
        _FLAG = stoi(tmp,nullptr,0);
		getline(fin, tmp);
		tmp.erase(0, 1);
		tmp.erase(tmp.end()-1, tmp.end());
		_SIDE0 = stoi(tmp,nullptr,0);
		getline(fin, tmp);
		tmp.erase(0, 1);
		tmp.erase(tmp.end()-1, tmp.end());
		_SIDE1 = stoi(tmp,nullptr,0);
        for (int i=0;i<BOARD_X;i++)
        {
			for(int j=0;j<BOARD_Y;j++)
            {
				getline(fin, tmp);
				tmp.erase(0, 1);
				tmp.erase(tmp.end()-1, tmp.end());
                JC.board.grids[i][j].id = tmp;
				getline(fin, tmp);
				tmp.erase(0, 1);
				tmp.erase(tmp.end()-1, tmp.end());
                JC.board.grids[i][j].occupant.alive = tmp=="1" ? true : false;
				getline(fin, tmp);
				if(tmp=="<>"){
					JC.board.grids[i][j].occupant.name = "";
				}else{
					tmp.erase(0, 1);
					tmp.erase(tmp.end()-1, tmp.end());
					JC.board.grids[i][j].occupant.name = tmp;
				}
				getline(fin, tmp);
				if(tmp=="<>"){
					JC.board.grids[i][j].occupant.owner.name = "";
				}else{
					tmp.erase(0, 1);
					tmp.erase(tmp.end()-1, tmp.end());
					JC.board.grids[i][j].occupant.owner.name = tmp;
				}
				getline(fin, tmp);
				tmp.erase(0, 1);
				tmp.erase(tmp.end()-1, tmp.end());
                JC.board.grids[i][j].occupant.power = stoi(tmp,nullptr,0);
				getline(fin, tmp);
				if(tmp=="<>"){
					JC.board.grids[i][j].owner.name = "";
				}else{
					tmp.erase(0, 1);
					tmp.erase(tmp.end()-1, tmp.end());
					JC.board.grids[i][j].owner.name = tmp;
				}
            }
        }
		getline(fin, tmp);
		tmp.erase(0, 1);
		tmp.erase(tmp.end()-1, tmp.end());
        JC.currentIndex = stoi(tmp,nullptr,0);
		getline(fin, tmp);
		if(tmp=="<>"){
			JC.players[0].name = "";
		}else{
			tmp.erase(0, 1);
			tmp.erase(tmp.end()-1, tmp.end());
			JC.players[0].name = tmp;
		}
		getline(fin, tmp);
		if(tmp=="<>"){
			JC.players[1].name = "";
		}else{
			tmp.erase(0, 1);
			tmp.erase(tmp.end()-1, tmp.end());
			JC.players[1].name = tmp;
		}
    //}
    fin.close();
}
