#pragma once
#include<iostream>
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
		TMonom m;
		for (int i = 0; i < n; i++)
		{
			m.coef = monoms[i][0];
			m.z = monoms[i][1] % 10;
			m.x = monoms[i][1] / 100;
			m.y = monoms[i][1] / 10 % 10;
			InsLast(m);
		}
	}


	TPolinom(TPolinom& p) : THeadList<TMonom>() {
		pHead->value.coef = 0;
		pHead->value.x = 0;
		pHead->value.y = 0;
		pHead->value.z = -1;
		TMonom m;
		for (p.Reset(); !p.IsListEnded(); p.GoNext())
		{
			m = p.pCurr->value;
			InsLast(m);
		}
	}
	
	
	//на паре вставляем в конец в посл цикле
	void AddMonom(const TMonom& m) {
		int flag = 0;
		for (Reset(); !IsListEnded(); GoNext()) {
			if (pCurr->value == m)
			{
				pCurr->value.coef += m.coef;
				if (pCurr->value.coef == 0)
				{
					DeleteCurrent();
					flag = 1;
				}
				break;
			}
			else {
				if (pCurr->value < m) {
					InsCurrent(m);
					break;
				}
			}
		}
		if (IsListEnded() && flag == 0) InsCurrent(m);
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
	/*TPolinom& operator+=(TMonom& mon)
	{
		if (mon.coef)
		{
			for (Reset(); !IsListEnded(); GoNext())
			{
				if (mon == pCurr->value)
				{
					double tmp = mon.coef + pCurr->value.coef;
					if (tmp != 0)
					{
						pCurr->value.coef = tmp;
						return *this;
					}
					else
					{
						DeleteCurrent();
						return *this;
					}
				}
				if (mon > pCurr->value)
				{
					InsCurrent(mon);
					return *this;
				}
			}
			InsLast(mon);
		}
		return *this;
	}*/

	bool TPolinom::operator==(TPolinom& p)
	{
		int flag = 0;
		p.Reset();
		for (Reset(); !IsListEnded(); GoNext())
		{
			if (pCurr->value.coef != p.pCurr->value.coef)
			{
				flag++;
			}
			else
			{
				if (pCurr->value != p.pCurr->value)
				{
					flag++;
				}
			}
			p.GoNext();
		}
		Reset();
		for (p.Reset(); !p.IsListEnded(); p.GoNext())
		{
			if (p.pCurr->value.coef != pCurr->value.coef)
			{
				flag++;
			}
			else
			{
				if (p.pCurr->value != pCurr->value)
				{
					flag++;
				}
			}
			GoNext();
		}
		if (flag > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	TPolinom& operator +=(TPolinom& Q) {
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
		return *this;
	}


	TPolinom operator +(TPolinom& p)
	{
		TPolinom res(*this);
		TMonom vcurrres, vcurrpol;
		res.Reset();
		p.Reset();
		while (!p.IsListEnded())
		{
			vcurrres = res.pCurr->value;
			vcurrpol = p.pCurr->value;
			if (vcurrres > vcurrpol)
			{
				res.GoNext();
			}
			else if (vcurrres < vcurrpol)
			{
				InsCurrent(vcurrpol);
				p.GoNext();
			}
			else
			{
				res.pCurr->value.coef += p.pCurr->value.coef;
				if (res.pCurr->value.coef != 0)
				{
					res.GoNext();
					p.GoNext();

				}
				else
				{
					res.DeleteCurrent();
					p.GoNext();
				}

			}

		}
		return res;

	}

	/*TPolinom operator+(TMonom& mon)
	{
		TPolinom tmp(*this);
		tmp += mon;
		return tmp;
	}*/

	friend istream& operator>>(istream& in, TPolinom& p)
	{
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




