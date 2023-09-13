#pragma once
#include"DonThuc.h";
class Dathuc
{
private:
	DonThuc* arr;
	int bac;
public:
	Dathuc(int n=0 )
	{
		this->bac = n;
		this->arr = new DonThuc[bac+1];
	}
	Dathuc(const Dathuc& q)
	{
		this->bac = q.bac;
		this->arr = new DonThuc[bac+1];
		for (int i = 0; i <= bac; i++)
			this->arr[i] = q.arr[i];
	}
	void Nhap();
	void Xuat();
	int Tinh_Tai(int x);
	Dathuc Cong_DaThuc(const Dathuc&);
	Dathuc Tru_DaThuc(const Dathuc&);
	~Dathuc();
};

