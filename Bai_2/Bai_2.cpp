// viet ctr nhap vao 1 phan so . rut gon phan so do va cho biets kq
#include<iostream>
using namespace std;
class CPhanSo
{
private:
	int tu;
	int mau;
public:
	void Nhap();
	void Xuat();
	void RutGon();
};
int main()
{
	CPhanSo ps;
	ps.Nhap();
	ps.RutGon();
	cout << "Phan so sau khi dc rut gon: ";
	ps.Xuat();
}
void CPhanSo::Nhap()
{
	cout << "Nhap tu so: ";
	cin >> tu;
	cout << "Nhap mau so: ";
	cin >> mau;
}
void CPhanSo::RutGon()
{
	int temp;
	int a = tu;
	int b = mau;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	int UCLN = a;
	tu = tu / UCLN;
	mau = mau / UCLN;
		
}
void CPhanSo::Xuat()
{
	cout << "\nTu= " << tu;
	cout << "\nMau= " << mau;
}