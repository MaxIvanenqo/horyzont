#include <iostream>
struct Point
{
   int x, y;
} a[4], b[4];

class Figure
{
protected:
	int coords[4];
public:
	Figure(const int a, const int b, const int c, const int d)
	{
		this->coords[0] = a;
		this->coords[1] = b;
		this->coords[2] = c;
		this->coords[3] = d;
	//	std::cout<<"constructor Figure"<<std::endl;
	};
	int& operator[](const int i){
		return this->coords[i];
	}
	int operator[](const int i) const{
		return this->coords[i];
	}
	virtual ~Figure()
	{
	//	std::cout<<"destructor Figure"<<std::endl;
	};
};


class L : public Figure
{
public:
	L():Figure(2,3,5,7)
	{
		std::cout<<"constructor L"<<std::endl;
	};
	~L()
	{
		std::cout<<"desctructor L"<<std::endl;
	};
};

class J : public Figure
{
public:
	J():Figure(3,5,7,6)
	{
		std::cout<<"constructor J"<<std::endl;
	};
	~J()
	{
		std::cout<<"desctructor J"<<std::endl;
	};
};

class I : public Figure
{
public:
	I():Figure(1,3,5,7)
	{
		std::cout<<"constructor I"<<std::endl;
	};
	~I()
	{
		std::cout<<"desctructor I"<<std::endl;
	};
};

class S : public Figure
{
public:
	S():Figure(3,5,4,6)
	{
		std::cout<<"constructor S"<<std::endl;
	};
	~S()
	{
		std::cout<<"desctructor S"<<std::endl;
	};
};

class Square : public Figure
{
public:
	Square():Figure(2,3,4,5)
	{
		std::cout<<"constructor Square"<<std::endl;
	}
	~Square()
	{
		std::cout<<"destructor Square"<<std::endl;
	};
};

class Z : public Figure
{
public:
	Z():Figure(2,4,5,7)
	{
		std::cout<<"constructor Z"<<std::endl;
	};

	~Z()
	{
		std::cout<<"destructor Z"<<std::endl;
	};
};

class T : public Figure
{
public:
	T():Figure(3,5,4,7)
	{
		std::cout<<"constructor T"<<std::endl;
	};
	~T()
	{
		std::cout<<"destructor T"<<std::endl;
	};
};