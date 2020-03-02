#pragma once
#include <iostream>
#include <vector>
#include <string>

class bigNumber{
public:
	static int ascii_;
	bigNumber(const int &a = 1);
	bigNumber(std::vector<int> &c, int &length);
	bigNumber operator*(int x);
	bigNumber operator=(const bigNumber &a);
	friend std::ostream & operator<<(std::ostream &a, const bigNumber &bn);
	~bigNumber();
private:
	int *p;
	int size = 0;
};