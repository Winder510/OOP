#pragma once
#include<iostream>
using namespace std;
class DonThuc
{
private:
	int heso;
	int mu;
public:
	DonThuc(int a = 0, int b = 0) :heso(a), mu(b) {};

	void Nhap(int i);
	void Xuat();
	int Tinh_tai(int);
	int getMu();
	DonThuc TongHaiDonThuc(const DonThuc& d);
	DonThuc TruHaiDonThuc(const DonThuc& d);
	~DonThuc();

};


