//valgrind

#include "dynbignumber.h"

 int bigNumber::ascii_ = 48;

bigNumber::bigNumber(const int &a){
	std::string str = std::to_string(a);
	size = str.size();
	p = new int[size];
	for (int i = 0; i < str.size(); i++)
	  p[i] = str[i] - bigNumber::ascii_;
}
bigNumber bigNumber::operator=(const bigNumber &a){
	std::cout<<"operator= iteration size: "<<size<<std::endl;
	//if(this==&a) return *this;
	/*else{*/
     delete [] p;
     p = new int[a.size];
	for(int i = 0; i < a.size; i++){
		p[i] = a.p[i];
	}
	return *this;
	
}
bigNumber  bigNumber::operator*(int x){
	std::string str = std::to_string(x);

	int *b = new int[str.size()];

	for (int i=0; i < str.size(); i++)
  		b[i] = str[i] - bigNumber::ascii_;

    size += str.size();
  	bigNumber c(1);
	delete [] c.p;
	c.p = new int[size];
	for(int i = 0; i < size; i++)
		c.p[i] = 0;
std::cout<<"operator* iteration size: "<<size<<std::endl;
	for (int i = 0; i < size; i++)
	  for (int j = 0; j < str.size(); j++)
	    c.p[i + j] += p[i] * b[j];
	delete [] b;
	for (int i = 0; i < size; i++){
		if (c.p[i] / 10 < 1) continue;
	 	else {
	 		c.p[i + 1] += c.p[i] / 10;
	   		c.p[i] %= 10;
	 	};
	}
	return c;
}


std::ostream & operator<<(std::ostream &a, const bigNumber &bn){
	int counter = 0;
	while (bn.p[counter] == 0 && counter<bn.size-1) counter++;
	
	//a << std::endl << "Vector V_ length -> " << bn.size << std::endl;

	for (int i = 0; i <= bn.size-1; i++)
		a << bn.p[i];
	a<<std::endl;
	return a;
};


bigNumber::~bigNumber(){
	delete [] p;
};