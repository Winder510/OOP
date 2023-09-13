#include<iostream>
#include"Dathuc.h"
#include"DonThuc.h"
using namespace std;
int main()
{
	
	Dathuc d1(3);
	Dathuc d2(4);
	cout << "Nhap vao da thuc 1:\n";
	d1.Nhap();
	cout << "Xuat da thuc 1 la:";
	d1.Xuat();
	cout << "\nNhap vao da thuc 2:\n";
	d2.Nhap();
	cout << "Xuat da thuc 2 la:";
	d2.Xuat();
	cout << "\nCong hai da thuc:\n";
	Dathuc kq;
	kq=(d1.Cong_DaThuc(d2));
	kq.Xuat();
	
	return 0;
}