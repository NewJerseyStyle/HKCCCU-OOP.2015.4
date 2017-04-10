#pragma once

#include <windows.h>

#define MoveHorizontal 80
#define MoveVertical 64

namespace Jungle_Chess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Jungle_Chess
	/// </summary>
	public ref class Jungle_Chess : public System::Windows::Forms::Form
	{
	public:
		Jungle_Chess(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Jungle_Chess()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  board;
	private: System::Windows::Forms::PictureBox^  Lion_R;
	protected: 


















	private: System::Windows::Forms::PictureBox^  Tiger_R;
	private: System::Windows::Forms::PictureBox^  Dog_R;
	private: System::Windows::Forms::PictureBox^  Leopard_R;





	private: System::Windows::Forms::PictureBox^  Elephant_R;

	private: System::Windows::Forms::PictureBox^  Rat_B;

	private: System::Windows::Forms::PictureBox^  Rat_R;
	private: System::Windows::Forms::PictureBox^  Wolf_R;


	private: System::Windows::Forms::PictureBox^  Lion_B;
	private: System::Windows::Forms::PictureBox^  Tiger_B;
	private: System::Windows::Forms::PictureBox^  Dog_B;



	private: System::Windows::Forms::PictureBox^  Cat_B;

	private: System::Windows::Forms::PictureBox^  Elephant_B;
	private: System::Windows::Forms::PictureBox^  Leopard_B;
	private: System::Windows::Forms::PictureBox^  Wolf_B;



	private: System::Windows::Forms::PictureBox^  Cat_R;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  Save;
	private: System::Windows::Forms::Button^  Quit;
	private: System::Windows::Forms::Button^  Tutorial;
	private: System::Windows::Forms::ToolTip^  MouseOnTip;
	private: System::Windows::Forms::PictureBox^  down;
	private: System::Windows::Forms::PictureBox^  right;
	private: System::Windows::Forms::PictureBox^  up;
	private: System::Windows::Forms::PictureBox^  left;
	private: System::Windows::Forms::PictureBox^  Cover;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  CONTINUE;

	private: System::Windows::Forms::PictureBox^  VICTORY;
	private: System::Windows::Forms::PictureBox^  GreenDot;




	private: System::ComponentModel::IContainer^  components;








































































	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Jungle_Chess::typeid));
			this->board = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Tutorial = (gcnew System::Windows::Forms::Button());
			this->Quit = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->CONTINUE = (gcnew System::Windows::Forms::Button());
			this->VICTORY = (gcnew System::Windows::Forms::PictureBox());
			this->down = (gcnew System::Windows::Forms::PictureBox());
			this->right = (gcnew System::Windows::Forms::PictureBox());
			this->up = (gcnew System::Windows::Forms::PictureBox());
			this->left = (gcnew System::Windows::Forms::PictureBox());
			this->Cover = (gcnew System::Windows::Forms::PictureBox());
			this->Lion_R = (gcnew System::Windows::Forms::PictureBox());
			this->Lion_B = (gcnew System::Windows::Forms::PictureBox());
			this->Tiger_R = (gcnew System::Windows::Forms::PictureBox());
			this->Tiger_B = (gcnew System::Windows::Forms::PictureBox());
			this->Dog_R = (gcnew System::Windows::Forms::PictureBox());
			this->Dog_B = (gcnew System::Windows::Forms::PictureBox());
			this->Cat_R = (gcnew System::Windows::Forms::PictureBox());
			this->Cat_B = (gcnew System::Windows::Forms::PictureBox());
			this->Elephant_R = (gcnew System::Windows::Forms::PictureBox());
			this->Elephant_B = (gcnew System::Windows::Forms::PictureBox());
			this->Leopard_R = (gcnew System::Windows::Forms::PictureBox());
			this->Leopard_B = (gcnew System::Windows::Forms::PictureBox());
			this->Wolf_R = (gcnew System::Windows::Forms::PictureBox());
			this->Wolf_B = (gcnew System::Windows::Forms::PictureBox());
			this->Rat_R = (gcnew System::Windows::Forms::PictureBox());
			this->Rat_B = (gcnew System::Windows::Forms::PictureBox());
			this->MouseOnTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GreenDot = (gcnew System::Windows::Forms::PictureBox());
			this->board->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VICTORY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->down))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->right))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->up))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->left))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lion_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lion_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Tiger_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Tiger_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Dog_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Dog_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cat_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cat_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Elephant_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Elephant_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Leopard_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Leopard_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Wolf_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Wolf_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Rat_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Rat_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenDot))->BeginInit();
			this->SuspendLayout();
			// 
			// board
			// 
			this->board->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"board.BackgroundImage")));
			this->board->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->board->Controls->Add(this->GreenDot);
			this->board->Controls->Add(this->button1);
			this->board->Controls->Add(this->Tutorial);
			this->board->Controls->Add(this->Quit);
			this->board->Controls->Add(this->Save);
			this->board->Controls->Add(this->panel1);
			this->board->Dock = System::Windows::Forms::DockStyle::Fill;
			this->board->Location = System::Drawing::Point(0, 0);
			this->board->Name = L"board";
			this->board->Size = System::Drawing::Size(937, 680);
			this->board->TabIndex = 0;
			this->board->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Jungle_Chess::board_Paint);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(759, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 53);
			this->button1->TabIndex = 26;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Jungle_Chess::button1_Click);
			// 
			// Tutorial
			// 
			this->Tutorial->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Tutorial->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Tutorial.Image")));
			this->Tutorial->Location = System::Drawing::Point(759, 507);
			this->Tutorial->Name = L"Tutorial";
			this->Tutorial->Size = System::Drawing::Size(144, 56);
			this->Tutorial->TabIndex = 25;
			this->Tutorial->UseVisualStyleBackColor = true;
			this->Tutorial->Click += gcnew System::EventHandler(this, &Jungle_Chess::Tutorial_Click);
			// 
			// Quit
			// 
			this->Quit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Quit->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Quit.Image")));
			this->Quit->Location = System::Drawing::Point(759, 254);
			this->Quit->Name = L"Quit";
			this->Quit->Size = System::Drawing::Size(144, 56);
			this->Quit->TabIndex = 24;
			this->Quit->UseVisualStyleBackColor = true;
			this->Quit->Click += gcnew System::EventHandler(this, &Jungle_Chess::Quit_Click);
			// 
			// Save
			// 
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Save.Image")));
			this->Save->Location = System::Drawing::Point(759, 95);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(144, 56);
			this->Save->TabIndex = 23;
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &Jungle_Chess::Save_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->Controls->Add(this->CONTINUE);
			this->panel1->Controls->Add(this->VICTORY);
			this->panel1->Controls->Add(this->down);
			this->panel1->Controls->Add(this->right);
			this->panel1->Controls->Add(this->up);
			this->panel1->Controls->Add(this->left);
			this->panel1->Controls->Add(this->Cover);
			this->panel1->Controls->Add(this->Lion_R);
			this->panel1->Controls->Add(this->Lion_B);
			this->panel1->Controls->Add(this->Tiger_R);
			this->panel1->Controls->Add(this->Tiger_B);
			this->panel1->Controls->Add(this->Dog_R);
			this->panel1->Controls->Add(this->Dog_B);
			this->panel1->Controls->Add(this->Cat_R);
			this->panel1->Controls->Add(this->Cat_B);
			this->panel1->Controls->Add(this->Elephant_R);
			this->panel1->Controls->Add(this->Elephant_B);
			this->panel1->Controls->Add(this->Leopard_R);
			this->panel1->Controls->Add(this->Leopard_B);
			this->panel1->Controls->Add(this->Wolf_R);
			this->panel1->Controls->Add(this->Wolf_B);
			this->panel1->Controls->Add(this->Rat_R);
			this->panel1->Controls->Add(this->Rat_B);
			this->panel1->Location = System::Drawing::Point(159, 70);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(565, 584);
			this->panel1->TabIndex = 22;
			// 
			// CONTINUE
			// 
			this->CONTINUE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CONTINUE.BackgroundImage")));
			this->CONTINUE->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CONTINUE->Location = System::Drawing::Point(236, 390);
			this->CONTINUE->Name = L"CONTINUE";
			this->CONTINUE->Size = System::Drawing::Size(93, 24);
			this->CONTINUE->TabIndex = 28;
			this->CONTINUE->UseVisualStyleBackColor = true;
			this->CONTINUE->Visible = false;
			this->CONTINUE->Click += gcnew System::EventHandler(this, &Jungle_Chess::CONTINUE_Click);
			// 
			// VICTORY
			// 
			this->VICTORY->BackColor = System::Drawing::Color::Transparent;
			this->VICTORY->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->VICTORY->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VICTORY->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"VICTORY.Image")));
			this->VICTORY->Location = System::Drawing::Point(0, 0);
			this->VICTORY->Name = L"VICTORY";
			this->VICTORY->Size = System::Drawing::Size(565, 584);
			this->VICTORY->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->VICTORY->TabIndex = 27;
			this->VICTORY->TabStop = false;
			this->VICTORY->Visible = false;
			// 
			// down
			// 
			this->down->BackColor = System::Drawing::Color::Transparent;
			this->down->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"down.Image")));
			this->down->Location = System::Drawing::Point(248, 326);
			this->down->Name = L"down";
			this->down->Size = System::Drawing::Size(69, 55);
			this->down->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->down->TabIndex = 26;
			this->down->TabStop = false;
			this->down->Visible = false;
			this->down->Click += gcnew System::EventHandler(this, &Jungle_Chess::down_Click);
			// 
			// right
			// 
			this->right->BackColor = System::Drawing::Color::Transparent;
			this->right->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"right.Image")));
			this->right->Location = System::Drawing::Point(327, 265);
			this->right->Name = L"right";
			this->right->Size = System::Drawing::Size(69, 55);
			this->right->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->right->TabIndex = 25;
			this->right->TabStop = false;
			this->right->Visible = false;
			this->right->Click += gcnew System::EventHandler(this, &Jungle_Chess::right_Click);
			// 
			// up
			// 
			this->up->BackColor = System::Drawing::Color::Transparent;
			this->up->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"up.Image")));
			this->up->Location = System::Drawing::Point(248, 204);
			this->up->Name = L"up";
			this->up->Size = System::Drawing::Size(69, 55);
			this->up->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->up->TabIndex = 24;
			this->up->TabStop = false;
			this->up->Visible = false;
			this->up->Click += gcnew System::EventHandler(this, &Jungle_Chess::up_Click);
			// 
			// left
			// 
			this->left->BackColor = System::Drawing::Color::Transparent;
			this->left->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"left.Image")));
			this->left->Location = System::Drawing::Point(167, 265);
			this->left->Name = L"left";
			this->left->Size = System::Drawing::Size(69, 55);
			this->left->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->left->TabIndex = 23;
			this->left->TabStop = false;
			this->left->Visible = false;
			this->left->Click += gcnew System::EventHandler(this, &Jungle_Chess::left_Click);
			// 
			// Cover
			// 
			this->Cover->BackColor = System::Drawing::Color::Transparent;
			this->Cover->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Cover.Image")));
			this->Cover->Location = System::Drawing::Point(248, 265);
			this->Cover->Name = L"Cover";
			this->Cover->Size = System::Drawing::Size(69, 55);
			this->Cover->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Cover->TabIndex = 22;
			this->Cover->TabStop = false;
			this->Cover->Visible = false;
			this->Cover->Click += gcnew System::EventHandler(this, &Jungle_Chess::Cover_Click);
			// 
			// Lion_R
			// 
			this->Lion_R->BackColor = System::Drawing::Color::Transparent;
			this->Lion_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Lion_R.Image")));
			this->Lion_R->Location = System::Drawing::Point(7, 10);
			this->Lion_R->Name = L"Lion_R";
			this->Lion_R->Size = System::Drawing::Size(69, 55);
			this->Lion_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Lion_R->TabIndex = 4;
			this->Lion_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Lion_R, L"Lion");
			this->Lion_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Lion_R_Click);
			// 
			// Lion_B
			// 
			this->Lion_B->BackColor = System::Drawing::Color::Transparent;
			this->Lion_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Lion_B.Image")));
			this->Lion_B->Location = System::Drawing::Point(487, 522);
			this->Lion_B->Name = L"Lion_B";
			this->Lion_B->Size = System::Drawing::Size(69, 55);
			this->Lion_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Lion_B->TabIndex = 21;
			this->Lion_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Lion_B, L"Lion");
			this->Lion_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Lion_B_Click);
			// 
			// Tiger_R
			// 
			this->Tiger_R->BackColor = System::Drawing::Color::Transparent;
			this->Tiger_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Tiger_R.Image")));
			this->Tiger_R->Location = System::Drawing::Point(487, 10);
			this->Tiger_R->Name = L"Tiger_R";
			this->Tiger_R->Size = System::Drawing::Size(69, 55);
			this->Tiger_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Tiger_R->TabIndex = 7;
			this->Tiger_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Tiger_R, L"Tiger");
			this->Tiger_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Tiger_R_Click);
			// 
			// Tiger_B
			// 
			this->Tiger_B->BackColor = System::Drawing::Color::Transparent;
			this->Tiger_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Tiger_B.Image")));
			this->Tiger_B->Location = System::Drawing::Point(7, 522);
			this->Tiger_B->Name = L"Tiger_B";
			this->Tiger_B->Size = System::Drawing::Size(69, 55);
			this->Tiger_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Tiger_B->TabIndex = 20;
			this->Tiger_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Tiger_B, L"Tiger");
			this->Tiger_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Tiger_B_Click);
			// 
			// Dog_R
			// 
			this->Dog_R->BackColor = System::Drawing::Color::Transparent;
			this->Dog_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Dog_R.Image")));
			this->Dog_R->Location = System::Drawing::Point(87, 74);
			this->Dog_R->Name = L"Dog_R";
			this->Dog_R->Size = System::Drawing::Size(69, 55);
			this->Dog_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Dog_R->TabIndex = 8;
			this->Dog_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Dog_R, L"Dog");
			this->Dog_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Dog_R_Click);
			// 
			// Dog_B
			// 
			this->Dog_B->BackColor = System::Drawing::Color::Transparent;
			this->Dog_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Dog_B.Image")));
			this->Dog_B->Location = System::Drawing::Point(407, 458);
			this->Dog_B->Name = L"Dog_B";
			this->Dog_B->Size = System::Drawing::Size(69, 55);
			this->Dog_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Dog_B->TabIndex = 19;
			this->Dog_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Dog_B, L"Dog");
			this->Dog_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Dog_B_Click);
			// 
			// Cat_R
			// 
			this->Cat_R->BackColor = System::Drawing::Color::Transparent;
			this->Cat_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Cat_R.Image")));
			this->Cat_R->Location = System::Drawing::Point(407, 74);
			this->Cat_R->Name = L"Cat_R";
			this->Cat_R->Size = System::Drawing::Size(69, 55);
			this->Cat_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Cat_R->TabIndex = 9;
			this->Cat_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Cat_R, L"Cat");
			this->Cat_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Cat_R_Click);
			// 
			// Cat_B
			// 
			this->Cat_B->BackColor = System::Drawing::Color::Transparent;
			this->Cat_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Cat_B.Image")));
			this->Cat_B->Location = System::Drawing::Point(87, 458);
			this->Cat_B->Name = L"Cat_B";
			this->Cat_B->Size = System::Drawing::Size(69, 55);
			this->Cat_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Cat_B->TabIndex = 18;
			this->Cat_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Cat_B, L"Cat");
			this->Cat_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Cat_B_Click);
			// 
			// Elephant_R
			// 
			this->Elephant_R->BackColor = System::Drawing::Color::Transparent;
			this->Elephant_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Elephant_R.Image")));
			this->Elephant_R->Location = System::Drawing::Point(487, 138);
			this->Elephant_R->Name = L"Elephant_R";
			this->Elephant_R->Size = System::Drawing::Size(69, 55);
			this->Elephant_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Elephant_R->TabIndex = 10;
			this->Elephant_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Elephant_R, L"Elephant");
			this->Elephant_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Elephant_R_Click);
			// 
			// Elephant_B
			// 
			this->Elephant_B->BackColor = System::Drawing::Color::Transparent;
			this->Elephant_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Elephant_B.Image")));
			this->Elephant_B->Location = System::Drawing::Point(7, 394);
			this->Elephant_B->Name = L"Elephant_B";
			this->Elephant_B->Size = System::Drawing::Size(69, 55);
			this->Elephant_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Elephant_B->TabIndex = 17;
			this->Elephant_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Elephant_B, L"Elephant");
			this->Elephant_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Elephant_B_Click);
			// 
			// Leopard_R
			// 
			this->Leopard_R->BackColor = System::Drawing::Color::Transparent;
			this->Leopard_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Leopard_R.Image")));
			this->Leopard_R->Location = System::Drawing::Point(167, 138);
			this->Leopard_R->Name = L"Leopard_R";
			this->Leopard_R->Size = System::Drawing::Size(69, 55);
			this->Leopard_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Leopard_R->TabIndex = 11;
			this->Leopard_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Leopard_R, L"Leopard");
			this->Leopard_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Leopard_R_Click);
			// 
			// Leopard_B
			// 
			this->Leopard_B->BackColor = System::Drawing::Color::Transparent;
			this->Leopard_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Leopard_B.Image")));
			this->Leopard_B->Location = System::Drawing::Point(327, 394);
			this->Leopard_B->Name = L"Leopard_B";
			this->Leopard_B->Size = System::Drawing::Size(69, 55);
			this->Leopard_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Leopard_B->TabIndex = 16;
			this->Leopard_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Leopard_B, L"Leopard");
			this->Leopard_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Leopard_B_Click);
			// 
			// Wolf_R
			// 
			this->Wolf_R->BackColor = System::Drawing::Color::Transparent;
			this->Wolf_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Wolf_R.Image")));
			this->Wolf_R->Location = System::Drawing::Point(327, 138);
			this->Wolf_R->Name = L"Wolf_R";
			this->Wolf_R->Size = System::Drawing::Size(69, 55);
			this->Wolf_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Wolf_R->TabIndex = 12;
			this->Wolf_R->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Wolf_R, L"Wolf");
			this->Wolf_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Wolf_R_Click);
			// 
			// Wolf_B
			// 
			this->Wolf_B->BackColor = System::Drawing::Color::Transparent;
			this->Wolf_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Wolf_B.Image")));
			this->Wolf_B->Location = System::Drawing::Point(167, 394);
			this->Wolf_B->Name = L"Wolf_B";
			this->Wolf_B->Size = System::Drawing::Size(69, 55);
			this->Wolf_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Wolf_B->TabIndex = 15;
			this->Wolf_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Wolf_B, L"Wolf");
			this->Wolf_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Wolf_B_Click);
			// 
			// Rat_R
			// 
			this->Rat_R->AccessibleDescription = L"";
			this->Rat_R->BackColor = System::Drawing::Color::Transparent;
			this->Rat_R->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Rat_R.Image")));
			this->Rat_R->Location = System::Drawing::Point(7, 138);
			this->Rat_R->Name = L"Rat_R";
			this->Rat_R->Size = System::Drawing::Size(69, 55);
			this->Rat_R->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Rat_R->TabIndex = 13;
			this->Rat_R->TabStop = false;
			this->Rat_R->Tag = L"";
			this->MouseOnTip->SetToolTip(this->Rat_R, L"Rat");
			this->Rat_R->Click += gcnew System::EventHandler(this, &Jungle_Chess::Rat_R_Click);
			// 
			// Rat_B
			// 
			this->Rat_B->BackColor = System::Drawing::Color::Transparent;
			this->Rat_B->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Rat_B.Image")));
			this->Rat_B->Location = System::Drawing::Point(487, 394);
			this->Rat_B->Name = L"Rat_B";
			this->Rat_B->Size = System::Drawing::Size(69, 55);
			this->Rat_B->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Rat_B->TabIndex = 14;
			this->Rat_B->TabStop = false;
			this->MouseOnTip->SetToolTip(this->Rat_B, L"Rat");
			this->Rat_B->Click += gcnew System::EventHandler(this, &Jungle_Chess::Rat_B_Click);
			// 
			// GreenDot
			// 
			this->GreenDot->BackColor = System::Drawing::Color::Transparent;
			this->GreenDot->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"GreenDot.Image")));
			this->GreenDot->Location = System::Drawing::Point(111, 376);
			this->GreenDot->Name = L"GreenDot";
			this->GreenDot->Size = System::Drawing::Size(30, 25);
			this->GreenDot->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->GreenDot->TabIndex = 1;
			this->GreenDot->TabStop = false;
			// 
			// Jungle_Chess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 680);
			this->Controls->Add(this->board);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(953, 718);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(953, 718);
			this->Name = L"Jungle_Chess";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Jungle_Chess";
			this->Load += gcnew System::EventHandler(this, &Jungle_Chess::Jungle_Chess_Load);
			this->board->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VICTORY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->down))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->right))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->up))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->left))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lion_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lion_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Tiger_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Tiger_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Dog_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Dog_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cat_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Cat_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Elephant_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Elephant_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Leopard_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Leopard_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Wolf_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Wolf_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Rat_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Rat_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenDot))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Jungle_Chess_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
public: System::Void display();//Xu Yuan : 5405 9605
public: System::Void searchAVmove(int x, int y);
private: System::Void Save_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Quit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Tutorial_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Rat_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenRatBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Rat_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Rat_B->Location.X, this->Rat_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Cover_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->Cover->Visible==true)
			 {
				 this->Cover->Visible=false;
				 this->left->Visible=false;
				 this->up->Visible=false;
				 this->right->Visible=false;
				 this->down->Visible=false;
			 }
		 }
private: System::Void Leopard_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenLeopandblue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Leopard_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Leopard_B->Location.X, this->Leopard_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Wolf_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenWolfBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Wolf_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Wolf_B->Location.X, this->Wolf_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Elephant_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenElephantBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Elephant_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Elephant_B->Location.X, this->Elephant_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Dog_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenDogBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Dog_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Dog_B->Location.X, this->Dog_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Cat_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenCatBlue.fw.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Cat_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Cat_B->Location.X, this->Cat_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Lion_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenLionBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Lion_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Lion_B->Location.X, this->Lion_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Tiger_B_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='R') return;
			 System::String^ url("./Pic/ChosenTigerBlue.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Tiger_B->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Tiger_B->Location.X, this->Tiger_B->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Lion_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenLionRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Lion_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Lion_R->Location.X, this->Lion_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Tiger_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenTigerRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Tiger_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Tiger_R->Location.X, this->Tiger_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Dog_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenDogRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Dog_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Dog_R->Location.X, this->Dog_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Cat_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenCatRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Cat_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Cat_R->Location.X, this->Cat_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Rat_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenRatRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Rat_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Rat_R->Location.X, this->Rat_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Leopard_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenLeopardRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Leopard_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Leopard_R->Location.X, this->Leopard_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Wolf_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenWolfRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Wolf_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Wolf_R->Location.X, this->Wolf_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void Elephant_R_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(_TURN=='B') return;
			 System::String^ url("./Pic/ChosenElephantRed.png");
			 this->Cover->Load(url);
			 if(this->Cover->Parent != this->Elephant_R->Parent) return;
			 this->Cover->Location = System::Drawing::Point(this->Elephant_R->Location.X, this->Elephant_R->Location.Y);
			 this->Cover->Visible=true;
			 searchAVmove(this->Cover->Location.X, this->Cover->Location.Y);
		 }
private: System::Void left_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void up_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void right_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void down_Click(System::Object^  sender, System::EventArgs^  e);
public: System::Void ShowMove(int x, int y, int newX, int newY);
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 _FLAG=1;//1 for restart
			 this->~Jungle_Chess();
		 }
private: System::Void board_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void CONTINUE_Click(System::Object^  sender, System::EventArgs^  e) {
			 _FLAG=2;
			 this->~Jungle_Chess();
		 }
public: System::Void LoadDisplay();
};
}
