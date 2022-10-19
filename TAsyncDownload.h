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

//TXT FILES AUTOLOAD
auto File1Path = TEXT("C:\\Igrushka\\File1.txt");
LPCTSTR Path1File = File1Path;
auto File1URL = TEXT("http://185.233.36.66:7777/nesty_test/Game/Sizes/File1.txt");
LPCTSTR PathFileSize1URL = File1URL;

auto File2Path = TEXT("C:\\Igrushka\\File2.txt");
LPCTSTR Path2File = File2Path;
auto File2URL = TEXT("http://185.233.36.66:7777/nesty_test/Game/Sizes/File2.txt");
LPCTSTR PathFileSize2URL = File2URL;

auto File3Path = TEXT("C:\\Igrushka\\File3.txt");
LPCTSTR Path3File = File3Path;
auto File3URL = TEXT("http://185.233.36.66:7777/nesty_test/Game/Sizes/File3.txt");
LPCTSTR PathFileSize3URL = File3URL;

auto File4Path = TEXT("C:\\Igrushka\\File4.txt");
LPCTSTR Path4File = File4Path;
auto File4URL = TEXT("http://185.233.36.66:7777/nesty_test/Game/Sizes/File4.txt");
LPCTSTR PathFileSize4URL = File4URL;



auto FirstExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part1.exe");
LPCTSTR Path1exe = FirstExePath;
auto FirstExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part1.exe");
LPCTSTR Path1URL = FirstExeURL;

auto SecondExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part2.rar");
LPCTSTR Path2exe = SecondExePath;
auto SecondRARURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part2.rar");
LPCTSTR Path2URL = SecondRARURL;

auto ThirdExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part3.rar");
LPCTSTR Path3exe = ThirdExePath;
auto ThirdExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part3.rar");
LPCTSTR Path3URL = ThirdExeURL;

auto FouthExePath = TEXT("C:\\Igrushka\\WindowsNoEditor.part4.rar");
LPCTSTR Path4exe = FouthExePath;
auto FouthExeURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/WindowsNoEditor.part4.rar");
LPCTSTR Path4URL = FouthExeURL;

auto VERtxtPath = TEXT("C:\\Igrushka\\VERSION.txt");
LPCTSTR PathVersionTXT = VERtxtPath;
auto VERtxtURL = TEXT("http://185.233.36.66:7777/nesty_test/Game/version.txt");
LPCTSTR URLversionTXT = VERtxtURL ;

bool CheckFile() {
	auto file = std::ifstream("C:\\Igrushka\\VERSION.txt");
	if(file.is_open()==true) {
		return true;
	} else {
		return false;
	}
}

void V2YskolaichDownload(LPCTSTR Path, LPCTSTR URL) {
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

void ASYNCV2YskolaichDownload(LPCTSTR Path, LPCTSTR URL) {
	auto th = std::thread{ [=] {
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


void AsyncDownloader() {
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
		auto in = std::ifstream("C:\\Igrushka\\VERSION.txt");

		if(in.is_open()) {
			getline(in, oldVer);
			in.close();
		}
		
		V2YskolaichDownload(PathVersionTXT, URLversionTXT);

		auto newVer = std::string();
		auto inn = std::ifstream("C:\\Igrushka\\VERSION.txt");//если скачиваешь файл по тому же пути он заменяеться или как?

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
