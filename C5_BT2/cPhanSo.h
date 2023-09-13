#pragma once
class PhanSo
{
private:
	int tuso;
	int mauso;
public:
	PhanSo(int t = 0, int m = 0) : tuso(t), mauso(m) {};
	PhanSo(const PhanSo& p);
	{
		tuso = p.tuso;
		mauso = p.mauso;
	}
	int getTu();
	int getMau();
	void GanTu();
	void GanMau();
	void Nhap();
	void Xuat();
	bool operator>(PhanSo);
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
};
