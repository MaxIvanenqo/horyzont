#include <iostream>
#include "dyn_arr.cpp"

int main()
{
	dyn_arr a;
	std::cout<<a;
	a.push(1);
	std::cout<<a;
	a.push(2);
	std::cout<<a;
	a.push(3);
	std::cout<<a;
	a.push(4);
	std::cout<<a;
	a.push(5);
	std::cout<<a;
	a.push(6);
	std::cout<<a;
	a.push(7);
	std::cout<<a;
	a.pop();
	std::cout<<a;
	std::cout<<"top: "<<a.top()<<std::endl;
	return 0;
}