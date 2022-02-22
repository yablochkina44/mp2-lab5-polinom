#pragma once
#include "TNode.h"
#include "TList.h"
#include "MyException.h"
#include <iostream>
using namespace std;

template <class T>
class THeadList:public TList<T>
{
protected:
	TNode<T>* pHead;

public:
	THeadList()
	{
		pHead = new TNode <T>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pCurr = pPrevCurr = NULL;
		pos = -1;
		len = 0;
	}
	~THeadList()
	{
		if (len != 0)
		{
			pCurr = pFirst;
			while (pCurr != pStop)
			{
				TNode<T>* del = pCurr;
				pCurr = pCurr->pNext;
				delete del;
			}
		}
		delete pHead;
	}

	void InsFirst(T val);
	void InsLast(T val);
	void InsCurrent(T val);

	void DeleteList();
	void DeleteCurrent();
	void DeleteFirst();
	

	//void DeleteLast()
	//{
	//	TNode<T>* previous = pFirst; //предыдущий элемент
	//	TNode<T>* current = pFirst;// последний?(текущий)
	//	while (current->pNext != NULL)
	//	{
	//		previous = current;
	//		current = current->pNext;
	//	}
	//	//учесть проблему если в списке одно звено или их нет
	//	delete current;
	//	previous->pNext = NULL;
	//}
};


template<class T>
void THeadList<T>::InsFirst(T val)
{
	TList::InsFirst(val);
	pHead->pNext = pFirst;

}


template<class T>
void THeadList<T>::InsCurrent(T val)
{
	if (pCurr == pFirst)
		InsFirst(val);
	else if (pPrevCurr == pLast)
		InsLast(val);
	else
	{
		TNode<T>* pNew = new TNode<T>(val, pCurr);
		pPrevCurr->pNext = pNew;
		pCurr = pNew;
		len++;
	}

}

template<class T>
void THeadList<T>::DeleteList()
{
	while (!IsListEmpty)
	{
		DeleteFirst();
	}
	pFirst = pLast = pCurr = pPrevCurr = pStop;
	pos = -1;
}

template<class T>
void THeadList<T>::DeleteCurrent()
{

	if (pCurr == pFirst)
		DeleteFirst();
	else if (pCurr != pStop)
	{
		pPrevCurr->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPrevCurr->pNext;
		len--;
	}

}

template<class T>
void THeadList<T>::DeleteFirst()
{
	TList::DeleteFirst();
	pHead->pNext = pFirst;
}
