#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include "TAsyncDownload.h"
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
	public ref class MyForm : public System::Windows::Forms::Form {
		public:
		MyForm(void) {
			InitializeComponent();
		}

		protected:
		//Destruct
		~MyForm() {
			if(components) {
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



		private: System::Windows::Forms::Button^ WAITING;
		private: System::Windows::Forms::CheckBox^ checkBox1;
		private: System::Windows::Forms::Button^ DeArHiVe;
		private: System::Windows::Forms::Button^ File1Crash;
		private: System::Windows::Forms::Button^ File2Crash;
		private: System::Windows::Forms::Button^ File3Crash;
		private: System::Windows::Forms::Button^ File4Crash;

		private: System::Windows::Forms::PictureBox^ pictureBox2;
		private: System::Windows::Forms::PictureBox^ pictureBox3;
		private: System::Windows::Forms::WebBrowser^ webBrowser2;
		private: System::Windows::Forms::WebBrowser^ webBrowser1;
		private: System::Windows::Forms::WebBrowser^ webBrowser3;
		private: System::Windows::Forms::WebBrowser^ webBrowser4;





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
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->DOWNLOADB = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->PLAY = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->WAITING = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->DeArHiVe = (gcnew System::Windows::Forms::Button());
			this->File1Crash = (gcnew System::Windows::Forms::Button());
			this->File2Crash = (gcnew System::Windows::Forms::Button());
			this->File3Crash = (gcnew System::Windows::Forms::Button());
			this->File4Crash = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->webBrowser3 = (gcnew System::Windows::Forms::WebBrowser());
			this->webBrowser4 = (gcnew System::Windows::Forms::WebBrowser());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
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
			this->DOWNLOADB->Location = System::Drawing::Point(66, 107);
			this->DOWNLOADB->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DOWNLOADB->Name = L"DOWNLOADB";
			this->DOWNLOADB->Size = System::Drawing::Size(102, 27);
			this->DOWNLOADB->TabIndex = 3;
			this->DOWNLOADB->Text = L"UPDATE⟳";
			this->DOWNLOADB->UseVisualStyleBackColor = false;
			this->DOWNLOADB->Click += gcnew System::EventHandler(this, &MyForm::DOWNLOADB_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->progressBar1->Location = System::Drawing::Point(170, 107);
			this->progressBar1->Margin = System::Windows::Forms::Padding(0);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(465, 27);
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
			this->PLAY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PLAY->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PLAY->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PLAY->Location = System::Drawing::Point(66, 107);
			this->PLAY->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PLAY->Name = L"PLAY";
			this->PLAY->Size = System::Drawing::Size(102, 25);
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
			this->label1->Location = System::Drawing::Point(170, 134);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(465, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->ImageLocation = L"C:\\Igrushka\\no mercy.png";
			this->pictureBox1->Location = System::Drawing::Point(75, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(326, 57);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// WAITING
			// 
			this->WAITING->BackColor = System::Drawing::Color::SpringGreen;
			this->WAITING->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->WAITING->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->WAITING->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->WAITING->Location = System::Drawing::Point(66, 107);
			this->WAITING->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->WAITING->Name = L"WAITING";
			this->WAITING->Size = System::Drawing::Size(102, 27);
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
			this->checkBox1->Location = System::Drawing::Point(902, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// DeArHiVe
			// 
			this->DeArHiVe->BackColor = System::Drawing::Color::Yellow;
			this->DeArHiVe->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->DeArHiVe->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeArHiVe->Location = System::Drawing::Point(66, 107);
			this->DeArHiVe->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DeArHiVe->Name = L"DeArHiVe";
			this->DeArHiVe->Size = System::Drawing::Size(102, 47);
			this->DeArHiVe->TabIndex = 15;
			this->DeArHiVe->Text = L"Dearchive";
			this->DeArHiVe->UseVisualStyleBackColor = false;
			this->DeArHiVe->Visible = false;
			this->DeArHiVe->Click += gcnew System::EventHandler(this, &MyForm::DeArHiVe_Click);
			// 
			// File1Crash
			// 
			this->File1Crash->BackColor = System::Drawing::Color::Red;
			this->File1Crash->Cursor = System::Windows::Forms::Cursors::Hand;
			this->File1Crash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1Crash->Location = System::Drawing::Point(170, 155);
			this->File1Crash->Margin = System::Windows::Forms::Padding(0);
			this->File1Crash->Name = L"File1Crash";
			this->File1Crash->Size = System::Drawing::Size(92, 37);
			this->File1Crash->TabIndex = 16;
			this->File1Crash->Text = L"File 1 Crashed\r\nReload File 1";
			this->File1Crash->UseVisualStyleBackColor = false;
			this->File1Crash->Visible = false;
			this->File1Crash->Click += gcnew System::EventHandler(this, &MyForm::File1Crash_Click);
			// 
			// File2Crash
			// 
			this->File2Crash->BackColor = System::Drawing::Color::Red;
			this->File2Crash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File2Crash->Location = System::Drawing::Point(262, 155);
			this->File2Crash->Margin = System::Windows::Forms::Padding(0);
			this->File2Crash->Name = L"File2Crash";
			this->File2Crash->Size = System::Drawing::Size(92, 37);
			this->File2Crash->TabIndex = 17;
			this->File2Crash->Text = L"File 2 Crashed\r\nReload File 2";
			this->File2Crash->UseVisualStyleBackColor = false;
			this->File2Crash->Visible = false;
			this->File2Crash->Click += gcnew System::EventHandler(this, &MyForm::File2Crash_Click);
			// 
			// File3Crash
			// 
			this->File3Crash->BackColor = System::Drawing::Color::Red;
			this->File3Crash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File3Crash->Location = System::Drawing::Point(354, 155);
			this->File3Crash->Margin = System::Windows::Forms::Padding(0);
			this->File3Crash->Name = L"File3Crash";
			this->File3Crash->Size = System::Drawing::Size(92, 37);
			this->File3Crash->TabIndex = 18;
			this->File3Crash->Text = L"File 3 Crashed\r\nReload File 3";
			this->File3Crash->UseVisualStyleBackColor = false;
			this->File3Crash->Visible = false;
			this->File3Crash->Click += gcnew System::EventHandler(this, &MyForm::File3Crash_Click);
			// 
			// File4Crash
			// 
			this->File4Crash->BackColor = System::Drawing::Color::Red;
			this->File4Crash->Cursor = System::Windows::Forms::Cursors::Hand;
			this->File4Crash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File4Crash->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->File4Crash->Location = System::Drawing::Point(446, 155);
			this->File4Crash->Margin = System::Windows::Forms::Padding(0);
			this->File4Crash->Name = L"File4Crash";
			this->File4Crash->Size = System::Drawing::Size(92, 37);
			this->File4Crash->TabIndex = 19;
			this->File4Crash->Text = L"File 4 Crashed\r\nReload File 4";
			this->File4Crash->UseVisualStyleBackColor = false;
			this->File4Crash->Visible = false;
			this->File4Crash->Click += gcnew System::EventHandler(this, &MyForm::File4Crash_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(8, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(33, 27);
			this->pictureBox2->TabIndex = 21;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->Location = System::Drawing::Point(1, 516);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(55, 30);
			this->pictureBox3->TabIndex = 22;
			this->pictureBox3->TabStop = false;
			// 
			// webBrowser2
			// 
			this->webBrowser2->Location = System::Drawing::Point(66, 211);
			this->webBrowser2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->webBrowser2->MinimumSize = System::Drawing::Size(15, 16);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->Size = System::Drawing::Size(569, 66);
			this->webBrowser2->TabIndex = 23;
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(66, 295);
			this->webBrowser1->Margin = System::Windows::Forms::Padding(2);
			this->webBrowser1->MinimumSize = System::Drawing::Size(15, 16);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(569, 66);
			this->webBrowser1->TabIndex = 24;
			// 
			// webBrowser3
			// 
			this->webBrowser3->Location = System::Drawing::Point(66, 380);
			this->webBrowser3->Margin = System::Windows::Forms::Padding(2);
			this->webBrowser3->MinimumSize = System::Drawing::Size(15, 16);
			this->webBrowser3->Name = L"webBrowser3";
			this->webBrowser3->Size = System::Drawing::Size(569, 66);
			this->webBrowser3->TabIndex = 25;
			// 
			// webBrowser4
			// 
			this->webBrowser4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->webBrowser4->Location = System::Drawing::Point(66, 467);
			this->webBrowser4->Margin = System::Windows::Forms::Padding(2);
			this->webBrowser4->MaximumSize = System::Drawing::Size(700, 80);
			this->webBrowser4->MinimumSize = System::Drawing::Size(540, 55);
			this->webBrowser4->Name = L"webBrowser4";
			this->webBrowser4->Size = System::Drawing::Size(569, 66);
			this->webBrowser4->TabIndex = 26;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(994, 563);
			this->Controls->Add(this->webBrowser4);
			this->Controls->Add(this->webBrowser3);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->webBrowser2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->File4Crash);
			this->Controls->Add(this->File3Crash);
			this->Controls->Add(this->File2Crash);
			this->Controls->Add(this->File1Crash);
			this->Controls->Add(this->DeArHiVe);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->WAITING);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PLAY);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->DOWNLOADB);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximumSize = System::Drawing::Size(1410, 802);
			this->MinimumSize = System::Drawing::Size(1010, 602);
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AnalGang";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


		private: static const char* PPLAY_C = "start C:/Igrushka/WindowsNoEditor/myProject.exe";
		private: static const char* dearchPath = "start C:/Igrushka/WindowsNoEditor.part1.exe";


		private: void isFilesOk(int index);
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
		private: System::Void DOWNLOADB_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {

		}

		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);

		private: System::Void PLAY_Click(System::Object^ sender, System::EventArgs^ e) {
			system(PPLAY_C);
			std::exit(EXIT_SUCCESS);
		}

		private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e); // update progressbar

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void webBrowser1_DocumentCompleted(System::Object^ sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^ e) {
		}
		private: System::Void WAITING_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		}
		public: System::Void DeArHiVe_Click(System::Object^ sender, System::EventArgs^ e) {

			system(dearchPath);
		}
		private: System::Void File1Crash_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void File2Crash_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void File3Crash_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void File4Crash_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
