#include <iostream>
#include <math.h>
#include <iomanip>
#include "dot.h"
#include "vector.h"

int main()
{
	Dot a(3.0f, 3.0f, 3.0f);
	Dot b(1.0f, 1.0f, 1.0f);

	Vector AB(a, b);

	Dot c(2.0f, 2.0f, 2.0f);
	Dot d(4.0f, 4.0f, 4.0f);

	Vector CD(c, d);

	Vector AD = AB - CD;

	std::cout<<"AB: "<<AB<<std::endl;
	std::cout<<"CD: "<<CD<<std::endl;
	std::cout<<"AD: "<<AD<<std::endl;

	std::cout<<"iloczyn skalarny AB i CD z katem 0: "<<AB.dotproduct(CD, 0)<<std::endl;
	std::cout<<"iloczyn skalarny AB i CD z katem 90: "<<AB.dotproduct(CD, 90)<<std::endl;
	std::cout<<"iloczyn skalarny AB i CD z katem 180: "<<AB.dotproduct(CD, 180)<<std::endl;

	return 0;
}