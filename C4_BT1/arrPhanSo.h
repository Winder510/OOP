#pragma once
#include"PhanSo.h"
class arrPhanSo
{
private:
	PhanSo* arr;
	int n;
public:
	arrPhanSo(int size = 0)
	{
		n = size;
		arr = new PhanSo[n];
	}
	void Nhap();
	void Xuat();
	PhanSo Tim_PS_Max();
	void SapXepTangDan();
	
};

