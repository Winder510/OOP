#include<iostream>
using namespace std;
class Sim
{
protected:
	int serial;
	string MaNhaMang;
	int sdt;
	bool trangthai;
	float SoTienKhuyenMai;
public:
	virtual void Nhap()
	{
		cout << "Nhap so seri: ";
		cin >> serial;
		cout << "Nhap nha mang(+001: Verizon, +002: AT&T, +003: Sprint): ";
		cin >> MaNhaMang;
		cout << "Nhap so dien thoai(gom 9 so):";
		cin >> sdt;
		cout << "Trang thai(1: Actived hoặc 0: Non-actived): ";
		cin >> trangthai;
	}
	virtual void Xuat()
	{
		cout << serial << " " << MaNhaMang << " " << sdt << " " << ((trangthai == 1) ? "Actived" : "Non-actived") <<" ";
	}
	virtual void NapTien()
	{
		return;
	}
	virtual int KhuyenMai(int dem=0)=0 ;

	int getSoTienKhuyenMai()
	{
		return SoTienKhuyenMai;
	}
	string getMNM()
	{
		return MaNhaMang;
	}
	virtual int getSoNo()
	{
		return 0;
	}

};
class SimTraTruoc:public Sim
{
private:
	float soDu;
	int SoLanNapthe;
	
public:
	void Nhap()
	{
		Sim::Nhap();
		cout << "Nhap so du hien tai:";
		cin >> soDu;
		cout << "Nhap so lan nap the:";
		cin >> SoLanNapthe;
		for (int i = 0; i < SoLanNapthe; i++)
		{
			int a;
			cout << "Menh gia the thu " << i + 1 << ": ";
			cin >> a;
			soDu = soDu + a + (float)a * KhuyenMai(i + 1) / 100;
			SoTienKhuyenMai = (float)a * KhuyenMai(i + 1) / 100;
		}
	}
	void Xuat()
	{
		Sim::Xuat();
		cout << soDu << " " << SoLanNapthe<<" "<<endl;
	}
	int KhuyenMai(int dem=0)
	{
		if (dem < 5) return 10;
		if (dem >= 5 && dem <= 10) return 20;
		if (dem > 10) return 50;
	}
	
};
class SimTraSau :public Sim
{
private:
	string goiCuoc;
	float soGhiNo;
public:
	void Nhap()
	{
		Sim::Nhap();
		cout << "Nhap vao so ghi no ban dau: ";
		cin >> soGhiNo;
		cout << "Nhap vao goi cuocc (LCAP, MCAP và HCAP): ";
		cin >> goiCuoc;
		SoTienKhuyenMai = soGhiNo * KhuyenMai()/100;
		soGhiNo -= SoTienKhuyenMai;
	}
	void Xuat()
	{
		Sim::Xuat();
		cout << goiCuoc << " " << soGhiNo<<endl;
	}
	int KhuyenMai(int dem=0)
	{
		if (goiCuoc == "LCAP") return 5;
		if (goiCuoc == "MCAP") return 10;
		if (goiCuoc == "HCAP") return 15;
	}
	int getSoGhiNo()
	{
		return soGhiNo;
	}
};
class DaiLySim
{
private:
	int n;
	Sim* ds[100];
public:
	void Nhap()
	{
		cout << "Nhap vao so sim: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap vao loai sim(1-SimTraTruoc, 2-SimTraSau): ";
			int loai;
			cin >> loai;
			if (loai == 1)
			{
				ds[i] = new SimTraTruoc;
			}
			if (loai == 2)
			{
				ds[i] = new SimTraSau;
			}
			ds[i]->Nhap();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "So thu" << i<<": ";
			ds[i]->Xuat();
		}
	}
	int TongTienKhuyenMai()
	{
		int sum=0;
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->getMNM() == "+002")
				sum += ds[i]->getSoTienKhuyenMai();
		}
		return sum;
	}
	int MinSoGhiNo()
	{
		int min = ds[0]->getSoNo();
		for (int i = 1; i < n; i++)
		{
			if (ds[i]->getSoNo() < min)
				min = ds[i]->getSoNo();
		}
		return min;
	}
};
int main()
{
	DaiLySim p;
	p.Nhap();
	p.Xuat();
}