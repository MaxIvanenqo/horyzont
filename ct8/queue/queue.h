#pragma once
#include <iostream>
#include <stdexcept>

typedef double T;

class queue
{
public:
	queue(const int n = 1);
	queue(const queue &a) = delete;
	queue & operator=(const queue &a) = delete;
	void enqueue(T x);
	T dequeue();
	T front();
	int size() const noexcept;
	int getZap() const noexcept					{return this->zap;};
	T &operator[](int i);
	T operator[](int i) const;
	friend std::ostream& operator<< (std::ostream & a, const queue & d);
	~queue();
private:
	T *arr;
	int size_;
	int zap;
	void zapIncrease()							{this->zap++;	  };
	void zapDecrease()							{this->zap--;	  };
	void sizeIncrease();
	void sizeDecrease();
	void powieksz();
	void pomniejsz();
};