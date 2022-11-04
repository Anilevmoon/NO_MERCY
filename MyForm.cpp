#include "MyForm.h"
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

//Добавити кнопку помилки і перезагрузки нового тому + відсутність мережі + видалення вже розархівованиї. 

void main(cli::array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURVA::MyForm form;
	Application::Run(% form);

}


double conectionSpeed(const char* Path);
double TestSize(const char* Path0);
bool IsDownloadedYet(const char* Path);

static const char* isExePath = "C:/Igrushka/WindowsNoEditor/myProject.exe";
static const char* PathTEST = "C:\\Igrushka\\Siz.txt";
static const char* PathMain = "C:\\Igrushka\\OBE.txt";
static const char* PathProgres = "C:\\Igrushka\\WindowsNoEditor\\Manifest_UFSFiles_Win64.txt";


static const char* File1 = "C:\\Igrushka\\WindowsNoEditor.part1.exe";
static const char* PathSizeFile1 = "C:\\Igrushka\\File1.txt";
static const char* File2 = "C:\\Igrushka\\WindowsNoEditor.part2.rar";
static const char* PathSizeFile2 = "C:\\Igrushka\\File2.txt";
static const char* File3 = "C:\\Igrushka\\WindowsNoEditor.part3.rar";
static const char* PathSizeFile3 = "C:\\Igrushka\\File3.txt";
static const char* File4 = "C:\\Igrushka\\WindowsNoEditor.part4.rar";
static const char* PathSizeFile4 = "C:\\Igrushka\\File4.txt";
double speed;
auto isAsyncRuning = false;
static auto allFilesOk = false;
bool DovnEnd = false;

System::Void KURVA::MyForm::DOWNLOADB_Click(System::Object^ sender, System::EventArgs^ e) {
	this->timer1->Start();
	this->timer2->Start();
	this->WAITING->Visible = true;
	this->DOWNLOADB->Visible = false;

	bool IndicatUpdating = UpdateDetect();

	if(IndicatUpdating) {
		speed = conectionSpeed(PathTEST);
		auto allSize = TestSize(PathMain);
		AsyncCinCrement(allSize, speed, 100);
		AsyncDownloader();
	} else {
		auto isExe = IsDownloadedYet(isExePath);
		if(!isExe) {
			this->WAITING->Visible = false;
			isFilesOk(1);
		} else {
			c = 100;
			this->progressBar1->Value = c;
			this->PLAY->Visible = true;
			this->WAITING->Visible = false;
			this->timer2->Stop();
		}
	}

}
int SizeFromFileInMB(const char* Path) {
	auto StringSize = std::string();
	auto in = std::ifstream(Path);
	if(in.is_open()) {
		getline(in, StringSize);
		in.close();
	}
	int intSize = stoi(StringSize);
	return intSize;
}

bool isOk(const char* File, const char* PathSizeFile) {
	auto iffile = std::ifstream(File, std::ios::binary);
	iffile.seekg(0, std::ios::end);
	auto size = iffile.tellg() / (1024*1024);

	int intNormalSize = SizeFromFileInMB(PathSizeFile);

	auto isOk = (size >= intNormalSize);
	return isOk;
}

void KURVA::MyForm::isFilesOk(int index) {
	auto F1OK = isOk(File1, PathSizeFile1);
	auto F2OK = isOk(File2, PathSizeFile2);
	auto F3OK = isOk(File3, PathSizeFile3);
	auto F4OK = isOk(File4, PathSizeFile4);

	if(index == 1) {
		if(!F1OK) {
			this->File1Crash->Visible = true;
			this->DeArHiVe->Visible = false;
		}

		if(!F2OK) {
			this->File2Crash->Visible = true;
			this->DeArHiVe->Visible = false;
		}

		if(!F3OK) {
			this->File3Crash->Visible = true;
			this->DeArHiVe->Visible = false;
		}

		if(!F4OK) {
			this->File4Crash->Visible = true;
			this->DeArHiVe->Visible = false;
		}
		if(F1OK&&F2OK&&F3OK&&F4OK) {
			this->DeArHiVe->Visible = true;
			allFilesOk = true;
		}
	} else {
		if(F1OK&&F2OK&&F3OK&&F4OK) {
			this->DeArHiVe->Visible = true;
			DovnEnd = true;
		}
	}

}

System::Void KURVA::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	ASYNCV2YskolaichDownload(Path1File, PathFileSize1URL);
	ASYNCV2YskolaichDownload(Path2File, PathFileSize2URL);
	ASYNCV2YskolaichDownload(Path3File, PathFileSize3URL);
	ASYNCV2YskolaichDownload(Path4File, PathFileSize4URL);

	return System::Void();
}

System::Void KURVA::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	isFilesOk(0);
	if(DovnEnd) {
		c = 99;
		if(PLAY->Visible == false) {
			isFilesOk(1);
		} else if(allFilesOk) {
			this->WAITING->Visible = false;
			this->timer1->Stop();
		}

	}
	return System::Void();
}

System::Void KURVA::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if(c>=0) this->progressBar1->Value = c;

	auto in = std::ifstream(PathProgres);
	if(in.is_open()) {
		c = 100;
		this->progressBar1->Value = c;
		this->timer1->Stop();
		this->PLAY->Visible = true;
		this->DeArHiVe->Visible = false;
		this->timer2->Stop();
	}
	return System::Void();
}

System::Void KURVA::MyForm::File1Crash_Click(System::Object^ sender, System::EventArgs^ e) {
	ASYNCV2YskolaichDownload(Path1exe, Path1URL);
	c -= 28;
	auto Size = SizeFromFileInMB(PathSizeFile1);
	if(!isAsyncRuning) {
		speed = conectionSpeed(PathTEST);
		AsyncCinCrement(Size, speed, 30);
		isAsyncRuning = true;
	}

	this->File1Crash->Visible = false;
	this->WAITING->Visible = true;
	return System::Void();
}

System::Void KURVA::MyForm::File2Crash_Click(System::Object^ sender, System::EventArgs^ e) {

	ASYNCV2YskolaichDownload(Path2exe, Path2URL);
	c -= 28;
	auto Size = SizeFromFileInMB(PathSizeFile2);
	if(!isAsyncRuning) {
		speed = conectionSpeed(PathTEST);
		AsyncCinCrement(Size, speed, 30);
		isAsyncRuning = true;
	}

	this->File2Crash->Visible = false;
	this->WAITING->Visible = true;
	return System::Void();
}

System::Void KURVA::MyForm::File3Crash_Click(System::Object^ sender, System::EventArgs^ e) {
	ASYNCV2YskolaichDownload(Path3exe, Path3URL);
	c -= 28;
	auto Size = SizeFromFileInMB(PathSizeFile3);
	if(!isAsyncRuning) {
		speed = conectionSpeed(PathTEST);
		AsyncCinCrement(Size, speed, 30);
		isAsyncRuning = true;
	}

	this->File3Crash->Visible = false;
	this->WAITING->Visible = true;
	return System::Void();
}

System::Void KURVA::MyForm::File4Crash_Click(System::Object^ sender, System::EventArgs^ e) {
	ASYNCV2YskolaichDownload(Path4exe, Path4URL);
	c -= 16;
	auto Size = SizeFromFileInMB(PathSizeFile4);
	if(!isAsyncRuning) {
		speed = conectionSpeed(PathTEST);
		AsyncCinCrement(Size, speed, 10);
		isAsyncRuning = true;
	}

	this->File4Crash->Visible = false;
	this->WAITING->Visible = true;
	return System::Void();
}
