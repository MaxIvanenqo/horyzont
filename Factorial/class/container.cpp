#include <typeinfo>
#include "container.h"

template<class T>
Container<T>::Container(size_t size):
 size_(size),
 p_(new T[size])
{	
	for(size_t i = 0; i != size; i++) p_[i] = 0;  
}

template<class T>
Container<T>::Container(T a, const size_t size):
 size_(size),
 p_(new T[size])
{	
	for(size_t i = 0; i != size; i++) p_[i] = a;  
}

template<class T>
Container<T>::Container(const Container &a):
 size_(a.size_),
 p_(new T[a.size_])
{	
	for(size_t i = 0; i != size_; i++) p_[i] = a.p_[i];  
}

template<class T>
void Container<T>::resize(const int a)
{	size_ = a;  }

template<class T>
void Container<T>::swap(Container<T> &a){
	std::swap(size_, a.size_);
	std::swap(p_, a.p_);
}

template<class T>
void Container<T>::push_back(const T a)
{
	T *tmp = new T[size_];
	for(size_t i = 0; i != size_; i++)
   		tmp[i] = p_[i];
	size_ += 1;
	for(size_t i = 0; i != size_; i++)
   		p_[i] = tmp[i];
  	p_[size_ - 1] = a;
}

template<class T>
Container<T> & Container<T>::operator=(const Container<T> &a){
  if (this != &a) Container<T>(a).swap(*this);
  return *this;
}

template<class T>
Container<T> Container<T>::operator+(const Container<T> &b){
	if (typeid(T).name() == typeid(int).name()){
		Container<T> C(b.size());
		for (size_t i = 0; i != b.size(); i++){
			C[i] = b[i] + p_[i];
		}
		for (size_t i = 0; i != C.size() - 1; i++){
			if (C[i] / 10 < 1) continue;
		 	else {
		 		if (i == 0) C.push_back(0);
		 		C[i + 1] += C[i] / 10;
		   	C[i] %= 10;
		 	};
		}
		return C; //R value
	}
	if (typeid(T).name() == typeid(char).name()){
		Container<T> C(b.size() + size_);
		for (size_t i = 0; i != C.size(); i++){
			if (b[i])	C[i] = p_[i];
			else C[i] = b[i];
		}
		return C; //R value
	}
}

template<class T>
Container<T>::~Container(){
	delete [] p_;
}