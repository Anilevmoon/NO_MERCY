﻿#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include"Header.h"
#include <thread>   



namespace KURVA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Button^ DOWNLOADB;


	private: System::Windows::Forms::ProgressBar^ progressBar1;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ PLAY;

	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::WebBrowser^ webBrowser1;
	private: System::Windows::Forms::WebBrowser^ webBrowser2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ WAITING;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->DOWNLOADB = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->PLAY = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->WAITING = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// DOWNLOADB
			// 
			this->DOWNLOADB->BackColor = System::Drawing::Color::RoyalBlue;
			this->DOWNLOADB->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->DOWNLOADB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DOWNLOADB->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->DOWNLOADB->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DOWNLOADB->Location = System::Drawing::Point(857, 463);
			this->DOWNLOADB->Margin = System::Windows::Forms::Padding(2);
			this->DOWNLOADB->Name = L"DOWNLOADB";
			this->DOWNLOADB->Size = System::Drawing::Size(134, 37);
			this->DOWNLOADB->TabIndex = 3;
			this->DOWNLOADB->Text = L"UPDATE⟳";
			this->DOWNLOADB->UseVisualStyleBackColor = false;
			this->DOWNLOADB->Click += gcnew System::EventHandler(this, &MyForm::DOWNLOADB_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->progressBar1->Location = System::Drawing::Point(341, 503);
			this->progressBar1->Margin = System::Windows::Forms::Padding(0);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(650, 37);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 4;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// PLAY
			// 
			this->PLAY->BackColor = System::Drawing::Color::Yellow;
			this->PLAY->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->PLAY->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PLAY->Location = System::Drawing::Point(857, 464);
			this->PLAY->Margin = System::Windows::Forms::Padding(2);
			this->PLAY->Name = L"PLAY";
			this->PLAY->Size = System::Drawing::Size(134, 37);
			this->PLAY->TabIndex = 5;
			this->PLAY->Text = L"PLAY❯❯❯";
			this->PLAY->UseVisualStyleBackColor = false;
			this->PLAY->Visible = false;
			this->PLAY->Click += gcnew System::EventHandler(this, &MyForm::PLAY_Click);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(341, 483);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(514, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->ImageLocation = L"C:\\Users\\glebl\\Desktop\\no mercy.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 480);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(326, 57);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// webBrowser1
			// 
			this->webBrowser1->IsWebBrowserContextMenuEnabled = false;
			this->webBrowser1->Location = System::Drawing::Point(665, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->ScrollBarsEnabled = false;
			this->webBrowser1->Size = System::Drawing::Size(336, 320);
			this->webBrowser1->TabIndex = 10;
			this->webBrowser1->Tag = L"";
			this->webBrowser1->Url = (gcnew System::Uri(L"http://randomcolour.com/", System::UriKind::Absolute));
			this->webBrowser1->DocumentCompleted += gcnew System::Windows::Forms::WebBrowserDocumentCompletedEventHandler(this, &MyForm::webBrowser1_DocumentCompleted);
			// 
			// webBrowser2
			// 
			this->webBrowser2->IsWebBrowserContextMenuEnabled = false;
			this->webBrowser2->Location = System::Drawing::Point(2, 0);
			this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->ScrollBarsEnabled = false;
			this->webBrowser2->Size = System::Drawing::Size(336, 320);
			this->webBrowser2->TabIndex = 11;
			this->webBrowser2->Tag = L"";
			this->webBrowser2->Url = (gcnew System::Uri(L"http://randomcolour.com/", System::UriKind::Absolute));
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->ImageLocation = L"C:\\Users\\glebl\\Desktop\\Soldier.png";
			this->pictureBox2->Location = System::Drawing::Point(344, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(303, 565);
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// WAITING
			// 
			this->WAITING->BackColor = System::Drawing::Color::SpringGreen;
			this->WAITING->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->WAITING->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->WAITING->Location = System::Drawing::Point(857, 463);
			this->WAITING->Margin = System::Windows::Forms::Padding(2);
			this->WAITING->Name = L"WAITING";
			this->WAITING->Size = System::Drawing::Size(134, 37);
			this->WAITING->TabIndex = 13;
			this->WAITING->Text = L"Proces...";
			this->WAITING->UseVisualStyleBackColor = false;
			this->WAITING->Visible = false;
			this->WAITING->Click += gcnew System::EventHandler(this, &MyForm::WAITING_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBox1->Location = System::Drawing::Point(12, 457);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1002, 549);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->WAITING);
			this->Controls->Add(this->webBrowser2);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PLAY);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->DOWNLOADB);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"AnalGang";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion




	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void NORMAL_Click(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Start();
	}

	private: System::Void TEST_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}

	private: System::Void DOWNLOADB_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void PLAY_Click(System::Object^ sender, System::EventArgs^ e) {
		system("start calc.exe");
	}
		   // update progressbar
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
			this->progressBar1->Value = c;
			if (c == 100) {
				this->PLAY->Visible = true;
				this->WAITING->Visible = false;
			}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void webBrowser1_DocumentCompleted(System::Object^ sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^ e) {
}
private: System::Void WAITING_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}