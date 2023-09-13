#pragma once
class PhanSo
{
private:
	int tu;
	int mau;
public:
	PhanSo() :tu(0), mau(0) {}
	PhanSo(int a, int b) : tu(a), mau(b) {}

	void Nhap();
	void Xuat();
	float Lay_GiaTri();
};

