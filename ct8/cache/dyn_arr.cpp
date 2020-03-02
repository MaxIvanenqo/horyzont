#include "dyn_arr.h"

dyn_arr::dyn_arr(const int n): size_(n), zap(0)
{
	arr = new T[n];
};
dyn_arr::~dyn_arr()
{
	delete[] arr;
};

int dyn_arr::size() const noexcept{
    return this->size_;
};
int dyn_arr::getZap() const noexcept{
	return this->zap;
};

std::ostream& operator<< (std::ostream & a, const dyn_arr & d){
	a << "[";
	for (int i = 0; i < d.zap; ++i){
		a << d.arr[i];
		if (i < d.zap - 1){
			a << ", ";
		}
	}
	a << "]" << std::endl;
	return a;
}

T &dyn_arr::operator[](int i){
	if (i < 0 || i >= size_){
		throw std::out_of_range("index spoza zakresu");
	}
	else return arr[i];
}
T dyn_arr::operator[](int i) const{
	if (i < 0 || i >= size_){
		throw std::out_of_range("index spoza zakresu");
	}
	else return arr[i];
}
T dyn_arr::top(){
	return this->arr[0];
}
void dyn_arr::push(T x){
	powieksz();
	this->arr[getZap()] = x;
	zapIncrease();
}

void dyn_arr::pop(){
	if (this->zap == 0){
		throw std::out_of_range("index spoza zakresu");
	}
	this->zap--;
	pomniejsz();
	if (this->zap > 1){
		T * tmp = new T[this->size()];
		for (int i = 1; i <= zap; ++i){
			tmp[i - 1] = this->arr[i];
		}
		for (int i = 0; i <= zap; ++i){
			this->arr[i] = tmp[i];
		}
		delete[] tmp;
	}
}

void dyn_arr::pomniejsz(){
	if (this->getZap() <= this->size() / 4) sizeDecrease();
}

void dyn_arr::powieksz(){
	if (this->getZap() == this->size())	sizeIncrease();
}



void dyn_arr::sizeIncrease(){
	this->size_ *= 2;
	T * tmp = new T[this->size_];
	for (size_t i = 0; i < this->size_; ++i){
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = tmp;
};
void dyn_arr::sizeDecrease(){
	this->size_ /= 2;
	T * tmp = new T[this->size_];
	for (size_t i = 0; i < this->size_; ++i){
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = tmp;
};