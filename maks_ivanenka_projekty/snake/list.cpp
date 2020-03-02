#include "list.h"
template<class T>
void List<T>::push_back(T data){
	if (this->head == nullptr){
		Node<T> * current = new Node<T>(data, nullptr);
		this->head = current;
	}
	else {
		Node<T> * current = this->head;
		while (current->pNext != nullptr){
			current = current->pNext;
		}
		current->pNext = new Node<T>(data, nullptr);
	}
	size_++;
}


template<class T>
void List<T>::push_front(T data){
	head = new Node<T>(data, head);
	size_++;
}


template<class T>
void List<T>::insert(const int i, T data){
	if (i == 0) push_front(data);
	else{
		Node<T> *prev = this->head;
		int counter = 0;
		while (counter < i-1){
			counter++;
			prev = prev->pNext;
		}
		Node<T> *tmp = new Node<T>(data, prev->pNext);
		prev->pNext = tmp;
		size_++;
	}
}

template<class T>
void List<T>::pop_front(){
	Node<T> *tmp = head;
	head = head->pNext;
	delete tmp;
	size_--;
}


template<class T>
void List<T>::clear(){
	while (size_ >= 0)
		pop_front();
}


template<class T>
T & List<T>::operator[](const int i){
		Node<T> * current = this->head;
		int counter = 0;
		while (current != nullptr){
			if (counter == i){
				return current->data;
			}
			else{
				current = current->pNext;
				counter++;
			}
		}
	}