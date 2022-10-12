#include "MyForm.h"
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(cli::array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    KURVA::MyForm form; 
    Application::Run(% form);

}


double conectionSpeed(const char* Path) ; 
double TestSize(const char* Path0);
bool IsDownloadedYet(const char* Path);

static const char* isExePath = "C:/Igrushka/WindowsNoEditor/myProject.exe";
static const char* PathTEST = "C:\\Igrushka\\Siz.txt";
static const char* PathMain = "C:\\Igrushka\\OBE.txt";
static const char* PathProgres = "C:\\Igrushka\\WindowsNoEditor\\Manifest_UFSFiles_Win64.txt";

System::Void KURVA::MyForm::DOWNLOADB_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->timer1->Start();
	this->timer2->Start();
	this->WAITING->Visible=true;
	this->DOWNLOADB->Visible=false;
	
	bool IndicatUpdating = UpdateDetect();

	if(IndicatUpdating) {
		auto speed = conectionSpeed(PathTEST);
		auto allSize = TestSize(PathMain);
		AsyncCinCrement(allSize, speed);
		AsyncDownloader();
	} else {
		auto isExe = IsDownloadedYet(isExePath);
		if(!isExe) {
			this->WAITING->Visible = false;
			this->DeArHiVe->Visible = true;
		} else {
			c = 100;
			this->progressBar1->Value = c;
			this->PLAY->Visible = true;
			this->WAITING->Visible = false;
			this->timer2->Stop();
		}
	}
		
}

System::Void KURVA::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if(c>=0) this->progressBar1->Value = c;
	auto in = std::ifstream(PathProgres);
	if(in.is_open()) {
		c = 100;
		this->timer1->Stop();
		this->PLAY->Visible = true;
		this->DeArHiVe->Visible = false;
		this->timer2->Stop();
	}
	return System::Void();
}
