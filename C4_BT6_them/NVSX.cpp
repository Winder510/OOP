#include "NVSX.h"
#include<iostream>
#include<string>
using namespace std;
void NVSX:: Nhap()
{
	cout << "Nhap ho ten:";
	getline(cin, hoten);
	cout << "Nhap vao DOB:";
	cin >> ngay >> thang >> nam;
	cout << "Nhap so san pham lam duoc:";
	cin >> sosanpham;
	cout << "Nhap luong co ban:";
	cin >> luongCB;
	luong = TinhLuong();
}
int NVSX::TinhLuong()
{
	return luongCB + sosanpham * 5000;
}
void NVSX::Xuat()
{
	cout << "Ho ten:" << hoten<<endl;
	cout << "DOB:" << ngay << "/" << thang << "/" << nam << endl;
	cout << "Luong:" << luong;
}
string NVSX::getHo() {
	int pos = hoten.find(" ");
		return hoten.substr(0, pos);
}
int NVSX::getTuoi()
{
	return 2023 - nam;
}
int NVSX::getLuong()
{
	return luong;
}