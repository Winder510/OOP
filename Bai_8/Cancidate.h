#pragma once
#include<iostream>
#include<string>
using namespace std;
class Cancidate
{
private:
	string id;
	string hoten;
	string dob;
	int diemtoan;
	int diemvan;
	int diemanh;
public:
	void Khoitao(string id, string hoten, string dob, int diemtoan, int diemvan, int diemanh);
	void Xuat();
	int totalScore();
};

