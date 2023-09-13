#include<iostream>
#include<vector>
using namespace std;
class DoiTuong
{
protected:
    string ten;
    int tuoi;
    int sdt;
    string cachchet;
public:
    int loai;
    virtual void Nhap()
    {
        cin >> ten >> tuoi >> sdt;
    }
    string getTen()
    {
        return ten;
    }
    virtual void CachChet()
    {
        return;
    }
    virtual string getCV()
    {
        return "";
    }
    virtual float getTaiSan() {
        return 0;
    }
    string getCachChet()
    {
        return cachchet;
    }
    virtual int getNamTu()
    {
        return 0;
    }
};
class ChinhTriGia :public DoiTuong
{
private:
    string chucvu;
public:
    ChinhTriGia() { cachchet = "dautim"; }
    void Nhap()
    {
        DoiTuong::Nhap();
        cin >> chucvu;
        loai = 1;
    }
    string getCV()
    {
        return chucvu;
    }
};
class DoanhNhan :public DoiTuong
{
private:
    float taisan;
public:
    void Nhap()
    {
        DoiTuong::Nhap();
        cin >> taisan;
        loai = 2;
    }
    float getTaiSan()
    {
        return taisan;
    }
    void CachChet()
    {
        if (taisan > 5) cachchet = "nang";
        else if (taisan < 3) cachchet = "nhe";
        else cachchet = "binh thuong";
    }

};
class TuNhan : public DoiTuong
{
private:
    string toi;
    int namtu;
public:
    void Nhap()
    {
        DoiTuong::Nhap();
        cin >> toi >> namtu;
        loai = 3;
    }
    int getNamTu()
    {
        return namtu;
    }
    void CachChet()
    {
        if (namtu > 20) cachchet = "nang";
        else if (namtu < 10) cachchet = "nhe";
        else cachchet = "binh thuong";
    }
};
class DeathNote
{
private:
    int m;
    int n;
    vector<DoiTuong*> ds;
public:
    static int dem;
    void Nhap()
    {
        cin >> n;
        cin >> m;
        DoiTuong* tmp;
        for (int i = 0; i < n; i++)
        {
            int loai;
            tmp = NULL;
            cin >> loai;
            if (loai == 1) tmp = new ChinhTriGia;
            else if (loai == 2) tmp = new DoanhNhan;
            else tmp = new TuNhan;
            tmp->Nhap();
            tmp->CachChet();
            Check(tmp);
        }
        if (ds.size() > m)
        {
            for (int i = ds.size() - 1; i >= m; i--)
            {
                ds[dem] = ds[i];
                ds.pop_back();
                dem++;
            }
        }
    }
    void Check(DoiTuong* tmp)
    {
        if (ds.empty())
            ds.push_back(tmp);
        int flag = 0;

        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == tmp->loai)
            {
                if (ds[i]->getTen() == tmp->getTen()) {
                    ds[i] = tmp;
                    flag = 1;
                    return;
                }
                else
                {
                    ds.push_back(tmp);
                    flag = 1;
                    return;

                }
            }
        }
        if (!flag) ds.push_back(tmp);

    }
    int getTenCTG()
    {
        int tmp = 0;
        int index = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == 1)
            {
                tmp = ds[i]->getTen().length();
                index = i;
                break;
            }
        }
        for (int i = index; i < ds.size(); i++)
        {
            if (ds[i]->loai == 1)
            {
                if (tmp < ds[i]->getTen().length())
                {
                    tmp = ds[i]->getTen().length();
                    index = i;
                }

            }
        }
        return index;

    }
    int is_XuatHien(int j)
    {
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == j)
                return 1;
        }
        return 0;
    }
    float Tong_taisan()
    {
        float sum = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            sum += ds[i]->getTaiSan();
        }
        return sum;
    }
    string getCC(int k)
    {
        string tmp = "nhe";
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == k)
            {
                if (ds[i]->getCachChet() == "binh thuong")
                    tmp = "binh thuong";
            }
        }
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == k)
            {
                if (ds[i]->getCachChet() == "nang")
                    tmp = "nang";
            }
        }
        return tmp;
    }
    int Tong_NamTu()
    {
        int sum = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i]->loai == 3)
                sum += ds[i]->getNamTu();
        }
        return sum;
    }
    void Xuat()
    {
        if (ds.empty())
        {
            cout << "Deathnote trong" << endl;
            return;
        }
        if (is_XuatHien(1))
        {
            int index = getTenCTG();
            cout << ds[index]->getTen();
            cout << ", Chuc vu: " << ds[index]->getCV() << endl;
        }
        if (is_XuatHien(2))
        {
            cout << "Doanh nhan: " << Tong_taisan() << " ty dong, Cach thuc chet: " << getCC(2) << endl;
        }
        if (is_XuatHien(3))
        {
            cout << "Tu nhan: " << Tong_NamTu() << ", Cach thuc chet: " << getCC(3) << endl;
        }
       
    }
    void Xuat2()
    {
        cout << ds.size();
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i]->getTen() << endl;
        }
    }
};
int DeathNote::dem = 0;
int main()
{
    DeathNote c;
    c.Nhap();
    c.Xuat();
}