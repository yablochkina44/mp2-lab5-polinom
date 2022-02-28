#pragma once
#include<iostream>
#include "TList.h"
#include "THeadList.h"
#include "TMonom.h"
using namespace std;

class TPolinom :public THeadList<TMonom> 
{
public:
	TPolinom() :THeadList<TMonom>() {
		pHead->value.coef = 0;
		pHead->value.x = 0;
		pHead->value.y = 0;
		pHead->value.z = -1;
	}
	TPolinom(int monoms[][2], int n) :THeadList<TMonom>() {
		pHead->value.coef = 0;
		pHead->value.x = 0;
		pHead->value.y = 0;
		pHead->value.z = -1;
		TMonom M;
		for (int i = 0; i < n; i++)
		{
			M.coef = monoms[i][0];
			M.z = monoms[i][1] % 10;
			M.x = monoms[i][1] / 100;
			M.y = monoms[i][1] / 10 % 10;
			InsLast(M);
		}
	}
	TPolinom(TPolinom& P) : THeadList<TMonom>() {
		pHead->value.coef = 0;
		pHead->value.x = 0;
		pHead->value.y = 0;
		pHead->value.z = -1;
		TMonom M;
		for (P.Reset(); !P.IsListEnded(); P.GoNext())
		{
			M = P.pCurr->value;
			InsLast(M);
		}
	}
	void AddMonom(const TMonom& M) {
		int flag = 0;
		for (Reset(); !IsListEnded(); GoNext()) {
			if (pCurr->value == M)
			{
				pCurr->value.coef += M.coef;
				if (pCurr->value.coef == 0)
				{
					DeleteCurrent();
					flag = 1;
				}
				break;
			}
			else {
				if (pCurr->value < M) {
					InsCurrent(M);
					break;
				}
			}
		}
		if (IsListEnded() && flag == 0) InsCurrent(M);
	}
	TPolinom operator* (double a) {
		TPolinom res(*this);
		for (res.Reset(); !res.IsListEnded(); res.GoNext())
		{
			res.pCurr->value.coef *= a;
			if (res.pCurr->value.coef == 0)
			{
				res.DeleteCurrent(); break;
			}
		}
		return res;
	}
	void operator*=(double a) {

		for (Reset(); !IsListEnded(); GoNext())
		{
			pCurr->value.coef *= a;
			if (pCurr->value.coef == 0)
			{
				DeleteCurrent(); break;
			}
		}

	}
	void operator*=(TMonom M) {
		for (Reset(); !IsListEnded(); GoNext())
		{
			pCurr->value.coef *= M.coef;
			pCurr->value.x += M.x;
			pCurr->value.y += M.y;
			pCurr->value.z += M.z;
		}

	}
	TPolinom operator *(TMonom M) {
		TPolinom res(*this);
		for (res.Reset(); !res.IsListEnded(); res.GoNext()) {
			res.pCurr->value.x += M.x;
			res.pCurr->value.y += M.y;
			res.pCurr->value.z += M.z;
			res.pCurr->value.coef *= M.coef;
		}
		return res;
	}
	void operator +=(TPolinom& Q) {
		TMonom pm, qm, rm;
		Reset();
		Q.Reset();
		while (!Q.IsListEnded())
		{
			pm = pCurr->value;
			qm = Q.pCurr->value;
			if (pm > qm)
			{
				GoNext();
			}
			else
			{
				if (pm > qm)
				{
					InsCurrent(qm);
					Q.GoNext();
				}
				else {
					rm = pm;
					rm.coef += qm.coef;
					if (rm.coef == 0)
					{
						DeleteCurrent();
						Q.GoNext();
					}
					else
					{
						pCurr->value = rm;
						GoNext();
						Q.GoNext();
					}
				}
			}

		}

	}

	friend istream& operator>>(istream& in, TPolinom& p) {
		TMonom m;
		in >> m;
		while (m.coef != 0) {
			p.AddMonom(m);
			in >> m;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, TPolinom& p)
	{
		for (p.Reset(); !p.IsListEnded(); p.GoNext()) {
			if (p.pCurr->value.coef < 0 || p.pCurr == p.pFirst)
				out << p.pCurr->value;
			else
				out << " + " << p.pCurr->value;
		}
		return out;
	}
};

