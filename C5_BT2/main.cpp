
#include"DSPhanSo.h"
#include<iostream>
using namespace std;
int main()
{
	DSPhanSo arr(5);
	arr.Nhap();
	PhanSo kq = arr.Tim_PSMAX();
	kq.Xuat();
}