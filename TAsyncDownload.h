#pragma once
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include <fstream>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <thread>  
#include <wininet.h>
#pragma comment(lib,"wininet")

double c = 0.0;
double pointsByInrementPer500mls = 0.0;
auto IndicatUpdating = false;


auto FirstExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part1.exe");
LPCTSTR Path1exe = FirstExePath;
auto FirstExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part1.exe");
LPCTSTR Path1URL = FirstExeURL;

auto SecondExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part2.exe");
LPCTSTR Path2exe = SecondExePath;
auto SecondExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part2.exe");
LPCTSTR Path2URL = SecondExeURL;

auto ThirdExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part3.exe");
LPCTSTR Path3exe = ThirdExePath;
auto ThirdExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part3.exe");
LPCTSTR Path3URL = ThirdExeURL;

auto FouthExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part4.exe");
LPCTSTR Path4exe = FouthExePath;
auto FouthExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part4.exe");
LPCTSTR Path4URL = FouthExeURL;

auto VERtxtPath = TEXT("C:\\Igrushka\\VERSION.txt");
LPCTSTR PathVersionTXT = VERtxtPath;
auto VERtxtURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/version.txt");
LPCTSTR URLversionTXT = VERtxtURL ;

bool CheckFile() {
	auto file = std::ifstream("C:\\Igrushka\\MatVkanave.txt");
	if(file.is_open()==true) {
		return true;
	} else {
		return false;
	}
}

void V2YskolaichDownload(LPCTSTR Path, LPCTSTR URL) {
	auto th = std::thread{ [&] {
	HINTERNET hInternetSession;
	HINTERNET hURL;

	BOOL bResult;
	DWORD dwBytesRead = 1;


	hInternetSession = InternetOpen(L"", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	hURL = InternetOpenUrl(hInternetSession, URL, NULL, 0, 0, 0);

	char buf[1024];
	DWORD dwTemp;
	HANDLE hFile = CreateFile(Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	for (; dwBytesRead > 0;)
	{
		InternetReadFile(hURL, buf, (DWORD)sizeof(buf), &dwBytesRead);
		WriteFile(hFile, buf, dwBytesRead, &dwTemp, NULL);
	}

	InternetCloseHandle(hURL);
	InternetCloseHandle(hInternetSession);

	CloseHandle(hFile);
			}
	};
	th.detach();
}

void ATHYNCV2YskolaichDownload() {
	auto th = std::thread{ [&] {

	V2YskolaichDownload(Path1exe, Path1URL);
	V2YskolaichDownload(Path2exe, Path2URL);
	V2YskolaichDownload(Path3exe, Path3URL);
	V2YskolaichDownload(Path4exe, Path4URL);
	V2YskolaichDownload(PathVersionTXT, URLversionTXT);
		}
	};
	th.detach();
}

void AsyncDownloader() {
	auto th = std::thread{ [] {
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1Bf2fFO1FgRa-1Rk5VTo6Lc50Ga1CXZLa", L"C:\\Igrushka\\WindowsNoEditor.part1.exe", 0, 0);
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1NqiYMnM7o5bRim1J_kxbba93eUtWW_Wt", L"C:\\Igrushka\\WindowsNoEditor.part2.rar", 0, 0);
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=177XmrXvQ-vz_cHruCr6zVrqgCmnN5nnM", L"C:\\Igrushka\\WindowsNoEditor.part3.rar", 0, 0);
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1XqHZ_W1mmdzwvgZEwc_faZ-_9wWuEQGH", L"C:\\Igrushka\\WindowsNoEditor.part4.rar", 0, 0);
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1RC9eS-vFBR-l7z1q8NNaY3oEtstsNJuM", L"C:\\Igrushka\\MatVkanave.txt", 0, 0);
		}
	};
	th.detach();
}


void AsyncCinCrement(const double size, const double speed) {
	pointsByInrementPer500mls = 100 / ( ( size  / speed ) / 0.5);
	auto Ccontrol = std::thread([] {
		do {
			if(c + pointsByInrementPer500mls>=100) {
				c = 99;
			} else {
				c += pointsByInrementPer500mls;
			}
			Sleep(500);
		} while(c<100);
		}
	);
	Ccontrol.detach();
}



bool UpdateDetect() {
	auto i = CheckFile();
	if(i) {
		auto oldVer = std::string();
		auto in = std::ifstream("C:\\Igrushka\\MatVkanave.txt");

		if(in.is_open()) {
			getline(in, oldVer);
			in.close();
		}
		
		URLDownloadToFile(0, L"https://anonfiles.com/7cpbT5Bby8/MatVkanave_txt", L"C:\\Igrushka\\MatVkanave.txt", 0, 0);

		auto newVer = std::string();
		auto inn = std::ifstream("C:\\Igrushka\\MatVkanave.txt");//если скачиваешь файл по тому же пути он заменяеться или как?

		if(inn.is_open()) std::getline(inn, newVer);
		inn.close();

		if(oldVer==newVer) {
			c = 100;
			return false;
		} else {
			return true;
		}
	} else {
		LPCWSTR path = L"C:\\Igrushka";
		CreateDirectory(path, 0);
		return true;
		//Треба підгрузити файл з розміром або винайти як його дістати
	}
}
