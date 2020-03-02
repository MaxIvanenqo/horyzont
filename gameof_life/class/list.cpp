#include "list.h"
#include <stdexcept>

void List::push_back(TYPE data){
	if (this->empty()){
		Node * current = new Node(data, nullptr, nullptr);
		this->head = current;
	}
	else {
		Node * current = this->head;
		while (current->pNext != nullptr){
			current = current->pNext;
		}
		current->pNext = new Node(data, nullptr, current);
	}
	size_++;
}

void List::push_front(TYPE data){
	head = new Node(data, head, nullptr);
	size_++;
}

void List::insert(const int pos, TYPE data){
    if (pos < 0) 
    	throw std::invalid_argument("ujemna pozycja");
    if (pos >= getSize()) 
    	throw std::range_error("pozycja spoza listy");
	if (pos == 0) push_front(data);
	else{
		Node *prev = this->head;
		int counter = 0;
		while (counter < pos - 1){
			counter++;
			prev = prev->pNext;
		}
		Node *tmp = new Node(data, prev->pNext, prev);
		prev->pNext = tmp;
		size_++;
	}
}

void List::pop_front(){
	Node * tmp = this->head;
	if (head->pNext) head = head->pNext;
	else 			 head = nullptr;
	this->size_--;
	delete tmp;
}

void List::clear(){
	if (this->head) 
		while (!this->empty()) pop_front();
}

TYPE & List::operator[](const int i){
	Node * current = this->head;
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
TYPE & List::operator[](const int i) const {
	Node * current = this->head;
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

int List::length(){
	if (this->empty()) return 0;
	else{
	    int s = 1;
	    Node *tmp = head;
	    while (tmp->pNext){
			tmp = tmp->pNext;
	        s++;
		}
	    return s;
	}
}
void List::concatenate(List &lst){
    Node *lst_last = lst.head;
    this->push_back(lst_last->data);
    while(lst_last->pNext){
        lst_last = lst_last->pNext;
        this->push_back(lst_last->data);
    }
    lst.clear();
    lst.head = nullptr;
}

void List::reverse(){
	if (!this->empty()){
		Node * current = this->head;
    	while (current->pNext != nullptr){
        	current = current->pNext;
    	}
	    List * tmp = new List();
	    while (current->pPrev){
	        tmp->push_back(current->data);
	        current = current->pPrev;
	    }
	    tmp->push_back(current->data);
	    this->head = tmp->head;
	}
}


void List::remove(int pos) {
    if (pos < 0 || pos >= getSize()) throw std::range_error("pozycja spoza listy");
    if (pos == 0) pop_front();
    else{
    	Node * current = this->head;
		int counter = 0;
		while (current != nullptr){
			if (counter + 1 == pos){
				current->pNext = current->pNext->pNext;
				current->pNext->pPrev = current;
				break;
			}
			else{
				current = current->pNext;
				counter++;
			}
		}
		this->size_--;
    }
}
void List::removeall(const TYPE &x) {
  if (empty()) return;
	Node * current = this->head;
	int counter = 0;
	while (current != nullptr){
		if (current->data == x) {
			this->remove(counter);
			counter--;
		}
		current = current->pNext;
		counter++;
	}
}
bool List::empty() const {
    return this->head == nullptr;
}
bool List::search(const int x, const int y) const {
  if (empty()) return false;
	Node * current = this->head;
	int counter = 0;
	while (current != nullptr){
		if (current->data.first == x && current->data.second == y) return true;
		current = current->pNext;
		counter++;
	}
}

int List::searchAndGetIndex(const int x, const int y) const{
	if (!empty()){
		int index = 0;
		Node * current = this->head;
		int counter = 0;
		while (current != nullptr){
			if (current->data.first == x && current->data.second == y) return index;
			index++;
			current = current->pNext;
			counter++;
		}
		return -1;
	}
};