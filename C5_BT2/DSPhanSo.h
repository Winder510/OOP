#pragma once
#include"cPhanSo.h"
class DSPhanSo
{
private:
	int n;
	PhanSo* ds;
public:
	DSPhanSo(int sl = 0)
	{
		n = sl;
		ds = new PhanSo[n];
	}
	void Nhap();
	PhanSo Tim_PSMAX();
	PhanSo Tinh_Tong();
//	PhanSo& operator[](int i);
	
};

