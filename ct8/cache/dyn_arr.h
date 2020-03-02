#pragma once
#include <iostream>
#include <stdexcept>

typedef double T;

class dyn_arr
{
public:
	dyn_arr(const int n = 1);
	dyn_arr(const dyn_arr &a) = delete;
	dyn_arr & operator=(const dyn_arr &a) = delete;
	void push(T x);
	void pop();
	T top();
	int size() const noexcept;
	int getZap() const noexcept;
	T &operator[](int i);
	T operator[](int i) const;
	friend std::ostream& operator<< (std::ostream & a, const dyn_arr & d);
	~dyn_arr();
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