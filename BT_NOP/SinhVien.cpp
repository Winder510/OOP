#include<iostream>
#include<string>
using namespace std;
class SinhVienDaiHoc
{
private:
	string MSSV;
	string HoTen;
	string DiaChi;
	int TongSoTinChi;
	float DTB;
	string TenLuanVan;
	float DiemLuanVan;
public:
	SinhVienDaiHoc(int MSSV = 0, string HoTen = "", string DiaChi = "", int TongSoTinChi = 0, float DTB = 0, string TenLuanVan = "", float DiemLuanVan = 0)
	{
		this->MSSV = MSSV;
		this->HoTen = HoTen;
		this->DiaChi = DiaChi;
		this->TongSoTinChi = TongSoTinChi;
		this->DTB = DTB;
		this->TenLuanVan = TenLuanVan;
		this->DiemLuanVan = DiemLuanVan;
	}
	~SinhVienDaiHoc() {};
	void Nhap();
	void Xuat();
	bool XetTotNghiep();
	float getDTB();
};
class SinhVienCaoDang
{
private:
	string MSSV;
	string HoTen;
	string DiaChi;
	int TongSoTinChi;
	float DTB;
	float DiemThiTotNghiep;
public:
	SinhVienCaoDang(int MSSV = 0, string HoTen = "", string DiaChi = "", int TongSoTinChi = 0, float DTB = 0, float DiemThiTotNgiep=0) 
	{
		this->MSSV = MSSV;
		this->HoTen = HoTen;
		this->DiaChi = DiaChi;
		this->TongSoTinChi = TongSoTinChi;
		this->DTB = DTB;
		this->DiemThiTotNghiep = DiemThiTotNghiep;
	};
	~SinhVienCaoDang() {};
	void Nhap();
	void Xuat();
	bool XetTotNghiep();
};
int main()
{
	//
	int SoLuongSinhVienCaoDang;
	int SoLuongSinhVienDaiHoc;
	cout << "Nhap vao so luong sinh vien cao dang:";
	cin >> SoLuongSinhVienCaoDang;
	cout << "Nhap vao so luong sinh vien dai hoc:";
	cin >> SoLuongSinhVienDaiHoc;
	SinhVienCaoDang* a=new SinhVienCaoDang[SoLuongSinhVienCaoDang];
	SinhVienDaiHoc* b=new SinhVienDaiHoc[SoLuongSinhVienDaiHoc];
	int SoluongSinhVien=SoLuongSinhVienCaoDang+SoLuongSinhVienDaiHoc;
	int m=0, n=0;
	cout << "Nhap vao thong tin cac sinh vien cao dang"<<endl;
	for (int i = 0; i < SoLuongSinhVienCaoDang; i++)
		a[i].Nhap();
	cout << "Nhap vao thong tin cac sinh vien dai hoc" << endl;
	for (int i = 0; i < SoLuongSinhVienDaiHoc; i++)
		b[i].Nhap();

	//
	for (int i = 0; i < SoLuongSinhVienCaoDang; i++)
		a[i].Xuat();
	for (int i = 0; i < SoLuongSinhVienDaiHoc; i++)
		b[i].Xuat();

	//
	int dem=0;
	for (int i = 0; i < SoLuongSinhVienCaoDang; i++)
		if (a[i].XetTotNghiep()) dem++;
	for (int i = 0; i < SoLuongSinhVienDaiHoc; i++)
		if (b[i].XetTotNghiep()) dem++;
	cout << "So luong sinh vien tot nghiep la:" << dem;

	//
	float diemCaoNhat = b[0].getDTB();
	int index = 0;
	for (int i = 1; i < SoLuongSinhVienDaiHoc; i++)
		if (b[i].getDTB() > diemCaoNhat)
		{
			diemCaoNhat = b[i].getDTB();
			index = i;
		}

	cout << "\nDiem trung binh cua sinh vien dai hoc cao nhat la:" << diemCaoNhat<<endl;
	cout << "Sinh vien do la:"<<endl;
	b[index].Xuat();


		
}
void SinhVienDaiHoc::Nhap()
{
	cin.ignore();
	cout << "Nhap thong tin Sinh vien:" << endl;
	cout << "Nhap ma so sinh vien:";
	getline(cin, MSSV);
	cout << "Nhap ho va ten:";
	getline(cin, HoTen);
	cout << "Nhap dia chi:";
	getline(cin, DiaChi);
	cout << "Nhap diem trung binh:";
	cin >> DTB;
	cout << "Nhap tong so tin chi:";
	cin >> TongSoTinChi;
	cout << "Nhap ten luan van:";
	cin >> TenLuanVan;
	cout << "Nhap diem bai luan van:";
	cin >> DiemLuanVan;
}
void SinhVienDaiHoc::Xuat()
{
	cout << "--Thong tin sinh vien--" << endl;
	cout << "MSSV:" << MSSV << endl;
	cout << "Hoten:" << HoTen << endl;
	cout << "Dia chi:" << DiaChi << endl;
	cout << "Tong so tin chi:" << TongSoTinChi << endl;
	cout << "Diem trung binh:" << DTB << endl;
	cout<<"Ten luan van:"<<TenLuanVan << endl;
	cout << "Diem luan van:" << DiemLuanVan<<endl;

}
bool SinhVienDaiHoc::XetTotNghiep()
{
	if (TongSoTinChi >= 150 && DTB >= 5 && DiemLuanVan >= 5)
		return true;
	else
		return false;
}
float SinhVienDaiHoc::getDTB()
{
	return DTB;
}

void SinhVienCaoDang::Nhap()
{
	cin.ignore();
	cout << "Nhap thong tin Sinh vien:" << endl;
	cout << "Nhap ma so sinh vien:";
	getline(cin, MSSV);
	cout << "Nhap ho va ten:";
	getline(cin, HoTen);
	cout << "Nhap dia chi:";
	getline(cin, DiaChi);
	cout << "Nhap diem trung binh:";
	cin >> DTB;
	cout << "Nhap tong so tin chi:";
	cin >> TongSoTinChi;
	cout << "Nhap diem tot nghiep:";
	cin >> DiemThiTotNghiep;
}
void SinhVienCaoDang::Xuat()
{
	cout << "--Thong tin sinh vien--" << endl;
	cout << "MSSV:" << MSSV << endl;
	cout << "Hoten:" << HoTen << endl;
	cout << "Dia chi:" << DiaChi << endl;
	cout << "Tong so tin chi:" << TongSoTinChi << endl;
	cout << "Diem trung binh:" << DTB << endl;
	cout << "Diem thi tot nghiep:" << DiemThiTotNghiep << endl;
}
bool SinhVienCaoDang::XetTotNghiep()
{
	if (TongSoTinChi >= 120 && DTB >= 5 && DiemThiTotNghiep >= 5)
		return true;
	else
		return false;
}
