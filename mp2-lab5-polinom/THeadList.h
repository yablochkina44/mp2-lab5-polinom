#pragma once
#include "TNode.h"
#include "TList.h"
#include "MyException.h"
#include <iostream>
using namespace std;

template <class T>
class THeadList: public TList<T>
{
protected:
	TNode<T>* pHead;

public:
	THeadList()
	{
		pHead = new TNode <T>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pCurr = pPrevCurr = pStop;
		len = 0;
	}
	~THeadList()//??
	{
		/*if (len != 0)
		{
			pCurr = pFirst;
			while (pCurr != pStop)
			{
				TNode<T>* del = pCurr;
				pCurr = pCurr->pNext;
				delete del;
			}
		}*/
		delete pHead;
	}

	void InsFirst(T val);
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
void THeadList<T>::DeleteFirst()
{
	TList::DeleteFirst();
	pHead->pNext = pFirst;
}
