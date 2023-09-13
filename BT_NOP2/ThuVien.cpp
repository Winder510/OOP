#include<iostream>
#include<string>
using namespace std;
class SachGiaoKhoa
{
private:
	string MaSach;
	string TenSach;
	string NhaXuatBan;
	int SoLuong;
	float DonGia;
	bool TinhTrang;
public:
	SachGiaoKhoa(string MaSach = "", string TenSach = "", string NhaXuatBan = "", int SoLuong = 0, float DonGia = 0, int TinhTang = -1)
	{
		this->MaSach = MaSach;
		this->TenSach = TenSach;
		this->NhaXuatBan = NhaXuatBan;
		this->SoLuong = SoLuong;
		this->DonGia = DonGia;
		this->TinhTrang = TinhTrang;
	}
	~SachGiaoKhoa() {};
	void Nhap();
	void Xuat();
	float TinhTien();
	string getNXB();
};
class SachThamKhao
{
private:
	string MaSach;
	string TenSach;
	string NhaXuatBan;
	int SoLuong;
	float DonGia;
	int TienThue;
public:
	SachThamKhao(string MaSach = "", string TenSach = "", string NhaXuatBan = "", int SoLuong = 0, float DonGia = 0, int TienThue = 0)
	{
		this->MaSach = MaSach;
		this->TenSach = TenSach;
		this->NhaXuatBan = NhaXuatBan;
		this->SoLuong = SoLuong;
		this->DonGia = DonGia;
		this->TienThue = TienThue;
	}
	~SachThamKhao(){};
	void Nhap();
	void Xuat();
	float TinhTien();
};
int main()
{
	//
	int SoluongSachGiaoKhoa;
	int SoluongSachThamKhao;
	cout << "Nhap so luong sach giao khoa:";
	cin >> SoluongSachGiaoKhoa;
	cout << "Nhap so luong sach tham khao:";
	cin >> SoluongSachThamKhao;
	SachThamKhao* TK = new SachThamKhao[SoluongSachThamKhao];
	SachGiaoKhoa* GK = new SachGiaoKhoa[SoluongSachGiaoKhoa];
	cout << "---- Nhap vao danh sach cac sach giao khoa ----" << endl;
	for (int i = 0; i < SoluongSachGiaoKhoa; i++)
		GK[i].Nhap();
	cout << "---- Nhap vao danh sach cac sach tham khao ----" << endl;
	for(int i=0;i<SoluongSachThamKhao;i++)
		TK[i].Nhap();

	//
	cout << "---- Danh sach SACH GIAO KHOA ----\n";
	for (int i = 0; i < SoluongSachGiaoKhoa; i++)
		GK[i].Xuat();
	cout << "---- DANH SACH SACH THAM KHAO ----\n";
	for (int i = 0; i < SoluongSachThamKhao; i++)
		TK[i].Xuat();


	//
	float TongTienSGK = 0;
	int index = 0;
	int minSGK = GK[0].TinhTien();
	for (int i = 0; i < SoluongSachGiaoKhoa; i++)
	{
		TongTienSGK += GK[i].TinhTien();
	}
	for (int i = 1; i < SoluongSachGiaoKhoa; i++)
	{
		if (minSGK > GK[i].TinhTien())
		{
			minSGK = GK[i].TinhTien();
			index = i;
		}
	}
	cout << "So tien phai tra cho sach giao khoa la:"<<TongTienSGK;
	cout << "\nSach giao khoa co so tien it nhat la:"<<endl;
	for (int i = 0; i < SoluongSachGiaoKhoa; i++)
	{
		GK[index].Xuat();
	}
	float TongTienSTK = 0;
	 index = 0;
	int minSTK = TK[0].TinhTien();
	for (int i = 0; i < SoluongSachThamKhao; i++)
	{
		TongTienSTK +=TK[i].TinhTien();
	}
	for (int i = 1; i < SoluongSachThamKhao; i++)
	{
		if (minSTK > TK[i].TinhTien())
		{
			minSTK = TK[i].TinhTien();
			index = i;
		}
	}
	cout << "So tien phai tra cho sach tham khao la:" << TongTienSTK;
	cout << "\nSach giao khoa co so tien it nhat la:" << endl;
	for (int i = 0; i < SoluongSachThamKhao; i++)
	{
		TK[index].Xuat();
	}


	//
	string tenNhaXuatBan;
	cout << "Nhap ten nha xuat ban muon tim : " << endl;
	cin >> tenNhaXuatBan;
	bool check = 0;
	for (int i = 0; i <SoluongSachGiaoKhoa ; i++)
	{
		if (GK[i].getNXB() == tenNhaXuatBan)
		{
			GK[i].Xuat();
			check = 1;
		}
	}
	if (!check) cout << "\nKhong co nha ban nay";

}
void SachGiaoKhoa::Nhap()
{
	cin.ignore();
	cout << "---- Nhap thong tin cua sach ----"<<endl;
	cout << "Nhap ma sach:";
	getline(cin, MaSach);
	cout << "Nhap ten sach:";
	getline(cin, TenSach);
	cout << "Nhap nha xuat ban:";
	getline(cin, NhaXuatBan);
	cout << "Nhap so luong:";
	cin >> SoLuong;
	cout << "Nhap don gia:";
	cin >> DonGia;
	cout << "Nhap tinh trang cua sach (0:Cu, 1:Moi) :";
	cin >> TinhTrang;
}
void SachGiaoKhoa::Xuat()
{
	cout << "-- Thong tin sach --" << endl;
	cout << "Ma sach:" << MaSach << endl;
	cout << "Ten sach:" << TenSach << endl;
	cout << "Nha xuat ban:" << NhaXuatBan << endl;
	cout << "So luong:" << SoLuong << endl;
	cout << "Don gia:" << DonGia << endl;
	cout << "Tinh trang:" <<(TinhTrang? "Moi" : "Cu")<<endl;
}
float SachGiaoKhoa::TinhTien()
{
	if (TinhTrang == 1)
		return SoLuong * DonGia;
	else
		return SoLuong * DonGia * 0.5;

}
string SachGiaoKhoa::getNXB()
{
	return NhaXuatBan;
}
void SachThamKhao::Nhap()
{
	cin.ignore();
	cout << "---- Nhap thong tin cua sach ----"<<endl;
	cout << "Nhap ma sach:";
	getline(cin, MaSach);
	cout << "Nhap ten sach:";
	getline(cin, TenSach);
	cout << "Nhap nha xuat ban:";
	getline(cin, NhaXuatBan);
	cout << "Nhap so luong:";
	cin >> SoLuong;
	cout << "Nhap don gia:";
	cin >> DonGia;
	cout << "Nhap tien thue:";
	cin >> TienThue;
}
void SachThamKhao::Xuat()
{
	cout << "-- Thong tin sach --" << endl;
	cout << "Ma sach:" << MaSach << endl;
	cout << "Ten sach:" << TenSach << endl;
	cout << "Nha xuat ban:" << NhaXuatBan << endl;
	cout << "So luong:" << SoLuong << endl;
	cout << "Don gia:" << DonGia << endl;
	cout << "Tien thue:" << TienThue << endl;
}
float SachThamKhao::TinhTien()
{
	return SoLuong * DonGia + TienThue;
}