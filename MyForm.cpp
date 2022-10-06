#include "MyForm.h"

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
int TestSize(const char* Path0);

System::Void KURVA::MyForm::DOWNLOADB_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->timer2->Start();
	const char* Path1 = "C:\\Users\\glebl\\Desktop\\TEST\\Siz.txt";
	const char* PathMain = "C:\\Igrushka\\OBE.txt";
	this->WAITING->Visible=true;
	this->DOWNLOADB->Visible=false;
	

	Skachka();
	if (IndicatUpdating) {
		double Speed = conectionSpeed(Path1);
		double allSize = TestSize(PathMain);
		asyncCinCrement(allSize, Speed);
		asyncDownloader();
	}
	else {
		c = 100;
		this->progressBar1->Value = c;
		this->PLAY->Visible = true;
		this->WAITING->Visible = false;
		this->timer1->Stop();
		this->timer2->Stop();
	}
		
}
