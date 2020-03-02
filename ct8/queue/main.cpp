#include <iostream>
#include "queue.cpp"

int main()
{
	queue Q;
	Q.enqueue(1);
	std::cout<<Q;
	Q.enqueue(2);
	std::cout<<Q;
	Q.enqueue(3);
	std::cout<<Q;
	Q.enqueue(4);
	std::cout<<Q;
	Q.enqueue(5);
	std::cout<<Q;
	Q.enqueue(6);
	std::cout<<Q;
	Q.enqueue(7);
	std::cout<<Q;
	Q.enqueue(8);
	std::cout<<Q;
	Q.enqueue(9);
	std::cout<<Q;
	std::cout<<Q.dequeue()<<std::endl;
	std::cout<<Q;
	std::cout<<"front = "<<Q.front()<<std::endl;
	std::cout<<Q;
	return 0;
}