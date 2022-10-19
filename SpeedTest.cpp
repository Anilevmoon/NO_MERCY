#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include <thread>   
#include<WinInet.h>

int FileSize(const char* path) {
	auto ifs = std::ifstream(path, std::ios::binary);
	ifs.seekg(0, std::ios::end);
	auto size = ifs.tellg();
	return size;
}


int asyncDownTestFile() {
	auto th = std::thread{ [=] {

	HINTERNET hInternetSession;
	HINTERNET hURL;

	BOOL bResult;
	DWORD dwBytesRead = 1;


	hInternetSession = InternetOpen(L"", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	hURL = InternetOpenUrl(hInternetSession, L"http://185.233.36.66:7777/nesty_test/Game/SPEED.rar", NULL, 0, 0, 0);

	char buf[1024];
	DWORD dwTemp;
	HANDLE hFile = CreateFile(L"C:\\Igrushka\\ViDoTEST.rar", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

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
	return 0;
}

double TestSize(const char* Path0) {
	auto fullDecSize = 0.0;
	auto in = std::ifstream(Path0);
	if(in.is_open()) {
		auto line = std::string();
		std::getline(in, line);
		auto ist = std::istringstream(line);
		ist >> fullDecSize;
	}
	return fullDecSize;
}

bool IsDownloadedYet(const char* Path) {
	auto isDowloaded = false;
	auto ifs = std::ifstream(Path, std::ios::binary);

	ifs.seekg(0, std::ios::end);
	auto size = ifs.tellg();
	if(size>20) {
		isDowloaded = true; // size / (1024 * 1024);
	}
	return isDowloaded;
}

double conectionSpeed(const char* Path) {
	DeleteFile(L"C:\\Igrushka\\ViDoTEST.rar");
	auto time = 0.0;
	asyncDownTestFile();
	auto inc = IsDownloadedYet("C:\\Igrushka\\ViDoTEST.rar");
	while(!inc) {
		time += 0.1;
		Sleep(100);
		inc = IsDownloadedYet("C:\\Igrushka\\ViDoTEST.rar");
	}
	auto TimSize = FileSize("C:\\Igrushka\\ViDoTEST.rar") / (1024*1024);
	return TimSize / time;
}