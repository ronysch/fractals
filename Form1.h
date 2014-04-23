#pragma once
#include "Complex.h"
#include "triple.h"
#include <ctime>
#include <time.h>

#include "process.h"
namespace fractals {



	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;
	using namespace fractals;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  equationInput;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
 
	public: static double xCoordinate=-2,yCoordinate=2;
	public: static double xStart=0,yStart=0;
	public: static double zoom=100;
	public: static Bitmap^ mBmp = gcnew Bitmap(480,400);
	private: static bool pressed=false;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TrackBar^  trackBar1;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->equationInput = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(67, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &Form1::pictureBox1_MouseHover);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			this->pictureBox1->Move += gcnew System::EventHandler(this, &Form1::pictureBox1_Move);
			// 
			// equationInput
			// 
			this->equationInput->Enabled = this->checkBox1->Checked;
			this->equationInput->Location = System::Drawing::Point(582, 83);
			this->equationInput->Name = L"equationInput";
			this->equationInput->Size = System::Drawing::Size(245, 20);
			this->equationInput->TabIndex = 1;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(833, 85);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(79, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Mandelbrot\r\n";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(579, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"insert equation to draw fractal";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(585, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(602, 213);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(210, 237);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(104, 66);
			this->panel1->TabIndex = 6;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(596, 272);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(976, 532);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->equationInput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseWheel);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				this->equationInput->Enabled=!(this->checkBox1->Checked);
				this->checkBox1->Focus();
			 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			
			 
			 }
		 	//System::Convert::ToString(3);
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		fractals::triple::drawMandel(1);
			
		
		 }
private: System::Void colorDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if(this->pressed){
				this->xCoordinate+=(this->xStart-e->X)/(this->zoom);
				this->yCoordinate+=(this->yStart-e->Y)/(this->zoom);
				this->xStart= e->X;
				this->yStart= e->Y;
			}
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
			this->pressed=false;
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->xStart=e->X;
			this->xStart=e->Y;
			this->pressed=true;	
		 }
private: System::Void pictureBox1_Move(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			
		 }
private: System::Void Form1_MouseWheel( System::Object^ sender , System::Windows::Forms::MouseEventArgs^ e )//control the zoom
      {
		 this->zoom+=e->Delta*0.1;
         this->label2->Text = System::Convert::ToString(this->zoom);;
      }
private: System::Void pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		 }

};
 
}


