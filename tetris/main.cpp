#include <SFML/Graphics.hpp>
#include <time.h>
#include "figure.h"
using namespace sf;

const int rows = 30;
const int columns = 30;
const int sizeBlock = 18;
int field[rows][columns] = {0};
bool gameRun = false;

bool checkReachedDown()
{
   for (int i = 0; i < 4; i++)
	  if (a[i].x < 0 || 
				a[i].x >= columns || 
				a[i].y >= rows) 
		return 0;
    else if (field[a[i].y][a[i].x]) 
		return 0;
  return 1;
};

void rotate(){
	Point p = a[1];
	for (int i = 0; i < 4; i++)
	{
		int x = a[i].y - p.y;
		int y = a[i].x - p.x;
		a[i].x = p.x - x;
		a[i].y = p.y + y;
	}
  if (!checkReachedDown()) 
	  for (int i = 0; i < 4;i++) 
	 	 	a[i] = b[i];
}

void init(float &timer, float delay, Figure *figures){
	if (timer > delay){
	  for (int i = 0; i < 4; i++) 
		{ 
			b[i] = a[i]; 
			a[i].y += 1;
		}
		if (!checkReachedDown()){
			int n = rand() % 7;
			for (int i = 0; i < 4; i++) {
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		  for (int i = 0; i < 4; i++) 
		 	  field[b[i].y][b[i].x] = 1;
		}
	  timer = 0;
	}
}

void moveSides(int dx){
	for (int i = 0; i < 4; i++)  
	{
		b[i] = a[i];
		a[i].x += dx;
	}
  if (!checkReachedDown()) 
			for (int i = 0; i < 4; i++) 
				a[i] = b[i];
}

void checkKeyboardPress(Window &window, Event e, bool &rotate, int &dx, float &delay){
while (window.pollEvent(e))
    {
			if (e.type == Event::Closed)  window.close();
		 	if (e.type == Event::KeyPressed)
		  	if (e.key.code == Keyboard::Up) rotate = true;
		  	else if (e.key.code == Keyboard::Left) dx = -1;
		  	else if (e.key.code == Keyboard::Right) dx = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
}
void linesCounting(){
  int k = rows - 1;
	for (int i = rows - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < columns; j++)
		{
		    if (field[i][j]) count++;
		    field[k][j] = field[i][j];
		}
		if (count < rows) k--;
	}
}
void normalize(int &dx, bool &rotateBool, float &delay){
	dx = 0;
	rotateBool = 0;
	delay = 0.2;
}
void game(){
	gameRun = true;
	//Figures construct
	I i; Z z; S s; T t; L l; J j; Square o;
	Figure figures[7] = { i, z, s, t, l, j, o };

  srand(time(0));	 
	RenderWindow window(VideoMode(rows * sizeBlock, columns * sizeBlock), "Hello Tetris!");

	RectangleShape block(Vector2f(sizeBlock, sizeBlock));
	block.setOutlineThickness(1);
	block.setOutlineColor(sf::Color(0, 0, 0));

  int dx = 0; 
	bool rotateBool = false; 
	float timer = 0, delay = 0.2; 
	Clock clock;
  while (window.isOpen() && gameRun)
  {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
    Event e;
    checkKeyboardPress(window, e, rotateBool, dx, delay);
		init(timer, delay, figures);
		moveSides(dx);
		if (rotateBool) rotate();
		linesCounting();
		window.clear(sf::Color(20, 20, 30, 255));
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				{
					if (field[i][j] == 0) continue;
					block.setTextureRect(IntRect(field[i][j] * sizeBlock, 0, sizeBlock, sizeBlock));
					block.setPosition(j * sizeBlock, i * sizeBlock);
					window.draw(block);
				}
		for (int i = 0; i < 4; i++)
		{
			block.setTextureRect(IntRect(sizeBlock, 0, sizeBlock, sizeBlock));
			block.setPosition(a[i].x * sizeBlock, a[i].y * sizeBlock);
			window.draw(block);
		}
		window.display();
		normalize(dx, rotateBool, delay);
	}
	gameRun = false;
}


int main()
{
	game();
  return 0;
}