#include <iostream>
#include "node.h"
#include "list.cpp"

int main()
{
	List<int> q;
	q.push_back(1);
	q.push_back(4);
	q.push_back(10);
	q.push_front(5);
    q.insert(0, 2);
	std::cout<<q[0]<<std::endl;
	return 0;
}