#include "PhanSo.h"
#include<iostream>
using namespace std;
void PhanSo::Nhap()
{
	cin >> tu;
	cin >> mau;
}
void PhanSo::Xuat()
{
	cout << tu << "/" << mau;
}
float PhanSo::Lay_GiaTri()
{
	return (float)tu / mau;
}
