#pragma once
#include <string>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include <fstream>
#include <urlmon.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <thread>  

double c = 0.0;
double pointsByInrementPer500mls = 0.0;
auto IndicatUpdating = false;

bool CheckFile() {
	auto file = std::ifstream("C:\\Igrushka\\MatVkanave.txt");
	if(file.is_open()==true) {
		return true;
	} else {
		return false;
	}
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
