/*Viết ctr nhạp họ tên điểm toán điểm văn của một hs. tính điểm tb và xuất kq */
#include<iostream>
#include<string>
using namespace std;
class CHocSinh
{
private:
	string hoten;
	int toan;
	int van;
	float dtb;
public:
	void Nhap();
	void Xuat();
	void Xuly();
};
int main()
{
	CHocSinh hs;
	hs.Nhap();	
	hs.Xuly();
	hs.Xuat();
	return 1;
}
void CHocSinh::Nhap()
{
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap toan: ";
	cin >> toan;
	cout << "Nhap van: ";
	cin >> van;
}
void CHocSinh::Xuly()
{
	dtb = (float)(toan + van) / 2;
}
void CHocSinh::Xuat()
{
	cout << "Ho ten: " << hoten;
	cout << "Diem toan: " << toan;
	cout << "Diem van:" << van;
	cout << "Diem trung binh:" << dtb;

}