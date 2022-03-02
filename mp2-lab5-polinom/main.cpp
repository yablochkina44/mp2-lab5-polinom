#pragma once
#include<iostream>
#include"TPolinom.h"
#include "TMonom.h"
#include"TList.h"


using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");
	TMonom m1, m2,m3,m4;
	m1.coef = 10;
	m2.coef = 20;
	m3.coef = 10;
	m4.coef = 20;

	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m2.x = 1;
	m2.y = 1;
	m2.z = 1;

	//m3.x = 2;
	//m3.y = 2;
	//m3.z = 2;

	//m4.x = 2;
	//m4.y = 2;
	//m4.z = 2;

	TPolinom p1,p2;
	p1.AddMonom(m1);
	//p1.AddMonom(m3);
	p2.AddMonom(m2);
	/*p2.AddMonom(m4);*/
	p1 += p2;
	cout << p1;
	
}