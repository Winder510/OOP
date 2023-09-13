#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class DonThuc
{
private:
	int heso;
	int somu;
public:
	DonThuc(): heso(0),somu(0){}
	DonThuc(int a,int b): heso(a),somu(b){}

	int getH() { return heso; }
	int getM() { return somu; }
	void setH(int _heso) { heso = _heso; }
	void setM(int _somu) { somu = _somu; }

	
	int GiaTri_DonThuc(int x) {
		return heso * pow(x, somu);
	}

	DonThuc Cong_DonThuc(DonThuc P)
	{	
		DonThuc Q;
		if (somu == P.somu) {
			Q.heso = heso + P.heso;
			Q.somu = somu;
			
		}
		return Q;

	}

};

class DaThuc
{
private:
	DonThuc* dt; // mảng chứa các đơn thức tương ứng của đa thức
	int size;   // bâc của đa thức
public:

	DaThuc(int n=0) {
		size = n;
		dt = new DonThuc[size];
	}
	void Nhap() {

		int x;
		for (int i = 0; i < size; i++) {
			
			cout << "Nhap vao he so cua don thuc thu " << i+1 << ":"; cin >> x; dt[i].setH(x);
			cout << "Nhap vao so mu cua don thuc thu " << i + 1 << ":"; cin >> x; dt[i].setM(x);
			cout << endl;
		}
	}
	void Xuat() {
		for (int i = 0; i < size; i++) {
			cout << dt[i].getH() << "x^" << dt[i].getM();
			if (i != size - 1)
				cout << "+";
		}
	}
	int Tinh_giaTri(int x) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += dt[i].GiaTri_DonThuc(x);
		}
		return sum;
	}
	void Xep_SoMu() {
		for(int i=0;i<size-1;i++)
			for (int j = i + 1; j < size; j++) {
				if (dt[i].getH() < dt[j].getH())
					swap(dt[i], dt[j]);
			}
	}
	DaThuc Cong_DaThuc( DaThuc P) {
		Xep_SoMu();
		P.Xep_SoMu();
		DaThuc Q(max(size, P.size));

		int i = 0, j = 0;
		int k = 0;
		while (i < size && j < P.size) {
			int somu1 = dt[i].getM();
			int somu2 = P.dt[j].getM();
			if (somu1 == somu2) {
				Q.dt[k] = dt[i].Cong_DonThuc(P.dt[j]);
				i++; j++;
				k++;
			}
			else if (somu1 < somu2) {
				Q.dt[k].setH(P.dt[j].getH());
				Q.dt[k].setM(P.dt[j].getM());
				k++;
				j++;
			}
			else {
				Q.dt[k].setH(dt[i].getH());
				Q.dt[k].setM(dt[i].getM());
				k++;
				i++;
			}
		}
		while (i < size) {
			Q.dt[k].setH(dt[i].getH());
			Q.dt[k].setM(dt[i].getM());
			k++;
			i++;
		}
		while (j < P.size) {
			Q.dt[k].setH(P.dt[j].getH());
			Q.dt[k].setM(P.dt[j].getM());
			k++;
			j++;
		}
	
		return Q;


	}
	~DaThuc()
	{
		delete[]dt;
	}

};
int main()
{
	DaThuc Q(4), P(2);
	P.Nhap();
	P.Xuat();
	cout << endl;
	Q.Nhap();
	Q.Xuat();
	cout << "Cong hai da thuc:";
	DaThuc M(4); 
	Q.Cong_DaThuc(P);
	M.Xuat();

}