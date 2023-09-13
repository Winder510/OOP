#include "DonThuc.h"
#include<iostream>
using namespace std;

void DonThuc::Nhap(int i)
{
	cout << "Nhap vao he so cua x^"<<i<<":";
	cin >> heso;
	this->mu = i;
}
void DonThuc::Xuat()
{
	cout << heso << "x^" << mu;
}
int DonThuc::Tinh_tai(int x)
{
	return heso * pow(x, mu);
}
DonThuc DonThuc::TongHaiDonThuc(const DonThuc& d)
{
	DonThuc kq;
	kq.heso = heso + d.heso;
	kq.mu = mu;
	return kq;
}
DonThuc DonThuc::TruHaiDonThuc(const DonThuc& d)
{
	DonThuc kq;
	kq.heso = heso - d.heso;
	kq.mu = mu;
	return kq;
}
int DonThuc::getMu()
{
	return mu;
}
DonThuc::~DonThuc()
{

}
