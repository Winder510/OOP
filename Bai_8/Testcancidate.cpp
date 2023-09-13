/*
xây dựng lớp cancidate gồm các thuộc tính: mã ,tên, ngày tháng năm sinh,điểm toán,điểm văn,điểm anh
Xây dựng lớp testcancidate để kiểm tra lớp trên:
- Nhập vào n thí sinh (do người dùng nhập)
- in ra các candidate có tổng điểm trên 15

*/
#include "Testcancidate.h"
#include"Cancidate.h"
using namespace std;

void Testcancidate::RunTest()
{
	int n;
	cin >> n;
	Cancidate* c = new Cancidate[n];
	for(int i=0;i<n;i++)
	{
		string id, name, dob;
		float diemtoan, diemanh, diemvan;
        cout << "Candidate " << i + 1 << endl;
        cout << "Enter candidate ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter candidate name: ";
        getline(cin, name);
        cout << "Enter candidate date of birth (dd/mm/yyyy): ";
        getline(cin, dob);
        cout << "Enter candidate math score: ";
        cin >> diemtoan;
        cout << "Enter candidate literature score: ";
        cin >> diemvan;
        cout << "Enter candidate english score: ";
        cin >> diemanh;

        c[i].Khoitao(id, name, dob, diemtoan, diemvan, diemanh);
	}
    for (int i = 0; i < n; i++)
        if (c[i].totalScore() > 15)
            c[i].Xuat();
}
int main()
{
    Testcancidate t;
    t.RunTest();
}
