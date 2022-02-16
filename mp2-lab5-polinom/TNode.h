#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode
{
	T value;
	TNode* pNext;
	TNode(T v, TNode* p = NULL)
	{
		value = v;
		pNext = p;
	}
};