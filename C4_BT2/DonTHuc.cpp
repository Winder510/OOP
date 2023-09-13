#include "DonThuc.h"
#include<iostream>
using namespace std;
//DonThuc::DonThuc() : heso(0), somu(0) {};
//DonThuc::DonThuc(int a, int b) : heso(a), somu(b) {};

void DonThuc::Nhap()
{
	cin >> heso;
	cin >> somu;
}
void DonThuc::setHeso(int a) { heso = a; }
void DonThuc::setSomu(int a) { somu = a; }

void DonThuc::Xuat()
{
	cout << heso << "x^" << somu;
}

int DonThuc::Tinh_GiaTri_tai(int x)
{
	return heso * pow(x, somu);
}

DonThuc DonThuc::DaoHam()
{
	DonThuc d;
	d.heso = heso * somu;
	d.somu = somu - 1;
	return d;
}
DonThuc DonThuc::CongDonThuc(DonThuc d)
{
	DonThuc kq;
	kq.heso = heso + d.heso;
	kq.somu = somu;
	return kq;
}
DonThuc::~DonThuc()
{}