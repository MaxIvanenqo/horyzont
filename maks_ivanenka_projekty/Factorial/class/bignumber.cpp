//valgrind

#include "bignumber.h"

 int bigNumber::ascii_ = 48;

bigNumber::bigNumber(const int &a){
	std::string str = std::to_string(a);
	V_.resize(str.size());
	for (int i = 0; i < str.size(); i++)
	  V_[i] = str[str.size() - i - 1] - bigNumber::ascii_;
}


bigNumber::bigNumber(std::vector<int> &c, int &length){
	V_.resize(0);
	for (int i = 0; i < length; i++) 
		V_.push_back(c[i]);
}


bigNumber bigNumber::operator*(int &x){
	std::string str = std::to_string(x);
	std::vector<int> B(str.size(), 0);
	for (int i=0; i < str.size(); i++)
  	B[i] = str[str.size()-i-1] - bigNumber::ascii_;

  int newTotalSize = V_.size() + B.size();
	std::vector<int> C(newTotalSize, 0);
	for (int i = 0; i < V_.size(); i++)
	  for (int j = 0; j < B.size(); j++)
	    C[i + j] += V_[i] * B[j];

	for (int i = 0; i < newTotalSize; i++){
		if (C[i] / 10 < 1) continue;
	 	else {
	 		C[i + 1] += C[i] / 10;
	   	C[i] %= 10;
	 	};
	}
  return bigNumber(C, newTotalSize);
}


std::ostream & operator<<(std::ostream &a, const bigNumber &bn){
	int counter = bn.V_.size() - 1;
	while (bn.V_[counter] == 0) counter--;
	for (int i = counter; i >= 0; i--)
		a << bn.V_[i];
	a<<std::endl;
	return a;
};
