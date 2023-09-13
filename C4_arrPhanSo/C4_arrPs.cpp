#include<iostream>
#include<stdlib.h>
using namespace std;
class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(int a=rand(), int b=rand()) : tu(a), mau(b) {}
    friend class arrPhanSo;
};

class arrPhanSo
{
private:
    PhanSo* arr;
    int n;
public: 
    arrPhanSo(int size=0)
    {
        n = size;
        arr = new PhanSo[n];
            
    }
    void Nhap()
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i].tu >> arr[i].mau;
    }
    void KhoiTao()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i].tu = rand();
            arr[i].mau = rand();
        }
    }

    ~arrPhanSo()
    {
        delete[]arr;
    }
};
int main()
{

}