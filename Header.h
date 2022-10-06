#pragma once
#include <string>#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#include <fstream>
#include <urlmon.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <thread>   
using namespace std;


double c = 0;
int Time = 0;
double pointsByInrementPer500mls = 0;
auto IndicatUpdating = false;

int checkFile() {

	std::ifstream file;
	file.open("C:\\Igrushka\\MatVkanave.txt");
	if (!file) {
		Time = 1;
		return 0;
	}
	else {
		return 1;
	}
}


int asyncDownloader() {
	auto th = std::thread{ [] {
			URLDownloadToFile(0, L"https://drive.google.com/uc?export=download&confirm=no_antivirus&id=191gIwh-S7BNs9f32oU5GpBXPg5d-kgHw", L"C:\\Igrushka\\VidosTEST.mp4", 0, 0);
			URLDownloadToFile(0, L"https://www.googleapis.com/drive/v3/files/1nPyC4dlwXiBHoKDhOnk63UcqtnFpKbdc?alt=media&key=AIzaSyAYRHF6vblVv-x0uaqSuh_drnPhLh-IOV4", L"C:\\Igrushka\\MatVkanave.txt", 0, 0);
		}
	};
	th.detach();
	return 0;
}


int asyncCinCrement(double Size, double Speed) {
	pointsByInrementPer500mls = 100/(((Size/1000) / Speed)/0.5);
	auto Ccontrol = std::thread{ [] {
		pointsByInrementPer500mls = floor(pointsByInrementPer500mls);
		do {
			if (c + pointsByInrementPer500mls >= 100) {
				c = 100;
				return 0;
			}
			else {
				c = c + pointsByInrementPer500mls;
			}
			Sleep(500);
	} while (c < 100);
	c = 100;
	}
	};
	Ccontrol.detach();
	return 0;
}



int Skachka()
{
	auto i = checkFile();
	if (i == 1)
	{
		string oldVer;
		ifstream in("C:\\Igrushka\\MatVkanave.txt");
		if (in.is_open())
		{
			getline(in, oldVer);
		}
		in.close();
		URLDownloadToFile(0, L"https://www.googleapis.com/drive/v3/files/1nPyC4dlwXiBHoKDhOnk63UcqtnFpKbdc?alt=media&key=AIzaSyAYRHF6vblVv-x0uaqSuh_drnPhLh-IOV4", L"C:\\Igrushka\\MatVkanave.txt", 0, 0);
		string newVer;
		ifstream inn("C:\\Igrushka\\MatVkanave.txt");//если скачиваешь файл по тому же пути он заменяеться или как?
		if (inn.is_open())
		{
			getline(inn, newVer);
		}
		inn.close();
		if (oldVer == newVer) {
			c = 100;
			IndicatUpdating = false;
			return 0;
		}
		else {
			IndicatUpdating = true;
			//asyncDownloader();
			

		}
	}
	else
	{
		IndicatUpdating = true;
		//CreateDirectory(L"C:\\Igrushka", NULL);
		//asyncDownloader();
	}
	return 0;
}
