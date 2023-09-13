#include "cSoPhuc.h"
#include<iostream>
using namespace std;
cSoPhuc operator+(cSoPhuc z1, cSoPhuc z2)
{
	cSoPhuc p;
	p.ao = z1.ao + z2.ao;
	p.thuc = z1.thuc + z2.thuc;
	return p;
}
cSoPhuc operator-(cSoPhuc z1, cSoPhuc z2)
{
	cSoPhuc p;
	p.ao = z1.ao - z2.ao;
	p.thuc = z1.thuc - z2.thuc;
	return p;
}
cSoPhuc operator*(cSoPhuc z1, cSoPhuc z2)
{
	cSoPhuc p;
	p.thuc = z1.thuc * z2.thuc - z1.ao * z2.ao;
	p.ao = z1.thuc * z2.ao + z1.ao * z2.thuc;
	return p;
}
cSoPhuc operator/(cSoPhuc z1, cSoPhuc z2)
{
	cSoPhuc p;
	p.thuc = (z1.thuc * z2.thuc + z1.ao * z2.ao) / (z2.thuc * z2.thuc + z2.ao * z2.ao);
	p.ao = (z1.ao * z2.thuc - z1.thuc * z2.ao) / (z2.thuc * z2.thuc + z2.ao * z2.ao);
	return p;
}
bool operator==(cSoPhuc z1, cSoPhuc z2)
{
	if ((z1.ao == z2.ao) && z2.thuc == z1.thuc)
		return 1;
	else return 0;
}





