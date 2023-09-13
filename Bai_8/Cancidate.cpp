#include "Cancidate.h"
#include<iostream>
using namespace std;
void Cancidate::Khoitao(string id, string hoten, string dob, int diemtoan, int diemvan, int diemanh)
{
	this->id = id;
	this->hoten = hoten;
	this->dob = dob;
	this->diemtoan = diemtoan;
	this->diemanh = diemanh;
	this->diemvan = diemvan;
}
int Cancidate::totalScore()
{
	return diemanh + diemtoan + diemvan;
}
void Cancidate::Xuat()
{
	cout << "id:" << id<<endl;
	cout << "Ho va ten:" << hoten << endl;
	cout << "Birthday:" << dob << endl;
	cout << "Diem toan: " << diemtoan << endl;
	cout << "Diem anh:" << diemanh << endl;
	cout << "Diem van:" << diemvan << endl;
	cout << "Tong diem:" << totalScore() << endl;
}
