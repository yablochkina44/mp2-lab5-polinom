#pragma once
#include "TNode.h"
#include "MyException.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
	TNode<T>* pFirst;		//указатель на первый элемент
	TNode<T>* pCurr;		//указатель на текущий элемент
	TNode<T>* pPrevCurr;    //указатель на предыдущий текущему элемент
	TNode<T>* pLast;		//указатель на последний элемент
	TNode<T>* pStop;		//указатель на голову в циклическом списке
	int len;				//длина списка
	

public:
	TList()
	{
		
		pFirst = pLast = pCurr = pPrevCurr = pStop=NULL;
		len = 0;
	}
	~TList()
	{
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	TList(const TList<T>& c)
	{
		TNode<T>* tmp = c.pFirst;
		if (tmp == pStop)
		{
			pFirst = tmp;
		}
		while (tmp != pStop)
		{
			Push(tmp->val);
			tmp = tmp->pNext;
		}
		delete tmp;
	}


	void Reset();
	void GoNext();

	bool IsListEmpty();
	bool IsListEnded(void) const;

	T GetValueCurrent();
	void SetValueCurrent(T v);
	
	void InsFirst(const T& a);
	void InsLast(T val);
	void InsCurrent(T val);
	
	void DeleteCurrent();
	void DeleteFirst();
};

template<class T>
inline void TList<T>::Reset()
{
	pPrevCurr = pStop;
	if (IsListEmpty())
	{
		pCurr = pStop;
		
	}
	else
	{
		pCurr = pFirst;
		

	}

}

template<class T>
void TList<T>::GoNext()
{
	pPrevCurr = pCurr;
	pCurr = pCurr->pNext;
	
}

template<class T>
bool TList<T>::IsListEmpty()
{
	return len == 0;
}

template<class T>
bool TList<T>::IsListEnded(void) const
{
	return pCurr == pStop;
}

template<class T>
T TList<T>::GetValueCurrent()
{
	if (pCurr != pStop)
		return pCurr->value;
}

template<class T>
void TList<T>::SetValueCurrent(T v)
{
	if (pCurr != pStop)
		pCurr->value = v;
}


template <class T>
void TList<T>::InsFirst(const T& a)
{
	TNode<T>* tmp;
	tmp = new TNode<T>;
	tmp->pNext = pFirst;
	tmp->value = a;
	if (pFirst == pStop) {
		pLast = pFirst = tmp;
	}
	else {
		pFirst = tmp;
	}
	len++;


	/* на  паре писали
	TNode<T>* tmp = new TNode<T>;
	tmp->value = val;
	tmp->pNext = pFirst;

	pFirst = tmp;
	if (len == 1)
		pLast = pFirst;
	len++;*/

}


template<class T>
void TList<T>::InsLast(T val)
{
	TNode <T>* newLast = new TNode <T>;
	newLast->value = val;
	newLast->pNext = pStop;
	if (pLast != pStop)
		pLast->pNext = newLast;
	else
		pFirst = newLast;
	pLast = newLast;
	len++;
}

template<class T>
void TList<T>::InsCurrent(T val)
{
	if (pCurr == pFirst)
		InsFirst(val);
	else if (pPrevCurr == pLast)
		InsLast(val);//???
	else
	{
		TNode<T>* pNew = new TNode<T>;
		pNew->value = val;
		pNew->pNext = pCurr;
		pPrevCurr->pNext = pNew;
		pCurr = pNew;
		len++;
	}

}

template<class T>
void TList<T>::DeleteCurrent()
{

	if (pCurr == pStop) throw MyException("Error DelCurr: Stop");
	if (pCurr == pFirst)
		DeleteFirst();
	else 
	{
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPrevCurr->pNext = pCurr;
		delete tmp;
		len--;
	}
	

}

template<class T>
void TList<T>::DeleteFirst()
{
	
	if (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	if (IsListEmpty())
	{
		throw MyException("List is Empty");
		//pLast = pStop;
	}
}
