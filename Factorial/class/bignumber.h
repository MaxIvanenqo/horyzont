#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "container.h"

class bigNumber{
public:
	static int ascii_;
	bigNumber(const int &a = 1);
	bigNumber(std::vector<int> &c, int &length);
	bigNumber operator*(int &x);
	friend std::ostream & operator<<(std::ostream &a, const bigNumber &bn);

private:
	Container<int> V_;
	//std::vector<char> V_;
};