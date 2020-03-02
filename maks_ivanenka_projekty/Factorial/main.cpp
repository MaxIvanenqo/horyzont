#include <iostream>
#include "class/container.cpp"
#include "class/bignumber.cpp"

bigNumber factorial(void){
	bigNumber B;
	int a;
	std::cout << "Enter a number: ";
	std::cin >> a;
	for (int i = 1; i <= a; i++){
		B = B * i;
	}
	std::cout << a << "! = " << B;
	return B;
}

int main(){
  factorial();
  Container<int> a(5, 3);
  Container<int> b(6, 3);

  Container<int> c = a + b;
  
  std::cout<<c<<std::endl;

  Container<char> q('a', 3);
  Container<char> w('b', 3);

  Container<char> e = q + w;

  std::cout<<e<<std::endl;

	return 0;
}