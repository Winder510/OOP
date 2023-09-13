#include<iostream>
#include<vector>
#include<map>
using namespace std;

class SanPham
{
protected:
	string maSo;
	string tieuDe;
	int giaBan;
public:
	virtual void Nhap()
	{
		cout << "Nhap vao ma so cua san pham: ";
		cin >> maSo;
		cout << "Nhap vao tieu de cua san pham: ";
		cin >> tieuDe;
		cout << "Gia ban cua san pham: ";
		cin >> giaBan;
	}
	virtual void Xuat()
	{
		cout << maSo << "\t" << tieuDe << "\t" << giaBan;
	}
	int getGiaBan()
	{
		return giaBan;
	}

};
class TranhAnh :public SanPham
{
private:
	int chieuRong;
	int chieuCao;
	string tenHoaSi;
public:
	void Nhap()
	{
		SanPham::Nhap();
		cout << "Nhap vao chieu rong cua buc tranh: ";
		cin >> chieuRong;
		cout << "Nhap vao chieu cao cua buc tranh: ";
		cin >> chieuCao;
		cout << "Nhap ten hoa si: ";
		cin >> tenHoaSi;
	}
	void Xuat()
	{
		SanPham::Xuat();
		cout << chieuCao << "\t" << chieuRong << "\t" << tenHoaSi;
	}
};
class CD :public SanPham
{
private:
	string tenCaSi;
	string DonViSanXuat;
public:
	void Nhap()
	{
		cout << "Nhap vao ten ca si: ";
		cin >> tenCaSi;
		cout << "Nhap don vi san xuat: ";
		cin >> DonViSanXuat;
	}
	void Xuat()
	{
		SanPham::Xuat();
		cout << tenCaSi << "\t" << DonViSanXuat;
	}
};
class KhachHang
{
private:
	string maKH;
	string tenKH;
	string sdt;
public:
	void Nhap()
	{
		cout << "Nhap ma khach hang: ";
		cin >> maKH;
		cout << "Nhap ten khach hang: ";
		cin >> tenKH;
		cout << "Nhap vao so dien thoai: ";
		cin >> sdt;
	}
	void Xuat()
	{
		cout << "Ma: " << maKH;
		cout << "\nTen khach hang: " << tenKH;
		cout << "\n So dien thoai: " << sdt;
	}
};


class HoaDon
{
private:
	string maHD;
	KhachHang c;
	vector<SanPham*> p;
	long TongGia;
public:
	void Nhap()
	{
		int n;
		SanPham* tmp;
		int loai;
		cout << "Nhap vao ma hoa don: ";
		cin >> maHD;
		c.Nhap();
		cout << "Nhap vao so san pham: ";
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			tmp = NULL;
			cout << "Nhap vao san pham(1-TranhAnh,2-Dia CD): ";
			cin >> loai;
			if (loai == 1) tmp = new TranhAnh;
			else tmp = new CD;
			tmp->Nhap();
			p.push_back(tmp);
		}
		TongGia = TinhThanhTien();
	}
	int TinhThanhTien()
	{
		int sum = 0;
		for (int i = 0; i < p.size(); i++)
		{
			sum += p[i]->getGiaBan();
		}
		return sum;
	}
	void Xuat()
	{
		cout << "Ma hoa don:" << "\t" << maHD;
		cout << "Thong tin khach hang: " << "\t"; c.Xuat();
		cout << "Danh sach san pham: " << endl;
		cout << "\t";
		for (int i = 0; i < p.size(); i++)
		{
			p[i]->Xuat();
		}
		cout << "Tong hoa don: " << "\t" << TongGia << endl;
	}
	long getTongGia()
	{
		return TongGia;
	}
	KhachHang getKhachHang()
	{
		return c;
	}
};
class DsHoaDon
{
private:
	vector<HoaDon*> ds;
public:
	void Nhap()
	{
		cout << "Nhap vao so luong hoa don: ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			ds[i]->Nhap();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < ds.size(); i++)
			ds[i]->Xuat();
	}
	long TinhDoanhThu()
	{
		long sum = 0;
		for (int i = 0; i < ds.size(); i++)
			sum += ds[i]->getTongGia();
		return sum;
	}
	KhachHang MaxTien()
	{
		map<KhachHang, long> mp;
		for (int i = 0; i < ds.size(); i++)
		{
			mp[ds[i]->getKhachHang()] += ds[i]->getTongGia();
		}
		KhachHang maxKH;
		long maxTotal = 0;

		for (auto it : mp)
		{
			if (it.second > maxTotal)
			{
				maxTotal = it.second;
				maxKH = it.first;
			}
		}

		return maxKH;
	}

};
int main()
{
	DsHoaDon ds;
	ds.Nhap();
	ds.Xuat();
	cout << "Doanh thu: " << ds.TinhDoanhThu();
	ds.MaxTien().Xuat();
}