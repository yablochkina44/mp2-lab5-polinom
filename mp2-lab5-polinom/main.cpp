#pragma once
#include<iostream>
#include"TPolinom.h"
#include "TMonom.h"
#include"TList.h"


using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");

	try {
		TPolinom p1,p2,p3;
		TMonom m;
		cout << "Polinom 1:" << endl;
		cin >> m;
		p1.AddMonom(m);
		cin >> m;
		p1.AddMonom(m);
		cout << p1<<endl;

		cout << "Polinom 2:" << endl;
		cin >> m;
		p2.AddMonom(m);
		cin >> m;
		p2.AddMonom(m);
		cout << p2 << endl;
		p1 += p1;
		cout << "Polinom1 + Polinom2:" << endl;
		cout << p1 << endl;
		cout << p2 << endl;
		

		/*TPolinom p, p1, p2, p3;
		TMonom m[3];
		cin >> p;
		cout << p;
		cin >> p1;
		cout << p1 << endl;
		p += p1;
		cout << p << endl;
		cin >> p2;
		p2 *= -1;
		cout << p2 << endl;

		cin >> p3;
		p3 += p2;
		cout << p3 << endl;*/

	}
	catch (char* s) {
		cout << s;
	}
	system("pause");
	





	//TMonom m1, m2,m3,m4;
	//m1.coef = 10;
	//m2.coef = 20;
	//m3.coef = 10;
	//m4.coef = 20;

	//m1.x = 1;
	//m1.y = 1;
	//m1.z = 1;

	//m2.x = 1;
	//m2.y = 1;
	//m2.z = 1;

	////m3.x = 2;
	////m3.y = 2;
	////m3.z = 2;

	////m4.x = 2;
	////m4.y = 2;
	////m4.z = 2;

	//TPolinom p1,p2;
	//p1.AddMonom(m1);
	////p1.AddMonom(m3);
	//p2.AddMonom(m2);
	///*p2.AddMonom(m4);*/
	//p1 += p2;
	//cout << p1;
	
}