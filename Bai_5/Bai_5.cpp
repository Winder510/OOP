// viet ctr nhap vao toa do hai diem trong khong gian. tinh khoang cach giua chung
#include<iostream>
#include<cmath>
using namespace std;
class CDiemKG
{
private:
	float x;
	float y;
	float z;
public:
	void Nhap();
	void Xuat();
	float distance(CDiemKG);
};
int main()
{
	CDiemKG A, B;
	cout << "Nhap toa do diem A:";
	A.Nhap();
	cout << "Nhap vao toa do diem B:";
	B.Nhap();
	float kq = A.distance(B);
	cout << "Khoang cach giua hai diem la:" << kq;
}
void CDiemKG::Nhap()
{
	cout << "Nhap x=";
	cin >> x;
	cout << "Nhap y=";
	cin >> y;
	cout << "Nhap z=";
	cin >> z;
}
void CDiemKG::Xuat()
{
	cout << "x=" << x;
	cout << "\ny=" << y;
	cout << "\nz=" << z;
}
float CDiemKG::distance(CDiemKG P)
{
	return sqrt(pow(x - P.x, 2) + pow(y - P.y, 2) + pow(z - P.z, 2));
}