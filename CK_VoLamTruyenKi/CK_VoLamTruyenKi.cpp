#include<iostream>
using namespace std;
class He
{
protected:
	string MonPhai;
public:
	virtual void Nhap() = 0;
	virtual string getHe() = 0;
	string getMonPhai()
	{
		return MonPhai;
	}
	virtual int TLSatThuong(He* h) = 0;
};
class Kim :public He
{
public:
	void Nhap()
	{
		cout << "Nhap vao mon phai(0-ThieuLam,1-ThienVuongBang): ";
		int loai;
		cin >> loai;
		if (loai == 0) MonPhai = "Thieu Lam";
		if (loai == 1) MonPhai = "Thien Vuong Bang";
		
	}
	string getHe()
	{
		return "Kim";
	}
	int TLSatThuong(He* h)
	{
		if (h->getHe() == "Tho") return 10;
		if (h->getHe() == "Moc") return 20;
		if (h->getHe() == "Hoa") return -20;
		return 0;
	}
};
class Moc :public He
{
public:
	void Nhap()
	{
		cout << "Nhap vao mon phai(0-Ngu Doc Giao,1-Duong Mon): ";
		int loai;
		cin >> loai;
		if (loai == 0) MonPhai = "Ngu Doc Giao";
		if (loai == 1) MonPhai = "Duong Mon";

	}
	string getHe()
	{
		return "Moc";
	}
	int TLSatThuong(He* h)
	{
		if (h->getHe() == "Hoa") return 10;
		if (h->getHe() == "Tho") return 20;
		if (h->getHe() == "Kim") return -20;
		return 0;
	}
};
class Thuy :public He
{
public:
	void Nhap()
	{
		cout << "Nhap vao mon phai(0-Nga My,1-Thuy Yen Mon): ";
		int loai;
		cin >> loai;
		if (loai == 0) MonPhai = "Nga My";
		if (loai == 1) MonPhai = "Thuy Yen Mon";

	}
	string getHe()
	{
		return "Thuy";
	}
	int TLSatThuong(He* h)
	{
		if (h->getHe() == "Moc") return 10;
		if (h->getHe() == "Hoa") return 20;
		if (h->getHe() == "Tho") return -20;
		return 0;
	}
};
class Hoa :public He
{
public:
	void Nhap()
	{
		cout << "Nhap vao mon phai(0-Cai Bang,1-Thien Nhan Giao): ";
		int loai;
		cin >> loai;
		if (loai == 0) MonPhai = "Cai Bang";
		if (loai == 1) MonPhai = "Thien Nhan Giao";

	}
	string getHe()
	{
		return "Hoa";
	}
	int TLSatThuong(He* h)
	{
		if (h->getHe() == "Tho") return 10;
		if (h->getHe() == "Kim") return 20;
		if (h->getHe() == "Thuy") return -20;
		return 0;
	}
};
class Tho :public He
{
public:
	void Nhap()
	{
		cout << "Nhap vao mon phai(0-ConLon,1-VoDang): ";
		int loai;
		cin >> loai;
		if (loai == 0) MonPhai = "Con Lon";
		if (loai == 1) MonPhai = "Vo Dang";

	}
	string getHe()
	{
		return "Tho";
	}
	int TLSatThuong(He* h)
	{
		if (h->getHe() == "Kim") return 10;
		if (h->getHe() == "Thuy") return 20;
		if (h->getHe() == "Moc") return -20;
		return 0;
	}
};
class PhanTu
{
protected:
	int capdo;
	He* he;
public:
	void Nhap()
	{
		cout << "Nhap vao cap do:"; cin >> capdo;
		cout << "Nhap vao he(0-kim,1-Moc,2-Thuy,3-Hoa,4-Tho):";
		int loai;
		cin >> loai;
		switch (loai)
		{
		case 0: {he = new Kim; break; }
		case 1: {he = new Moc; break; }
		case 2: {he = new Thuy; break; }
		case 3: {he = new Hoa; break; }
		case 4: {he = new Tho; break; }
		}
		he->Nhap();
	}
	void Xuat()
	{
		cout <<getTen()<<" "<<capdo << " " << he->getHe() << " " << he->getMonPhai() << endl;
	}
	virtual string getTen()
	{
		return "";
	}
	virtual float MucSatThuong() = 0;
	float SatThuong(PhanTu* p)
	{
		float mst = MucSatThuong();
		return mst + mst * he->TLSatThuong(p->getHe())/100;
	}
	He* getHe()
	{
		return he;
	}
};
class NhanVat:public PhanTu
{
public:
	string getTen()
	{
		return "Nhan Vat";
	}
	float MucSatThuong()
	{
		return capdo * 5;
	}
};
class QuaiVat :public PhanTu
{
};
class QVThuong :public QuaiVat
{
public:
	string getTen()
	{
		return "Quai vat thuong";
	}
	float MucSatThuong()
	{
		return  capdo * 3;
	}
};
class QVDauLinh :public QuaiVat
{
public:
	string getTen()
	{
		return "Quai vat dau linh";
	}
	float MucSatThuong()
	{
		return  capdo * 7;
	}
};
class DSPhanTu
{
private:
	int n;
	PhanTu* ds[100];
public:
	void Nhap()
	{
		cout << "Nhap vao so phan tu:"; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int loai;
			cout << "Nhap vao loai phan tu(0-Nhan Vat,1-QVThuong,2-QVDauLinh): ";
			cin >> loai;
			switch (loai)
			{
			case 0: {ds[i] = new NhanVat; break; }
			case 1: {ds[i] = new QVThuong; break; }
			case 2: {ds[i] = new QVDauLinh; break; }
			}
			ds[i]->Nhap();
		}
	
	}
	void Xuat()
	{	
		for (int i = 0; i < n; i++)
		{
			ds[i]->Xuat();
		}
	}
	void MaxSatThuong()
	{
		float max = ds[0]->MucSatThuong();
		for (int i = 1; i < n; i++)
		{
			if (ds[i]->MucSatThuong() > max)
				max = ds[i]->MucSatThuong();
		}
		cout << "Nhung phan tu co muc sat thuong lon nhat la: ";
		for (int i = 0; i < n; i++)
			if (max == ds[i]->MucSatThuong())
				cout << i << " ";
	}
	void SatThuong()
	{
		cout << "Sat thuong A tac dong len B: ";
		cout << ds[0]->SatThuong(ds[1]);
		cout << "\nSat thuong B tac dong len A: ";
		cout<< ds[1]->SatThuong(ds[0]);
	}
};
int main()
{
	// cau a
	DSPhanTu arr;
	arr.Nhap();
	arr.Xuat();

	// cau b
	arr.MaxSatThuong();

	// cau c
	DSPhanTu arr1;
	cout << "\nPhai nhap so phan tu bang 2"<<endl;
	arr1.Nhap(); // n=2
	arr1.SatThuong();
}