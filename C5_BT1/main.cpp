#include<iostream>
#include"cSoPhuc.h"
using namespace std;

int main()
{
	cSoPhuc z1;
	cSoPhuc z2;
	cSoPhuc kq;
	do
	{
		int n;
		cout << "1.Kiem tra xem hai so phuc bang nhau khong"<<endl;
		cout << "2.Cong hai so phuc" << endl;
		cout << "3.Tru hai so phuc" << endl;
		cout << "4.Nhan hai so phuc" << endl;
		cout << "5.Chia hai so phuc" << endl;
		cout << "Chon:"; cin >> n;
					
		switch (n)
		{
		case 1: {
			cout << "Nhap vao so phuc thu nhat: ";
			cin >> z1;
			cout << "Nhap vao so phuc thu hai: ";
			cin >> z2;
			cout << endl;
			if (z1 == z2)
				cout << "bang nhau";
			else cout << "khong bang";
			break;

		}
		case 2: {
			cout << "Nhap vao so phuc thu nhat: ";
			cin >> z1;
			cout << "Nhap vao so phuc thu hai: ";
			cin >> z2;
			cout << endl;
			kq = z1 + z2;
	
			cout << z1 << " + " << z2 << "=" << kq;
			break;

		}
		case 3: {
			cout << "Nhap vao so phuc thu nhat: ";
			cin >> z1;
			cout << "Nhap vao so phuc thu hai: ";
			cin >> z2;
			cout << endl;
			kq = z1 - z2;
			cout << z1 << " - " << z2 << "=" << kq;
			break;

		}
		case 4: {
			cout << "Nhap vao so phuc thu nhat: ";
			cin >> z1;
			cout << "Nhap vao so phuc thu hai: ";
			cin >> z2;
			cout << endl;
			kq = z1 * z2;
			cout << z1 << " * " << z2 << "=" << kq;
			break;

		}
		case 5: {
			cout << "Nhap vao so phuc thu nhat: ";
			cin >> z1;
			cout << "Nhap vao so phuc thu hai: ";
			cin >> z2;
			cout << endl;
			kq = z1 / z2;
			cout << z1 << " / " << z2 << "=" << kq;
			break;

		}
		}
	} while (true);
	
}