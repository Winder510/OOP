#include<iostream>
using namespace std;
class cDaThuc
{
private:
	int bac;
	int* heso;
public:
	cDaThuc(int n = 0)
	{
		bac = n;
		heso = new int[n+1];
		for (int i = 0; i <= bac; i++)
			heso[i] = 0;
	}
	cDaThuc(const cDaThuc& q)
	{
		this->bac = q.bac;
		this->heso = new int[bac + 1];
		for (int i = 0; i <= bac; i++)
			this->heso[i] = q.heso[i];
	}
	float TinhGiaTriTai_x(float x)
	{
		float sum = 0;
		for (int i = 0; i <= bac; i++)
			sum += heso[i] * pow(x, i);
	}
	friend istream& operator>>(istream& is, cDaThuc& p)
	{
		for (int i = 0; i <= p.bac; i++)
		{
			cout << "Nhap vao he so cua bac " << i<<": ";
			cin >> p.heso[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, cDaThuc p)
	{
		for (int i = p.bac; i >=0; i--)
		{
			cout << p.heso[i];
			cout << "x^" << i;
			if (i != 0) cout << " + ";

		}
		return os;
	}
	 cDaThuc operator +(cDaThuc p)
	{
		int bac_kq = max(p.bac, bac);
		cDaThuc kq(bac_kq);
		for (int i = 0; i <= p.bac; i++)
			kq.heso[i] = p.heso[i];
		for (int i = 0; i <= bac; i++)
			kq.heso[i] += heso[i];
		return kq;
	}
	 cDaThuc operator - (cDaThuc p)
	{
		int bac_kq = max(p.bac, bac);
		cDaThuc kq(bac_kq);
		for (int i = 0; i <= p.bac; i++)
			kq.heso[i] += p.heso[i];
		for (int i = 0; i <= bac; i++)
			kq.heso[i] -= heso[i];
		return kq;
	}

	 friend cDaThuc operator+(int a,cDaThuc p)
	 {
		 p.heso[0] += a;
		 return p;
	 }
	 friend cDaThuc operator-(int a, cDaThuc p)
	 {
		 p.heso[0] -= a;
		 return p;
	 }
	cDaThuc& operator=(cDaThuc q)
	{
		bac = q.bac;
		heso = new int[bac+ 1];
		for (int i = 0; i <= bac; i++)
			heso[i] = q.heso[i];
		return *this;
	}
	~cDaThuc()
	{
		delete[]heso;
	}
};
int main()
{
	cDaThuc kq, p(4), q(3);
	cin >> q;
	cin >> p;
	kq = p + q;
	kq = kq+1;
	cout << kq;
}