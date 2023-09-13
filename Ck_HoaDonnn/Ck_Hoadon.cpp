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
		cout << "Ma so san pham: " << maSo;
		cout << "\nTieu de san pham: " << tieuDe;
		cout << "\nGia ban: " << giaBan;
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
		cout << "\nChieu rong: " << chieuRong;
		cout << "\nChieu cao: " << chieuCao;
		cout << "\nTen hoa si: " << tenHoaSi;
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
		SanPham::Nhap();
		cout << "Nhap vao ten ca si: ";
		cin >> tenCaSi;
		cout << "Nhap don vi san xuat: ";
		cin >> DonViSanXuat;
	}
	void Xuat()
	{
		SanPham::Xuat();
		cout << "\nTen ca si: " << tenCaSi;
		cout << "\nDon vi san xuat: " << DonViSanXuat;
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
		cout << "\nSo dien thoai: " << sdt;
	}
	string getMaKH()
	{
		return maKH;
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
	long TinhThanhTien()
	{
		long sum = 0;
		for (int i = 0; i < p.size(); i++)
		{
			sum += p[i]->getGiaBan();
		}
		return sum;
	}
	void Xuat()
	{
		cout << "Ma hoa don:" << maHD;
		cout << "Thong tin khach hang: "; c.Xuat();
		cout << "\nDanh sach san pham: " << endl;
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
	string getMaKH()
	{
		return c.getMaKH();
	}
};
class DsHoaDon
{
private:
	vector<HoaDon> ds;
public:
	void Nhap()
	{
		int n;
		cout << "Nhap vao so luong hoa don: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap vao hoa don thu " << i + 1 << endl;
			HoaDon tmp;
			tmp.Nhap();
			ds.push_back(tmp);
		}
	}
	void Xuat()
	{
		for (int i = 0; i < ds.size(); i++)
		{
			cout << "Hoa don thu " << i + 1 << endl;
			ds[i].Xuat();
		}
	}
	long TinhDoanhThu()
	{
		long sum = 0;
		for (int i = 0; i < ds.size(); i++)
			sum += ds[i].getTongGia();
		return sum;
	}
	vector<string> MaxTien()
	{
		vector<string> kq;
		map<string, long> mp;
		for (int i = 0; i < ds.size(); i++)
		{
			mp[ds[i].getMaKH()] += ds[i].getTongGia();
		}
		long maxTotal = 0;

		for (const auto& it : mp)
		{
			if (it.second > maxTotal)
			{
				maxTotal = it.second;
			}
		}

		for (auto it : mp)
		{
			if (it.second == maxTotal)
				kq.push_back(it.first);
		}
		return kq;
	}

};
int main()
{
	DsHoaDon ds;
	ds.Nhap();
	ds.Xuat();
	// cau b
	cout << "Doanh thu cua cua hang: " << ds.TinhDoanhThu();
	// cau c
	cout << "\nID cua cac khach hang mua nhieu nhat la: ";
	vector<string> kq = ds.MaxTien();
	for (int i = 0; i < kq.size(); i++)
		cout << kq[i] << " ";

}