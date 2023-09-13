#pragma once
class DonThuc
{
private:
	int heso;
	int somu;
public:
	//DonThuc();
	//DonThuc(int a, int b);
	void Nhap();
	void setHeso(int a);
	void setSomu(int a);
	void Xuat();
	int Tinh_GiaTri_tai(int x);
	DonThuc DaoHam();
	DonThuc CongDonThuc(DonThuc d);
	~DonThuc();
};

