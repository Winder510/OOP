// Viet ctr nhap vao mot phan so . cho biet no am hay duong
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
	int Xetdau();
};
int main()
{
	CPhanSo ps;
	ps.Nhap();
	cout << "Phan so vua nhap: ";
	ps.Xuat();
	int kq = ps.Xetdau();
	switch (kq)
	{
	case 1: cout << "\nPhan so duong";break;
	case -1: cout << "\nPhan so am"; break;
	case 0: cout << "\nPhan so bang 0";break;
	}
}
void CPhanSo::Nhap()
{
	cout << "Nhap tu: ";
	cin >> tu;
	cout << "Nhap mau: ";
	cin >> mau;
}
void CPhanSo::Xuat()
{
	cout << "\nTu="<<tu;
	cout << "\nMau=" << mau;
}
int CPhanSo::Xetdau()
{
	if (tu * mau > 0)
		return 1;
	if (tu * mau < 0)
		return -1;
	return 0;
}