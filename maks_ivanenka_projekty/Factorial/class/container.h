#pragma once
#include <iostream>
template<class T>
class Container{
public:

	Container(size_t size = 200);
	Container(T a, const size_t size = 200);
	Container(const Container<T> &a);

	void swap(Container<T> &a);
	void resize(const int a);
	void push_back(const T a);

	size_t size() const				{ return size_; }
	T & operator[](int i)			{ return p_[i]; }
	T & operator[](int i) const		{ return p_[i]; }

	friend std::ostream & operator<<(std::ostream &a, const Container<T> &c){
		for (int i = 0; i < c.size_; i++)
			a << c.p_[i];
		return a;
	};

	Container<T> & operator=(const Container<T> &a);
	Container<T> operator+(const Container<T> &b);

	virtual ~Container();

private:
	T * p_;
	size_t size_;
};