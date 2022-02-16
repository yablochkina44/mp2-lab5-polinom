#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
	//TNode<T>* pHead;
	TNode<T>* pFirst;		//указатель на первый элемент
	TNode<T>* pCurr;		//указатель на текущий элемент
	TNode<T>* pPrevCurr;   //указатель на предыдущий текущему элемент
	TNode<T>* pLast;		//указатель на последний элемент
	TNode<T>* pStop;		//указатель на голову в циклическом списке
	int len;				//длина списка

public:
	TList()
	{
		pFirst = NULL;
		pCurr = NULL;
		pPrevCurr = NULL;
		pLast = NULL;
		pStop = NULL;
		len = 0;
	}
	

	T GetValueCurrent()
	{
		if (pCurr != pStop)
			return pCurr->value;
	}

	void SetValueCurrent(T v)
	{
		if (pCurr != pStop)
			pCurr->value = v;
	}

	void InsFirst(T val)
	{
		TNode<T>* newFirst = new TNode<T>;
		newFirst->value = val;
		newFirst->pNext = pFirst;

		pFirst = newFirst;
		if (len == 1)
			pLast = pFirst;
		len++;

	}

	void InsLast(T val)
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

	void InsCurrent(T val)
	{
		if (pCurr == pFirst)
			InsFirst(val);
		else if (pPrevCurr == pLast)
			InsLast(val);
		else
		{
			TNode<T>* pNew = new TNode<T>(val,pCurr);
			pPrevCurr->pNext = pNew;
			pCurr = pNew;
			len++;
		}

	}

	void DeleteCurrent()
	{

		if (pCurr == pFirst)
			DelFirst();
		else if (pCurr != pStop)
		{
			pPrevCurr->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPrevCurr->pNext;
			len--;
		}

	}

	void DeleteFirst()
	{
		/*if (len != 0)
		{
			if (pCurr != pFirst)
			{
				pHead->pNext = pFirst->pNext;
				delete pFirst;
				pFirst = pHead->pNext;
				len--;
				
			}
			else
			{
				pHead->pNext = pFirst->pNext;
				delete pFirst;
				pCurr = pFirst = pHead->pNext;
				len--;
			}
		}*/
	}


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

