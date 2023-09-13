#include "Dathuc.h"
#include"DonThuc.h"
#include<iostream>
using namespace std;


void Dathuc::Nhap()
{
	for (int i = bac; i >=0; i--)
	{
		arr[i].Nhap(i);
	}
}
void Dathuc::Xuat()
{
	for (int i = bac; i >= 0; i--)
	{
		arr[i].Xuat();
		if (i != 0)
			cout << " + ";
	}
}
int Dathuc::Tinh_Tai(int x)
{
	int sum = 0;
	for (int i = 0; i <= bac; i++)
		sum += arr[i].Tinh_tai(x);
	return sum;
}
Dathuc Dathuc::Cong_DaThuc(const Dathuc& p)
{
	int max_bac = max(bac, p.bac);
	Dathuc kq(max_bac);

	int i = 0;
	int j = 0;
	int k = 0;

	while (i <= bac && j <= p.bac) {
		if (arr[i].getMu() == p.arr[j].getMu()) {
			kq.arr[k] = arr[i].TongHaiDonThuc(p.arr[j]);
			i++;
			j++;
		}
		else if (arr[i].getMu() < p.arr[j].getMu()) {
			kq.arr[k] = arr[i];
			i++;
		}
		else {
			kq.arr[k] = p.arr[j];
			j++;
		}
		k++;
	}

	while (i <= bac) {
		kq.arr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= p.bac) {
		kq.arr[k] = p.arr[j];
		j++;
		k++;
	}
	return kq;
}

Dathuc Dathuc::Tru_DaThuc(const Dathuc& p)
{
	int max_bac = max(bac, p.bac);
	Dathuc kq(max_bac);

	int i = 0;
	int j = 0;
	int k = 0;

	while (i <= bac && j <= p.bac) {
		if (arr[i].getMu() == p.arr[j].getMu()) {
			kq.arr[k] = arr[i].TruHaiDonThuc(p.arr[j]);
			i++;
			j++;
		}
		else if (arr[i].getMu() < p.arr[j].getMu()) {
			kq.arr[k] = arr[i];
			i++;
		}
		else {
			kq.arr[k] = p.arr[j];
			j++;
		}
		k++;
	}

	while (i <= bac) {
		kq.arr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= p.bac) {
		kq.arr[k] = p.arr[j];
		j++;
		k++;
	}
	return kq;
}
Dathuc::~Dathuc()
{
	cout << "da xoa";
	delete[] arr;
}

