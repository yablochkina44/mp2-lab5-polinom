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
	int pos;				//номер текущего элемента

public:
	TList()
	{
		
		pFirst = pLast = pCurr = pPrevCurr = pStop=NULL;
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
				TNode<T>* del = pCurr;
				pCurr = pCurr->pNext;
				delete del;
			}
		}
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
};

template<class T>
inline void TList<T>::Reset()
{
	pPrevCurr = pStop;
	if (IsListEmpty())
	{
		pCurr = pStop;
		pos = -1;
	}
	else
	{
		pCurr = pFirst;
		pos = 0;

	}

}

template<class T>
void TList<T>::GoNext()
{
	pPrevCurr = pCurr;
	pCurr = pCurr->pNext;
	pos++;
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

template<class T>
void TList<T>::SetCurrPos(int _pos)
{
	Reset();
	for (int i = 0; i < _pos; i++)
		GoNext();

}


template<class T>
void TList<T>::InsFirst(T val)
{
	TNode<T>* tmp = new TNode<T>(val, pFirst);
	if (tmp == NULL)
		throw MyException("List empty");
	else
	{
		pFirst = tmp;
		len++;
		//проверка пустоты списка перед вставкой
		if (len == 1)
		{
			pLast = tmp;
			Reset();
		}
		//корректировка текущей позиции - отличие обработки для начала списка
		else if (pos == 0)
			pCurr = tmp;
		else
			pos++;
	}
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
void TList<T>::DeleteList()
{
	while (!IsListEmpty)
	{
		DeleteFirst();
	}
	pFirst = pLast = pCurr = pPrevCurr = pStop;
	pos = -1;
}

template<class T>
void TList<T>::DeleteCurrent()
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
void TList<T>::DeleteFirst()
{
	if (IsListEmpty())
		MyException("List empty");
	else
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext();
		delete tmp;
		len--;
		if (IsListEmpty())
		{
			pLast = pStop;
			Reset();
		}
		else if (pos == 0)
			pCurr = pFirst;
		else if (pos == 1)
			pPrevCurr = pStop;
		if (pos > 0)
			pos--;
	}
}
