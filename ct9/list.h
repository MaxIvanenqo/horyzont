#pragma once
#include <iostream>

typedef int TYPE;
class List
{
public:
	List():size_(0), head(nullptr)						{};
	List(const List &lst) = delete;
  List& operator = (const List &lst) = delete;
	void clear();
	void pop_front();
  int length();
  void concatenate(List &lst);
  void reverse();
	void insert(const int pos, TYPE data);
	void push_front(TYPE data);
	void push_back(TYPE data);
	void remove(int pos);
  void removeall(const TYPE &x);
  bool empty() const;
  bool search(const TYPE &x) const;
  friend std::ostream& operator<< (std::ostream & a, const List & lst){
    Node *tmp = lst.head;
    a << "[" << *tmp;
    while (tmp->pNext){
      tmp = tmp->pNext;
      a << ", " << *tmp;
    } 
    a << "]" << std::endl;
  };
  int getSize()										{return size_;	};
	TYPE & operator[](const int i);
  TYPE & operator[](const int i) const;
  ~List()												{clear();		};
private:
	class Node{
		public:
		  Node * pNext;
      Node * pPrev;
		  TYPE data;
			Node(const TYPE data = TYPE(), Node *pNext = nullptr, Node *pPrev = nullptr){
				this->data = data;
				this->pNext = pNext;
			 	this->pPrev = pPrev;
			};
      friend std::ostream& operator<< (std::ostream & a, const Node & nd){
      	a << nd.data;
      };
		~Node(){}
	};
  int getData(){
    return head->data;
  }
	Node *head;
	int size_;
	int count = 0;
};