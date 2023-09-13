#pragma once
#include<iostream>
using namespace std;
class cSoPhuc
{
private:
	double thuc;
	double ao;
public:
	cSoPhuc(double t=0 , double a=0 ) :thuc(t), ao(a) {};
	//cSoPhuc(double t) :thuc(t), ao(0) {};

	friend cSoPhuc operator+(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator-(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator*(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator/(cSoPhuc, cSoPhuc);
	friend bool operator==(cSoPhuc, cSoPhuc);
	friend istream& operator>>(istream& is, cSoPhuc& z)
	{
		cin >> z.thuc;
		cin >> z.ao;
		return is;
	}
	friend ostream& operator<<(ostream& os, cSoPhuc& z)
	{
		os <<"("<< z.thuc << " + " << z.ao << "i"<<")";
		return os;
	}




};

