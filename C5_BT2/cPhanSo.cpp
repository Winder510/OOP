#include "cPhanSo.h"
#include<iostream>
using namespace std;
bool PhanSo::operator >(PhanSo p)
{
	float a = (float)tuso / mauso;
	float b = (float)p.tuso / p.mauso;
	return (a > b);
}
void PhanSo::Nhap()
{
	cin >> tuso;
	cin >> mauso;
}
PhanSo PhanSo::operator +(PhanSo p)
{
	PhanSo kq;
	kq.tuso = tuso * p.mauso + mauso * p.tuso;
	kq.mauso = mauso * p.mauso;
	return kq;
}
void PhanSo::Xuat()
{
	cout << tuso << "/" << mauso;
}
