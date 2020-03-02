#include "queue.h"

queue::queue(const int n): size_(n), zap(0)
{
	arr = new T[n];
};
queue::~queue()
{
	delete[] arr;
};

int queue::size() const noexcept{
    return this->size_;
};

std::ostream& operator<< (std::ostream & a, const queue & d){
	a << "[";
	for (int i = 0; i < d.zap; ++i){
		a << d.arr[i];
		if (i < d.zap - 1){
			a << ", ";
		}
	}
	a << "]" << std::endl;
	a << "size: " << d.size() << ", zap: " << d.zap << std::endl;
	return a;
}

T &queue::operator[](int i){
	if (i < 0 || i >= this->getZap()){
		throw std::out_of_range("index spoza zakresu");
	}
	else return arr[i];
}
T queue::operator[](int i) const{
	if (i < 0 || i >= this->getZap()){
		throw std::out_of_range("index spoza zakresu");
	}
	else return arr[i];
}
T queue::front(){
	return this->arr[0];
}
void queue::enqueue(T x){
	powieksz();
	this->arr[zap] = x;
	zapIncrease();
}

T queue::dequeue(){
	T elem = this->arr[0];
	if (this->getZap() == 0){
		throw std::out_of_range("index spoza zakresu");
	}
	zapDecrease();
	pomniejsz();
	if (this->getZap() > 1){
		T * tmp = new T[this->size()];
		for (int i = 1; i <= this->getZap(); ++i){
			tmp[i - 1] = this->arr[i];
		}
		for (int i = 0; i <= this->getZap(); ++i){
			this->arr[i] = tmp[i];
		}
		delete[] tmp;
	}
	return elem;
}


void queue::pomniejsz(){
	if (this->getZap() <= this->size() / 4) sizeDecrease();
}

void queue::powieksz(){
	if (this->getZap() == this->size())	sizeIncrease();
}

void queue::sizeIncrease(){
	this->size_ *= 2;
	T * tmp = new T[this->size_];
	for (size_t i = 0; i < this->size_; ++i){
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = tmp;
};
void queue::sizeDecrease(){
	this->size_ /= 2;
	T * tmp = new T[this->size_];
	for (size_t i = 0; i < this->size_; ++i){
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = tmp;
};