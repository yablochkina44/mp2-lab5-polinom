#pragma once
#include<iostream>
#include "TList.h"
#include "THeadList.h"
using namespace std;
struct TMonom
{
	double coef;
	int x, y, z;
public:
	bool operator ==(const TMonom& m);
	bool operator >(const TMonom& m);
	bool operator >=(const TMonom& m);
	bool operator <(const TMonom& m);
	bool operator <=(const TMonom& m);
	bool operator !=(const TMonom& m);

	friend istream& operator>>(istream& in, TMonom& m)
	{
		int xyz;
		cout << "Coefficient: ";
		in >> m.coef;
		cout << endl << " Power: ";
		in >> xyz;
		m.x = xyz / 100;
		m.y = xyz / 10 % 10;
		m.z = xyz % 10;
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMonom& m)
	{
		out << m.coef << "(x^" << m.x << ")" << "(y^" << m.y << ")" << "(z^" << m.z << ")";
		return out;
	}
};

bool TMonom::operator==(const TMonom& m) {
	if (x == m.x && y == m.y && z == m.z)
		return true;
	else return false;
}

bool TMonom::operator>(const TMonom& m) {
	int a, b;
	a = x * 100 + y * 10 + z;
	b = m.x * 100 + m.y * 10 + m.z;

	if (a > b)	return true;
	else return false;
}

bool TMonom::operator>=(const TMonom& m) {
	int a, b;
	a = x * 100 + y * 10 + z;
	b = m.x * 100 + m.y * 10 + m.z;

	if (a >= b)	return true;
	else return false;
}

bool TMonom::operator<(const TMonom& m) {
	int a, b;
	a = x * 100 + y * 10 + z;
	b = m.x * 100 + m.y * 10 + m.z;

	if (a < b)	return true;
	else return false;
}

bool TMonom::operator<=(const TMonom& m) {
	int a, b;
	a = x * 100 + y * 10 + z;
	b = m.x * 100 + m.y * 10 + m.z;

	if (a <= b)	return true;
	else return false;
}

bool TMonom::operator!=(const TMonom& m) {
	if (*this == m)
		return false;
	else
		return true;
}