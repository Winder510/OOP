#include<iostream>
using namespace std;
class NhomMau
{
protected:
	string Rh;
public:
	void Nhap()
	{
		cout << "Nhap Rh(+ hoac -): ";
		cin >> Rh;
	}
	virtual void Xuat()
	{
		cout << Rh << " " << endl;
	}
	virtual string PhanLoai() = 0;
	virtual bool KiemTraDiTruyen(NhomMau* me,NhomMau* cha)=0;
	virtual bool NhanMau(NhomMau* nguoicho) = 0;
	virtual string getRh()
	{
		return Rh;
	}
};
class A:public NhomMau
{
public:
	void Xuat()
	{
		cout << "A";
		NhomMau::Xuat();
	}
	string PhanLoai()
	{
		return "A";
	}
	bool KiemTraDiTruyen(NhomMau* me, NhomMau* cha)
	{
		string Me = me->PhanLoai();
		if (Me == "A" || Me == "AB")
			return true;
		return false;

	}
	bool NhanMau(NhomMau* nguoicho)
	{
		//A-
		if(getRh()=="-")
		{
			if (nguoicho->PhanLoai() == "A" || nguoicho->PhanLoai() == "O")
			{
				if (nguoicho->getRh() == "-")
					return true;
			}
		}
		else //A+
		{
			if (nguoicho->PhanLoai() == "A" || nguoicho->PhanLoai() == "O")
				return true;
		}
		return false;

	}

};
class B :public NhomMau
{
public:
	void Xuat()
	{
		cout << "B";
		NhomMau::Xuat();
	}
	string PhanLoai()
	{
		return "B";
	}
	bool KiemTraDiTruyen(NhomMau* me, NhomMau* cha)
	{
		string Me = me->PhanLoai();
		if (Me == "B" || Me == "AB")
			return true;
		return false;
	}
	bool NhanMau(NhomMau* nguoicho)
	{
		//B-
		if (getRh() == "-")
		{
			if (nguoicho->PhanLoai() == "O" || nguoicho->PhanLoai() == "B")
			{
				if (nguoicho->getRh() == "-")
					return true;
			}
		}
		else //B+
		{
			if (nguoicho->PhanLoai() == "O" || nguoicho->PhanLoai() == "B")
				return true;
		}
		return false;

	}
};
class AB :public NhomMau
{
public:
	void Xuat()
	{
		cout << "AB";
		NhomMau::Xuat();
	}
	string PhanLoai()
	{
		return "AB";
	}
	bool KiemTraDiTruyen(NhomMau* me, NhomMau* cha)
	{
		string Me = me->PhanLoai();
		string Cha = cha->PhanLoai();
		if (Me == "B" && Cha != "B" && Cha != "O")
			return true;
		if (Me == "AB" && Cha != "O")
			return true;
		return false;
	}
	bool NhanMau(NhomMau* nguoicho)
	{
		//AB-
		if (getRh() == "-")
		{
			if (nguoicho->getRh() == "-")
				return true;
			
		}
		else //AB+
		{
			return true;
		}
		return false;

	}

};
class O :public NhomMau
{
public:
	void Xuat()
	{
		cout << "O";
		NhomMau::Xuat();
	}
	string PhanLoai()
	{
		return "O";
	}
	bool KiemTraDiTruyen(NhomMau* me, NhomMau* cha)
	{
		string Me = me->PhanLoai();
		if (Me !="AB")
			return true;
		return false;
	}
	bool NhanMau(NhomMau* nguoicho)
	{
		//O-
		if (getRh() == "-")
		{
			if ( nguoicho->PhanLoai() == "O"&& nguoicho->getRh() == "-")
			{
					return true;
			}
		}
		else //O+
		{
			if (nguoicho->PhanLoai() == "O")
				return true;
		}
		return false;

	}
};
class DSMau
{
private:
	int n;
	NhomMau* ds[100];
public:
	friend istream& operator>>(istream& is, DSMau& dsmau)
	{
		cout << "Nhap so nguoi:";
		is >> dsmau.n;
		cout << "Nhap tung nguoi:" << endl;
		for (int i = 0; i < dsmau.n; i++)
		{
			cout << "Nhap nhom mau: ";
			string loai;
			is >> loai;
			if (loai == "A") dsmau.ds[i] = new A;
			if (loai == "B") dsmau.ds[i] = new B;
			if (loai == "AB") dsmau.ds[i] = new AB;
			if (loai == "O") dsmau.ds[i] = new O;	
			dsmau.ds[i]->Nhap();
		}
		return is;
	}
	void Nhap()
	{
		
	}
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Nguoi thu " << i  << ": ";
			ds[i]->Xuat();
		}
	}
	bool XetDiTruyen()
	{
		bool check1 = ds[2]->KiemTraDiTruyen(ds[1], ds[0]);
		bool check2 = ds[2]->KiemTraDiTruyen(ds[0], ds[1]);
		if (check1 && check2)
			return true;
		return false;
	}
	void dsChoMau()
	{
		int i;
		cout << "Chon nguoi thu: ";
		cin >> i;
		cout << "Nhung nguoi co the nhan mau:"<<endl;
		for (int j = 0; i < n; j++)
		{
			if (i != j)
			{
				if (ds[j]->NhanMau(ds[i]))
					cout << "Nguoi thu " << j << ": " << ds[j]->PhanLoai() << ds[j]->getRh()<<endl;
			}
		}
	}

};
int main()
{
	// cau a
	DSMau kq;
	cin >> kq;
	kq.Xuat();


	// Cau b
	DSMau p;
	cin >> p;
	cout << "Ket qua di truyen: " << (p.XetDiTruyen() ? "Dung" : "Sai");

	//Cau c
	kq.dsChoMau();

}