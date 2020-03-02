#pragma once
#include "node.h"
template<typename T>
class List
{
public:
	List():size_(0), head(nullptr)						{				};
	~List()												{clear();		};
	int getSize()										{return size_;	};
	void clear();
	void pop_front();
	void insert(const int i, T data);
	void push_front(T data);
	void push_back(T data);
	T & operator[](const int i);

private:
	Node<T> *head;
	int size_;
};