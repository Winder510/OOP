// viets ctr nhap vao toa do cua hai diem . tinh kc giua chung vaf xuats kq
#include<iostream>
#include<cmath>
using namespace std;
class CDiem
{
private:
	float x;
	float y;
public:
	void Nhap();
	void Xuat();
	float distance(CDiem);
};
int main()
{
	CDiem A, B;
	cout << "Nhap toa do diem A";
	A.Nhap();
	cout << "\nNhap toa do diem B:";
	B.Nhap();
	float kq = B.distance(A);	
	cout << "Toa do diem A";
	A.Xuat();
	cout << "\n\Toa do diem B ";
	B.Xuat();
	cout << "\nKhoang cach la: " << kq;
}
void CDiem::Nhap()
{
	cout << "\nNhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}
void CDiem::Xuat()
{
	cout << "\nx=" << x;
	cout << "\ny=" << y;
}
float CDiem::distance(CDiem P)
{
	return sqrt(pow(x - P.x, 2) + pow(y - P.y, 2));
}
