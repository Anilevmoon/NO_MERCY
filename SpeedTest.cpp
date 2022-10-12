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
	auto th = std::thread{ [] {
		URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1wBVmmCpPJjER1jVfotGFx4OovsXOLmbV", L"C:\\Igrushka\\VidosTEST.rar", 0, 0);
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
	if(size>0) {
		isDowloaded = true; // size / (1024 * 1024);
	}
	return isDowloaded;
}

double conectionSpeed(const char* Path) {
	DeleteFile(L"C:\\Igrushka\\VidosTEST.rar");
	auto time = 0.0;
	asyncDownTestFile();
	auto inc = IsDownloadedYet("C:\\Igrushka\\VidosTEST.rar");
	while(!inc) {
		time += 0.2;
		Sleep(200);
		inc = IsDownloadedYet("C:\\Igrushka\\VidosTEST.rar");
	}
	auto TimSize = FileSize("C:\\Igrushka\\VidosTEST.rar") / (1024*1024);
	return TimSize / time;
}