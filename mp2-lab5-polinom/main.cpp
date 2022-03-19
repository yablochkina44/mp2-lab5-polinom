#pragma once
#include<iostream>
#include"TPolinom.h"
#include "TMonom.h"
#include"TList.h"


using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");

	TPolinom p1, p2;
	TMonom m2, m1, m, m0;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m1.coef = -10;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m0.coef = 20;
	m0.x = 2;
	m0.y = 2;
	m0.z = 2;

	m2.coef = 40;
	m2.x = 3;
	m2.y = 3;
	m2.z = 3;

	p1.AddMonom(m);
	p1.AddMonom(m0);
	p1.AddMonom(m2);
	cout << "Polinom1:" << endl;
	cout << p1 << endl;

	p2.AddMonom(m1);
	p2.AddMonom(m0);
	p2.AddMonom(m2);

	cout << "Polinom2:" << endl;
	cout << p2 << endl;

	p1 += p2;		
	cout << "Polinom1 + Polinom2:" << endl;
	cout << p1 << endl;
		
	
}