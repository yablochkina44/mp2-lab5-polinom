#pragma once
#include "TNode.h"
#include "MyException.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
	TNode<T>* pHead;
	TNode<T>* pFirst;		//указатель на первый элемент
	TNode<T>* pCurr;		//указатель на текущий элемент
	TNode<T>* pPrevCurr;    //указатель на предыдущий текущему элемент
	TNode<T>* pLast;		//указатель на последний элемент
	TNode<T>* pStop;		//указатель на голову в циклическом списке
	int len;				//длина списка
	int pos;				//номер текущего элемента

public:
	TList()
	{
		pHead = new TNode <T>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pCurr = pPrevCurr = NULL;
		pos = -1;
		len = 0;
	}
	~TList()
	{
		if (len != 0)
		{
			pCurr = pFirst;
			while (pCurr != pStop)
			{
				pPrevCurr = pCurr;
				pCurr = pCurr->pNext;
				delete pPrevCurr;
			}
		}
		delete pHead;
	}

	void Reset();
	void GoNext();

	bool IsListEmpty();
	bool IsListEnded(void) const;

	T GetValueCurrent();
	void SetValueCurrent(T v);
	void SetCurrPos(int _pos);

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

