#include<iostream>
using namespace std;
class VuKhi
{
protected:
	string tenSung;
	int KichThuocbangDan;
	float SatThuong;
	float TocDoBan;
	int slBangDan=0;
	float doHaoMon=0;
public:
	VuKhi(string ts="",int ktbd=0,float st=0, float tdb=0):
		tenSung(ts),KichThuocbangDan(ktbd),SatThuong(st),TocDoBan(tdb){}
	virtual void Nhap()
	{
		cin >> slBangDan>>doHaoMon;
	}
	void Xuat()
	{
		cout << tenSung << " " << KichThuocbangDan << " " << SatThuong << " " << TocDoBan;
	}
	virtual void DieuChinh() 
	{
		if (doHaoMon >= 1) return;
		else
		{
			SatThuong = SatThuong * doHaoMon;
			TocDoBan = TocDoBan / 2;
		}
	}
	float TinhDam(float tg)
	{
		int delay=0;
		if (getTen() == "AWM" || getTen() == "SVD")
		{
			delay = 1;
		}
		float satThuongTong = 0;
		int soVienDaBan = 0;
		float thoiGianDaTruoc = 0;
		for(int i=0;i<slBangDan;i++)
		{
			while ((thoiGianDaTruoc < tg) )
			{
				if ((soVienDaBan >= KichThuocbangDan))
				{
					thoiGianDaTruoc += 2;
					soVienDaBan = 0;
					break;
				}
				satThuongTong += SatThuong;
				soVienDaBan++;

				if (soVienDaBan <= KichThuocbangDan) {
					thoiGianDaTruoc += (float)(1.0 / TocDoBan)+delay;
				}
				
			}
		}
		return satThuongTong;
	}
	string getTen()
	{
		return tenSung;
	}
};
//
class SungNgan :public VuKhi
{
public:
	SungNgan(string ts = "", int ktbd = 0, float st = 0, float tdb = 0)
		: VuKhi(ts, ktbd, st, tdb) {}

};
class G18 : public SungNgan
{
public:
	G18(string ts = "G18", int ktbd = 12, float st = 2, float tdb = 1)
		:SungNgan(ts,ktbd,st,tdb){}
};
class M500 :public SungNgan
{
public:
	M500(string ts = "M500", int ktbd = 5, float st = 4, float tdb = 0.5)
		:SungNgan(ts, ktbd, st, tdb) {}
};


//
class SungTruong :public VuKhi
{
protected:
	int TangDame=0;
public:
	SungTruong(string ts = "", int ktbd = 0, float st = 0, float tdb = 0)
		: VuKhi(ts, ktbd, st, tdb) {}
	void Nhap()
	{
		VuKhi::Nhap();
		cin >> TangDame;
	}
	void DieuChinh()
	{
		VuKhi::DieuChinh();
		SatThuong += TangDame; 
	}
};
class MP40 : public SungTruong
{
public:
	MP40(string ts = "MP40", int ktbd = 20, float st = 3, float tdb = 5)
		: SungTruong(ts, ktbd, st, tdb) {}
};
class AK : public SungTruong
{
public:
	AK(string ts = "AK", int ktbd = 30, int st = 5, float tdb = 1)
		: SungTruong(ts, ktbd, st, tdb) {}
};

//
class SungBanTia :public VuKhi
{
protected: 
	int delay = 1;
public:
	SungBanTia(string ts = "", int ktbd = 0, float st = 0, float tdb = 0)
		: VuKhi(ts, ktbd, st, tdb) {}
	void DieuChinh()
	{
		VuKhi::DieuChinh();
		//TocDoBan -= delay;
	}
};
class SVD : public SungBanTia
{
public:
	SVD(string ts = "SVD", int ktbd = 10, float st = 5, float tdb = 0.5)
		: SungBanTia(ts, ktbd, st, tdb) {}
};
class AWM :public SungBanTia
{
public:
	AWM(string ts = "AWM", int ktbd = 5, float st = 10, float tdb = 0.5)
		: SungBanTia(ts, ktbd, st, tdb) {}
};



class DsSung
{
private:
	int n;
	VuKhi* ds[100];
public:
	void Nhap()
	{
		cin >> n;
			int loai;
		for (int i = 0; i < n; i++)
		{
			cin >> loai;
			if (loai == 1) ds[i] = new G18;
			else if (loai == 2) ds[i] = new M500;
			else if (loai == 3) ds[i] = new MP40;
			else if (loai == 4) ds[i] = new AK;
			else if (loai == 5) ds[i] = new SVD;
			else if (loai == 6) ds[i] = new AWM;
			ds[i]->Nhap();
			ds[i]->DieuChinh();
		}
	}
	void TinhDame(float tg)
	{
		for (int i = 0; i < n; i++)
		{
			cout << ds[i]->getTen() << ": " << ds[i]->TinhDam(tg) << endl;
		}
	}
};
int main()
{
	DsSung ar;
	ar.Nhap();
	float tg;
	cin >> tg;
	ar.TinhDame(tg);
}