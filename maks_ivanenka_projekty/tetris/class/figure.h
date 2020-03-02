#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Figure
{
public:
	int sizeBlock = 15;
	Figure(const int blockQuantity = 0):
	  Coords(blockQuantity),
	  size(blockQuantity)
	{};
	virtual ~Figure(){};
	std::vector<int[2]> Coords;
	int size;
};


class L_form: public Figure
{
public:
	L_form(const int blockQuantity = 4): Figure(blockQuantity){
		Coords[0][0] = 0;
		Coords[0][1] = sizeBlock;

		Coords[1][0] = 0;
		Coords[1][1] = 0;

		Coords[2][0] = 0;
		Coords[2][1] = -sizeBlock;

		Coords[3][0] = sizeBlock;
		Coords[3][1] = 0;
	};
	~L_form(){};
};

class Cross_form: public Figure
{
public:
	Cross_form(const int blockQuantity = 5): Figure(blockQuantity){
		Coords[0][0] = 0;
		Coords[0][1] = sizeBlock;

		Coords[1][0] = 0;
		Coords[1][1] = 0;

		Coords[2][0] = 0;
		Coords[2][1] = -sizeBlock;

		Coords[3][0] = sizeBlock;
		Coords[3][1] = 0;

		Coords[4][0] = -sizeBlock;
		Coords[4][1] = 0;
	};
	~Cross_form(){};
};

class Square_form: public Figure
{
public:
	Square_form(const int blockQuantity = 4): Figure(blockQuantity){
		Coords[0][0] = -sizeBlock;
		Coords[0][1] = sizeBlock;

		Coords[1][0] = sizeBlock;
		Coords[1][1] = sizeBlock;

		Coords[2][0] = sizeBlock;
		Coords[2][1] = -sizeBlock;

		Coords[3][0] = -sizeBlock;
		Coords[3][1] = -sizeBlock;

	};
	~Square_form(){};
};

class Stick_form: public Figure
{
public:
	Stick_form(const int blockQuantity = 4): Figure(blockQuantity){
		Coords[0][0] = 0;
		Coords[0][1] = -sizeBlock;

		Coords[1][0] = 0;
		Coords[1][1] = 0;

		Coords[2][0] = 0;
		Coords[2][1] = sizeBlock;

		Coords[3][0] = 0;
		Coords[3][1] = 2*sizeBlock;
	};
	~Stick_form(){};
};