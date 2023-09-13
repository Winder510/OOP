#include<iostream>
using namespace std;
class NhanVat
{
protected:
    string ten = "";
    float HP = 0;
    float ATK = 0;
    float DEF = 0;
    static int demNhanLoai;
public:
    virtual void Nhap()
    {
        cin >> ten >> HP >> ATK >> DEF;
    }
    virtual void Xuat()
    {
        cout << ten << " " << HP;
    }
    bool is_live()
    {
        return HP > 0;
    }
    void TanCong(NhanVat* enemy)
    {
        if (ATK > enemy->DEF) {
            enemy->HP = enemy->HP - (ATK - enemy->DEF);
        }

    }
    virtual void DieuChinh()
    {
        return;
    }
    int getHP()
    {
        return HP;
    }

};
int NhanVat::demNhanLoai = 0;
class Boss : public NhanVat
{

};
class NhanLoai : public NhanVat
{
protected:
    string NgheNghiep;
public:
    void Nhap()
    {
        NhanVat::Nhap();
        cin >> NgheNghiep;
        ++demNhanLoai;
    }

};
class BanNhan : public NhanVat
{
protected:
    string ChungToc;
public:
    void Nhap()
    {
        NhanVat::Nhap();
        cin >> ChungToc;
    }
};
class DiHinh :public NhanVat
{
public:
};

// Nhan loai
class HuMan : public NhanLoai
{
public:

};
class Elf : public NhanLoai
{
public:
    void DieuChinh()
    {
        DEF = DEF * 1.5;
    }
};

// Ban Nhan
class Orc : public BanNhan
{
public:
    void DieuChinh()
    {
        HP = HP * 1.5;
    }
};
class Golbin : public BanNhan
{
public:
    void DieuChinh()
    {
        ATK = ATK * 1.1;
    }
};

// DiHinh
class DeVil : public DiHinh
{
protected:
    static int demDevil;
public:
    void Nhap()
    {
        NhanVat::Nhap();
        demDevil++;
    }
    void DieuChinh()
    {
        ATK = ATK + ATK * 0.1 * demDevil;
        DEF = DEF + DEF * 0.1 * demDevil;
    }
};
int DeVil::demDevil = 0;
class Vampire : public DiHinh
{
public:
    void DieuChinh()
    {
        HP = HP + HP * 0.1 * demNhanLoai;
    }
};
class Guild
{
private:
    int n;
    NhanVat* ds[100];
public:
    void Nhap()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int loai;
            cin >> loai;
            if (loai == 1) ds[i] = new HuMan;
            else if (loai == 2) ds[i] = new Elf;
            else if (loai == 3) ds[i] = new Orc;
            else if (loai == 4) ds[i] = new Golbin;
            else if (loai == 5) ds[i] = new Vampire;
            else if (loai == 6) ds[i] = new DeVil;
            ds[i]->Nhap();

        }
        for (int i = 0; i < n; i++)
            ds[i]->DieuChinh();
    }
    void Xuat()
    {
        for (int i = 0; i < n; i++)
        {
            if (ds[i]->is_live())
            {
                ds[i]->Xuat();
                cout << endl;
            }

        }
    }
    NhanVat* getMinHp()
    {
        int min_index = 0;
        for (int i = 0; i < n; ++i) {
            if (ds[i]->is_live()) {
                min_index = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ds[i]->is_live() && (ds[i]->getHP() < ds[min_index]->getHP())) {
                min_index = i;
            }
        }
        return ds[min_index];
    }
    bool is_lose()
    {
        for (int i = 0; i < n; ++i) {
            if (ds[i]->is_live()) {
                return false;
            }
        }
        return true;

    }
    void all_attack(NhanVat* enemy)
    {
        for (int i = 0; i < n; i++)
        {
            if (ds[i]->is_live())
                ds[i]->TanCong(enemy);
        }
    }
    void SortHP()
    {
        for (int i = 0; i <= n - 2; ++i)
            for (int j = i + 1; j <= n - 1; ++j)
                if (ds[j]->getHP() < ds[i]->getHP())
                    swap(ds[i], ds[j]);

    }
};
int main()
{
    Guild* team = new Guild;
    Boss* boss = new Boss;
    team->Nhap();
    boss->Nhap();
    int dem = 0;

    // danh nhau
    do
    {
        if (team->is_lose()||dem>100)
        {
            boss->Xuat();
            break;
        }
        team->all_attack(boss);
        dem++;
        if (!boss->is_live())
        {
            team->SortHP();
            team->Xuat();
            break;
        }
        else
        {
            boss->TanCong(team->getMinHp());
            dem++;
        }
    } while (true);



}