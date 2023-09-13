#include<iostream>
#include"arrPhanSo.h"
#include"PhanSo.h"
 using namespace std;
int main()
{
	int n;
	cin >> n;
	arrPhanSo arr(n);
	arr.Nhap();
	cout << "Gia tri lon nhat cua mang:";
	PhanSo kq=arr.Tim_PS_Max();
	kq.Xuat();
	cout << "/nMang sau khi sap xep...";
	cout << "/n";
	arr.SapXepTangDan();
	arr.Xuat();

}