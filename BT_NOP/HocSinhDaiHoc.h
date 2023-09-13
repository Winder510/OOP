#pragma once
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

