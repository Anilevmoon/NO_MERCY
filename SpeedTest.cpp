#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include <thread>   

int asyncDownTestFile() {
	auto th = std::thread{ [] {
		URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=191gIwh-S7BNs9f32oU5GpBXPg5d-kgHw", L"C:\\Users\\glebl\\Desktop\\TEST\\VidosTEST.mp4", 0, 0);
	 }
	};
	th.detach();
	return 0;
}

int TestSize(const char* Path0) {
	double Obshee;
	
	std::ifstream in(Path0);
	if (in.is_open())
	{
		std::string line;
		std::getline(in, line);
		std::istringstream ist(line);
		ist >> Obshee;
	}
	in.close();
	return Obshee;
}

bool downYet() {
	bool Downloaded = 0;
	std::ifstream ifs("C:\\Users\\glebl\\Desktop\\TEST\\VidosTEST.mp4", std::ios::binary);
	if (ifs) {
		ifs.seekg(0, std::ios::end);
		double size = ifs.tellg();
		Downloaded = 1;// size / (1024 * 1024);
	}
	return Downloaded;
}

double conectionSpeed(const char* Path) {
	double testSize = TestSize(Path);
	double time = 0;
	asyncDownTestFile();
	bool inc = downYet();
	while (inc == 0) {
		time += 0.1;
		std::cout << "TIME IS: " << time << std::endl;
		Sleep(100);
		inc = downYet();
	}
	std::cout << "TIME IS : " << time << "THE SPEED IS S/T = " << 40 / time << std::endl;
	return 40 / time;
}