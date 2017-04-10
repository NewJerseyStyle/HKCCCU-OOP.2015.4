#ifndef COMMON_H
#define COMMON_H

#pragma comment(lib, "user32.lib")
#include <string>
#include <cmath>
#include <vector>
#include "Header.h"

extern int _SIDE0;
extern int _SIDE1;

using namespace std;
#endif

#ifdef DEBUG

#include <iostream>

#endif

#ifndef HEADER_H
#define HEADER_H

class player//Wong Po Yee : 5407 0357
{
public:
	player(){
		name="";
	}
	player(string theName){
		name=theName;
	}
	~player(){}
	string name;
};

class Animal//Wong Po Yee : 5407 0357
{
public:
	Animal(){}
	Animal(string theName, int thePower){
		name=theName;
		power=thePower;
		alive=true;
		//who is the owner?? set by other function at another time??
	}
	~Animal(){}
	string name;
	bool alive;
	int power;
	player owner;
};

class Landscape//Wong Po Yee : 5407 0357
{
public:
	Landscape(){
		occupant.name="";
		occupant.power=0;
		occupant.alive=false;
		occupant.owner.name="";
		id="I'mLAND";
	}
	Landscape(Animal &moveIn){
		occupant.name=moveIn.name;
		occupant.power=moveIn.power;
		occupant.alive=moveIn.alive;
		occupant.owner.name=moveIn.owner.name;
		id="I'mLAND";
	}
	Landscape(Landscape &copyMe){
		occupant.name=copyMe.occupant.name;
		occupant.power=copyMe.occupant.power;
		occupant.alive=copyMe.occupant.alive;
		occupant.owner.name=copyMe.occupant.owner.name;
		id=copyMe.id;
	}
	~Landscape(){}
	void moveTo(Landscape &dest){//how are we going to use this damn thing?
		dest.occupant.name=occupant.name;
		occupant.name="";
		dest.occupant.power=occupant.power;
		occupant.power=0;
		dest.occupant.alive=occupant.alive;
		occupant.alive=false;
		dest.occupant.owner.name=occupant.owner.name;
		occupant.owner.name="";
	}
	Animal occupant;
	string id;
	player owner;
};

class River:public Landscape//Jasper Lo :5401 8936
{
public:
	River(){
		id="I'mRIVER";
	}
	~River(){}//who knows that this is river or land??
	string id;
};

class Den:public Landscape//Jasper Lo :5401 8936
{
public:
	Den(){
		id="I'mDEN";
	}
	Den(player theOwner){
		owner.name=theOwner.name;
		occupant.owner=theOwner.name;
		id="I'mDEN";
	}
	~Den(){}
	string id;
};

class Trap:public Landscape//Jasper Lo :5401 8936
{
public:
	Trap(){
		id="I'mTRAP";
	}
	~Trap(){}//how do I know this thing is a trap??
	string id;
	
};

#ifndef BOARD_X
#define BOARD_X 7//Jasper Lo :5401 8936
#endif

#ifndef BOARD_Y
#define BOARD_Y 9//Jasper Lo :5401 8936
#endif

class Board//Ku Wai Ming : 54067250
{
public:
	Board(Landscape** theBoard){
		grids=new Landscape*[BOARD_X];
		for(int i=0;i!=BOARD_X;i++)
		{
			grids[i]=new Landscape[BOARD_Y];
		}
		for (int i = 0; i != BOARD_X; ++i)
		{
			for (int j = 0; j != BOARD_Y; ++j)
			{
				theBoard[i][j].moveTo(grids[i][j]);
			}
		}
	}
	Board(){
		grids=new Landscape*[BOARD_X];
		for(int i=0;i!=BOARD_X;i++)
		{
			grids[i]=new Landscape[BOARD_Y];
		}
	}
	~Board(){
		for(int i=0;i!=BOARD_X;i++)
		{
			delete []grids[i];
		}
		delete []grids;
	}
	Landscape getAnimalLocation(Animal theAnimal){
		for(int i=0;i!=BOARD_X;i++){
			for (int j = 0; j !=BOARD_Y; ++j)
			{
				if(grids[i][j].occupant.power==theAnimal.power&&grids[i][j].occupant.alive==true&&grids[i][j].occupant.owner.name==theAnimal.owner.name){
					return grids[i][j];
				}
			}
		}
	}
	void clear(){
		for(int i=0;i!=BOARD_X;i++){
			for (int j = 0; j !=BOARD_Y; ++j)
			{
				grids[i][j].occupant.power=0;
				grids[i][j].occupant.alive=false;
				grids[i][j].occupant.owner.name="";
				grids[i][j].occupant.name="";
			}
		}
	}
	Landscape** grids;
};

class UI//Jasper Lo :5401 8936
{
public:
	UI(){}
	~UI(){}
	void display(Animal[]);
	void display(Board);
};

class Rule//Xu Yuan : 5405 9605
{
public:
	Rule(){}
	~Rule(){}
	player getWinner(const Board &Chessboard){
		if((Chessboard.grids[3][0].occupant.owner.name!=Chessboard.grids[3][0].owner.name&&Chessboard.grids[3][0].occupant.alive)||(_SIDE1==8))
		{
			return Chessboard.grids[3][8].owner;
		}
		if((Chessboard.grids[3][8].occupant.owner.name!=Chessboard.grids[3][8].owner.name&&Chessboard.grids[3][8].occupant.alive)||(_SIDE0==8))
		{
			return Chessboard.grids[3][0].owner;
		}
		return player();
	}
	int CheckMove(int _x, int _y, int &newX, int &newY, const Board &Chessboard)
	{
		if(_x==newX&&_y==newY)
		{
			return 1;//cannot over write the position
		}
		if((newX>=0)&&(newX<BOARD_X)&&(newY>=0)&&(newY<BOARD_Y))
		{
			if(Chessboard.grids[_x][_y].occupant.owner.name==Chessboard.grids[3][0].owner.name)
			{
				if((newX==3)&&(newY==0))
				{
					return 1;//Cannot win the player itself
				}
			}
			else
			{
				if((newX==3)&&(newY==8))
				{
					return 1;//Cannot win the player itself
				}
			}
			if((Chessboard.grids[_x][_y].occupant.power==6)||(Chessboard.grids[_x][_y].occupant.power==7))
			{
				int diffX=newX-_x;
				int diffY=newY-_y;
				while(Chessboard.grids[newX][newY].id=="I'mRIVER"&&Chessboard.grids[newX][newY].occupant.power!=1)
				{
					newX+=diffX;
					newY+=diffY;
				}
				if((Chessboard.grids[newX][newY].occupant.power==1)&&(Chessboard.grids[newX][newY].id=="I'mRIVER"))
				{
					return 1;//the road is blocked
				}
			}
			if(Chessboard.grids[newX][newY].occupant.alive==false)
			{
				if(Chessboard.grids[_x][_y].occupant.power==1)
				{
					return 0;//the road is clear
				}
				if(Chessboard.grids[newX][newY].id=="I'mRIVER")
				{
					return 1;
				}
			}
			if(Chessboard.grids[newX][newY].occupant.power==1)
			{
				if(Chessboard.grids[_x][_y].occupant.power==1)
				{
					return 0;//the road is clear
				}
				else if(Chessboard.grids[_x][_y].occupant.power==8)
				{
					return 1;//elephant cannot capture
				}
				if(Chessboard.grids[newX][newY].id=="I'mRIVER")
				{
					return 1;
				}
			}
			if(Chessboard.grids[newX][newY].occupant.power==8)
			{
				if(Chessboard.grids[_x][_y].occupant.power==1&&Chessboard.grids[_x][_y].id!="I'mRIVER")
				{
					return 0;//capture the elephant
				}
			}
#ifdef DEBUG
				cout<<endl;
				cout<<"from owner: "<<Chessboard.grids[_x][_y].occupant.owner.name<<endl<<"from owner: "<<Chessboard.grids[newX][newY].occupant.owner.name;
#endif
			if((Chessboard.grids[newX][newY].id=="I'mTRAP")&&(Chessboard.grids[newX][newY].occupant.owner.name!=Chessboard.grids[newX][newY].owner.name)&&(Chessboard.grids[_x][_y].occupant.power!=1))
			{
				return 0;
			}
			if(CapturePiece(Chessboard.grids[_x][_y].occupant.power, Chessboard.grids[newX][newY].occupant.power)||(Chessboard.grids[_x][_y].occupant.owner.name==Chessboard.grids[newX][newY].occupant.owner.name))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 3;//out of bound
		}
		return 5;//unknown logical error
	}
	int CapturePiece(int thePowerAgressive, int thePowerPassive){//Jasper Lo :5401 8936
		if(thePowerAgressive==8&&thePowerPassive==1)
		{
			return 1;
		}
		if (thePowerAgressive>=thePowerPassive)
		{
			return 0;//normal, capture
		}
		return 1;//cannot capture
	}
	void searchMove(int _x, int _y, const Board &Chessboard, int leftxy_upxy_rightxy_downxy[8]){
		int newX, newY;
		newX=_x-1;
		newY=_y;
		if(CheckMove(_x, _y, newX, newY, Chessboard)){
			newX=-1;
			newY=-1;
		}
		leftxy_upxy_rightxy_downxy[0]=newX;
		leftxy_upxy_rightxy_downxy[1]=newY;
		newX=_x;
		newY=_y-1;
		if(CheckMove(_x, _y, newX, newY, Chessboard)){
			newX=-1;
			newY=-1;
		}
		leftxy_upxy_rightxy_downxy[2]=newX;
		leftxy_upxy_rightxy_downxy[3]=newY;
		newX=_x+1;
		newY=_y;
		if(CheckMove(_x, _y, newX, newY, Chessboard)){
			newX=-1;
			newY=-1;
		}
		leftxy_upxy_rightxy_downxy[4]=newX;
		leftxy_upxy_rightxy_downxy[5]=newY;
		newX=_x;
		newY=_y+1;
		if(CheckMove(_x, _y, newX, newY, Chessboard)){
			newX=-1;
			newY=-1;
		}
		leftxy_upxy_rightxy_downxy[6]=newX;
		leftxy_upxy_rightxy_downxy[7]=newY;
	}
};
#define DEST_X 3
#define DEST_Y 8

class AI
{
public:
	AI(){
		AI_FLAG=false;
		name="Player2";
		mask=new int*[BOARD_X];
		for(int i=0;i!=BOARD_X;i++)
		{
			mask[i]=new int[BOARD_Y];
		}
		map=new bool*[BOARD_X];
		for(int i=0;i!=BOARD_X;i++)
		{
			map[i]=new bool[BOARD_Y];
		}
		DEFCONlvl=5;
		enermyMouseInRiver=false;
	}
	~AI(){
		for(int i=0;i!=BOARD_X;i++)
		{
			delete[] mask[i];
			delete[] map[i];
		}
		delete[] mask;
		delete[] map;
	}
	void UpdateMaskAndDEFCONlvl(const Board &b){
		lagestAnimal=1;
		for(int i=0;i!=BOARD_X;i++)
		{
			for (int j = 0; j!=BOARD_Y; j++)
			{
				if(b.grids[i][j].occupant.alive)
					if(b.grids[i][j].occupant.owner.name==name)
						mask[i][j]=-b.grids[i][j].occupant.power;
					else
						mask[i][j]=b.grids[i][j].occupant.power;
				else
					mask[i][j]=0;
				if(b.grids[i][j].occupant.power==1&&b.grids[i][j].id=="I'mRIVER"&&b.grids[i][j].occupant.owner.name!=name)
					enermyMouseInRiver=true;
				if(b.grids[i][j].occupant.power>lagestAnimal&&b.grids[i][j].occupant.alive==true)
					lagestAnimal=b.grids[i][j].occupant.power;
			}
		}
		DEFCONlvl = getDEFCONlevel();
	}
	int ifIlost(){
		//if(map[3][0])
			//return;
		return 0;
	}
	void decideMove(int &id, int &x, int &y, int &destX, int &destY, Board &b){
		ifIlost();
		id=0;
		x=-1;
		y=-1;
		if(getDEFCONlevel()==1){
			for(int i=1;i!=3;i++)
			{
				for(int j=0;j!=2;j++)
				{
					if(mask[i][j]>0)
						id=4;
				}
			}
			for(int i=3;i!=6;i++)
			{
				for(int j=0;j!=2;j++)
				{
					if(mask[i][j]>0)
						id=5;
				}
			}
			if(mask[3][2]>0) id=3;
		}
		for(int i=0;i!=6;i++){
			for(int j=0;j!=3;j++){
				if(id==-mask[i][j]){
					x=i;
					y=j;
				}
			}
		}
		if(id==0) id=lagestAnimal;
		if(x==-1&&y==-1){
			for(int i=0;i<BOARD_X;i++){
				for(int j=0;j<BOARD_Y;j++){
					if(b.grids[i][j].occupant.power==id&&b.grids[i][j].occupant.owner.name==name){//something went wrong to the owner
						x=i;
						y=j;
						i=BOARD_X;
						j=BOARD_Y;
					}
				}
			}
		}
		destX=DEST_X;
		destY=DEST_Y;
		if(id==1) routeCal(x, y, destX, destY, true); else routeCal(x, y, destX, destY, false);
		int dX, dY;
		if(x+1<BOARD_X&&map[x+1][y]==true) {
			dX=abs(x+1-destX);
			dY=abs(y-destY);
		}
		if(x-1>=0&&map[x-1][y]==true) {
			if(dX>abs(x-1-destX)||dY>abs(y-destY))
			{
				dX=abs(x-1-destX);
				dY=abs(y-destY);
			}
		}
		if(y+1<BOARD_Y&&map[x][y+1]==true) {
			if(dX>abs(x-destX)||dY>abs(y+1-destY))
			{
				dX=abs(x-destX);
				dY=abs(y+1-destY);
			}
		}
		if(y-1<BOARD_Y&&map[x][y-1]==true) {
			if(dX>abs(x-destX)||dY>abs(y-1-destY))
			{
				dX=abs(x-destX);
				dY=abs(y-1-destY);
			}
		}
	}

	/* data */
protected:
	int** mask;
	string name;
	bool enermyMouseInRiver;

private:
	int lagestAnimal;
	int DEFCONlvl;
	bool** map;
	int getDEFCONlevel(){
		for(int i=1;i!=5;i++)
		{
			for(int j=0;j!=2;j++)
			{
				if(mask[i][j]>0)
					return 1;
			}
		}
		if(mask[3][2]>0) return 1;
		for(int i=0;i!=2;i++)
		{
			if(mask[0][i]>0) return 2;
			if(mask[6][i]>0) return 2;
		}
		for(int i=0;i!=6;i++)
		{
			if(mask[i][2]>0) return 2;
		}
		if(mask[3][3]>0) return 2;
		for(int i=0;i!=6;i++)
		{
			if(mask[i][3]>0) return 3;
		}
		if(mask[3][4]>0) return 3;
		for(int i=0;i!=6;i++)
		{
			if(mask[i][4]>0) return 4;
		}
		if(mask[3][5]>0) return 4;
	}
	int routeDistance(int srcX, int srcY, int destX, int destY){
		int distance=0;
		for(int i=srcX;i!=destX;){
			for(int j=srcY;j!=destY;){
				int x,y;
				x=i;
				y=j;
				//improvement
			}
		}
	}
	bool routeCal(int srcX, int srcY, int destX, int destY, bool mouseMove){
		for(int i=0;i!=BOARD_X;i++){
			for(int j=0;j!=BOARD_Y;j++){
				map[i][j]=mask[i][j]==0?true:false;
			}
		}
		map[1][3]=mouseMove;
		map[1][4]=mouseMove;
		map[1][5]=mouseMove;
		map[2][3]=mouseMove;
		map[2][4]=mouseMove;
		map[2][5]=mouseMove;
		map[4][3]=mouseMove;
		map[4][4]=mouseMove;
		map[4][5]=mouseMove;
		map[5][3]=mouseMove;
		map[5][4]=mouseMove;
		map[5][5]=mouseMove;
		for(int k=0;k!=6;k++){
			for(int i=0;i!=BOARD_X;i++){
				for(int j=0;j!=BOARD_Y;j++){
					if(map[i][j]){
						int DeadrouteCount=0;
						if(i<1||map[i-1][j]) ++DeadrouteCount;
						if(i>(BOARD_X-2)||map[i+1][j]) ++DeadrouteCount;
						if(j<1||map[i][j-1]) ++DeadrouteCount;
						if(j>(BOARD_Y)||map[i][j+1]) +DeadrouteCount;
						if(DeadrouteCount>2){
							if(i!=destX||j!=destY){
								if(i!=srcX||j!=srcY){
										map[i][j]=false;
								}
							}
						}
					}
				}
			}
		}
		if(!map[srcX][srcY]) return false;
		if(!map[destX][destY]) return false;
		return true;
	}
	bool goodRouteExist(){
		//improvement
	}
	bool** decideRoute(){
		//improvement
	}
	public:
		bool AI_FLAG;
};

class Game//Xu Yuan : 5405 9605
{
public:
	Game(){ //create board,animals,players
		//inputplayers
		initializing();
	}
	~Game(){
		vector<player>().swap(players);
		vector<Animal>().swap(animals);
	}
	void initializing(){
		currentIndex=0;
		{
			player tmp;
			tmp.name="Player1";
			players.push_back(tmp);
			tmp.name="Player2";
			players.push_back(tmp);
		}
		{
			Animal tmp;
			tmp.alive=true;
			tmp.power=1;
			tmp.name.assign("Rat");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=2;
			tmp.name.assign("Cat");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=3;
			tmp.name.assign("Wolf");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=4;
			tmp.name.assign("Dog");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=5;
			tmp.name.assign("Leopard");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=6;
			tmp.name.assign("Tiger");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=7;
			tmp.name.assign("Lion");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
			tmp.power=8;
			tmp.name.assign("Elephant");
			for(vector<player>::iterator iterP = players.begin(); iterP != players.end(); ++iterP)
			{
				tmp.owner.name=iterP->name;
				animals.push_back(tmp);
			}
		}
		{
			Den d;
			Trap t;
			River r;
			{
				vector<player>::iterator iter = players.begin();
				//den
				board.grids[3][8].id.assign(d.id);
				board.grids[3][8].occupant.owner.name.assign(iter->name);
				board.grids[3][8].owner.name.assign(iter++->name);
				board.grids[3][0].id.assign(d.id);
				board.grids[3][0].occupant.owner.name.assign(iter->name);
				board.grids[3][0].owner.name.assign(iter--->name);
			}
			//trap
			board.grids[2][0].id.assign(t.id);
			board.grids[2][0].owner.name=players[1].name;
			board.grids[4][0].id.assign(t.id);
			board.grids[4][0].owner.name=players[1].name;
			board.grids[3][1].id.assign(t.id);
			board.grids[3][1].owner.name=players[1].name;
			board.grids[2][8].id.assign(t.id);
			board.grids[2][8].owner.name=players[0].name;
			board.grids[4][8].id.assign(t.id);
			board.grids[4][8].owner.name=players[0].name;
			board.grids[3][7].id.assign(t.id);
			board.grids[3][7].owner.name=players[0].name;
			//river
			board.grids[1][3].id.assign(r.id);
			board.grids[1][4].id.assign(r.id);
			board.grids[1][5].id.assign(r.id);
			board.grids[2][3].id.assign(r.id);
			board.grids[2][4].id.assign(r.id);
			board.grids[2][5].id.assign(r.id);
			board.grids[4][3].id.assign(r.id);
			board.grids[4][4].id.assign(r.id);
			board.grids[4][5].id.assign(r.id);
			board.grids[5][3].id.assign(r.id);
			board.grids[5][4].id.assign(r.id);
			board.grids[5][5].id.assign(r.id);
			//animals
			vector<Animal>::iterator iter = animals.begin();
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[6][6]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[0][2]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[1][7]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[5][1]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[2][6]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[4][2]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[5][7]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[1][1]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[4][6]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[2][2]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[0][8]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[6][0]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[6][8]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[0][0]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[0][6]);
				++iter;
			}
			{
				Animal tmpA(iter->name, iter->power);
				tmpA.owner.name=iter->owner.name;
				Landscape tmpL(tmpA);
				tmpL.moveTo(board.grids[6][2]);
				++iter;
			}
		}
#ifdef DEBUG
		cout<<endl;
		cout<<"Alive \t Name \t Owner \t Power\n";
		for(vector<Animal>::iterator iter = animals.begin(); iter != animals.end(); ++iter){
			cout<<iter->alive<<"\t"<<iter->name<<"\t"<<iter->owner.name<<"\t"<<iter->power<<endl;
		}
#endif

#ifdef DEBUG
		cout<<endl;
		cout<<"\tx\ty\tName\tOwner\tID\n";
		for(int i=0;i<BOARD_X;i++)
		{
			for(int j=0;j<BOARD_Y;j++)
			{
				//if(board.grids[i][j].occupant.alive)
					cout<<"\t"<<i<<"\t"<<j<<"\t"<<board.grids[i][j].occupant.name<<"\t"<<board.grids[i][j].occupant.owner.name<<"\t"<<board.grids[i][j].id<<endl;
			}
		}
#endif
	}
	Board board;
	vector<player> players;
	vector<Animal> animals;
	int currentIndex;
	Rule rule;
	AI ai;
};
#endif