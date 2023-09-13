#pragma once
#include<iostream>
#include<string>
using namespace std;
class NVSX
{
private:
	string hoten;
	int ngay, thang, nam;
	int luong;
	int luongCB, sosanpham;
public:

	NVSX(string h = "", int d = 0, int m = 0, int y = 0, int l = 0) {
		hoten = h;
		ngay = d;
		thang = m;
		nam = y;
		luong = l;
	}
	void Nhap();
	void Xuat();
	int TinhLuong();
	string getHo();
	int getTuoi();
	int getLuong();


		
};

