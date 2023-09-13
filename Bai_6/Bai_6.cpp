/*Nhập vao hai phan so . tính tong hieu tich thuong */
#include<iostream>
#include<cmath>
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
	CPhanSo add(CPhanSo);
	CPhanSo sub(CPhanSo);
	CPhanSo multi(CPhanSo);
	CPhanSo div(CPhanSo);
};
int main()
{
	CPhanSo A,B;
	cout << "Nhap vao phan so thu nhat:\n";
	A.Nhap();
	cout << "Nhap vao phan so thu hai:\n";
	B.Nhap();
	CPhanSo kq = A.add(B);
	cout << "Tong hai phan so la:\n";
	kq.Xuat();
	kq = A.sub(B);
	cout << "\nHieu hai so la:\n" ;
	kq.Xuat();
	kq = A.multi(B);
	cout << "\nTich hai phan so la:\n";
	kq.Xuat();
	kq = A.div(B);
	cout << "\nThuong hai Phan so la:\n" ;
	kq.Xuat();

}
void CPhanSo::Nhap()
{
	cout << "Nhap tu:";
	cin >> tu;
	cout << "Nhap mau:";
	cin >> mau;
}
void CPhanSo::Xuat()
{
	cout << "tu=" << tu;
	cout << "\nmau=" << mau;
}
CPhanSo CPhanSo::add(CPhanSo P)
{
	CPhanSo kq;
	kq.tu = (tu * P.mau + mau * P.tu);
	kq.mau = (mau * P.mau);
	return kq;
}
CPhanSo CPhanSo::sub(CPhanSo P)
{
	CPhanSo kq;
	kq.tu = (tu * P.mau - mau * P.tu);
	kq.mau = (mau * P.mau);
	return kq;
}
CPhanSo CPhanSo::multi(CPhanSo P)
{
	CPhanSo kq;
	kq.tu = tu * P.tu;
	kq.mau = mau * P.mau;
	return kq;
}
CPhanSo CPhanSo::div(CPhanSo P)
{
	CPhanSo kq;
	kq.tu = tu * P.mau;
	kq.mau = mau * P.tu;
	return kq;
}