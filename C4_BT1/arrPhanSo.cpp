#include "arrPhanSo.h"
#include<iostream>
using namespace std;

void arrPhanSo:: Nhap()
{
	for (int i = 0; i < n; i++)
		arr[i].PhanSo::Nhap();
}
void arrPhanSo::Xuat()
{
	for (int i = 0; i < n; i++)
	{
		arr[i].PhanSo::Xuat();
		cout << " ";
	}
}
PhanSo arrPhanSo::Tim_PS_Max()
{
	float max = arr[0].Lay_GiaTri();
	int index= 0;
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i].Lay_GiaTri()) {
			max = arr[i].Lay_GiaTri();
			index = i;
		}
	}
	return arr[index];
}
void arrPhanSo::SapXepTangDan()
{
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].Lay_GiaTri() < arr[j].Lay_GiaTri())
				swap(arr[i], arr[j]);
		}
}
