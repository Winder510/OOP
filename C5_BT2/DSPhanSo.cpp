#include "DSPhanSo.h"
#include"cPhanSo.h"
void DSPhanSo::Nhap()
{
	for (int i = 0; i < n; i++)
		ds[i].Nhap();
}
PhanSo DSPhanSo::Tim_PSMAX()
{
	PhanSo max = ds[0];
	for (int i = 1; i < n; i++)
		if (ds[i] > max)
			max = ds[i];
	return max;
}
PhanSo DSPhanSo::Tinh_Tong()
{
	PhanSo kq;
	for (int i = 0; i < n; i++)
		kq = kq + ds[i];
	return kq;
}
//PhanSo& DSPhanSo::operator[](int i)
//{
//	return ds[i];
//}

