#include <iostream>
#include "node.h"
#include "list.cpp"
#include <string>
#include "stdlib.h"
#include <SFML/Graphics.hpp>

int sizeRect = 0;
int direction = 0;
bool gameRun = false;
void getDirection(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (direction != 2){
			direction = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (direction != 1){
		  direction = 2;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (direction != 4){
		  direction = 3;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (direction != 3){
		  direction = 4;
		}
	}
}

void turn(List<sf::CircleShape> &Snake, int i, sf::RenderWindow &window){
	int newHeadX = 0;
	int newHeadY = 0;
	if (i == 0){
		switch(direction){
			case 1:{
				newHeadX = Snake[0].getPosition().x - 2;
				newHeadY = Snake[0].getPosition().y;
				break;
			}
			case 2:{
				newHeadX = Snake[0].getPosition().x + 2;
				newHeadY = Snake[0].getPosition().y;
				break;
			}
			case 3:{
				newHeadY = Snake[0].getPosition().y - 2;
				newHeadX = Snake[0].getPosition().x;
				break;
			}
			case 4:{
				newHeadY = Snake[0].getPosition().y + 2;
				newHeadX = Snake[0].getPosition().x;
				break;
			}
		}
		for (int i = Snake.getSize() - 1; i > 0; --i){
			Snake[i].setPosition(Snake[i-1].getPosition().x, Snake[i-1].getPosition().y);
		}
		Snake[0].setPosition(newHeadX, newHeadY);
		for (int i = 1; i < Snake.getSize(); ++i){
			if (Snake[0].getPosition().x == Snake[i].getPosition().x && Snake[0].getPosition().y == Snake[i].getPosition().y){
				gameRun = false;
			  sf::Font font;
				if (!font.loadFromFile("./font/7fonts.ru_nsecthck.ttf"))
				{
				    std::cout<<"file doesn't exist..."<<std::endl;
				}
				std::string gameOverText = "Game Over!";
			  sf::Text gameOver;
			  gameOver.setPosition(290, 250);
			  gameOver.setFont(font);
				gameOver.setCharacterSize(50);
				gameOver.setFillColor(sf::Color::White);
				gameOver.setString(gameOverText);
				window.draw(gameOver);
				break;
			}
		}
		for (int i = 0; i < Snake.getSize(); ++i){
			if (Snake[i].getPosition().x > 800){
				Snake[i].setPosition(0, Snake[i].getPosition().y);
			}
			if (Snake[i].getPosition().y > 600){
				Snake[i].setPosition(Snake[i].getPosition().x, 0);
			}
			if (Snake[i].getPosition().x < 0){
			  Snake[i].setPosition(800, Snake[i].getPosition().y);
			}
			if (Snake[i].getPosition().y < 0){
				Snake[i].setPosition(Snake[i].getPosition().x, 600);
			}
		}
	}
}

List<sf::CircleShape> initSnake(){
	List<sf::CircleShape> Snake;
	sf::CircleShape snakeShape(5, 30);
	snakeShape.setFillColor(sf::Color(255, 0, 0));
  snakeShape.setPosition(0, 0);
  Snake.push_front(snakeShape);
  return Snake;
}

void initFeed(sf::RenderWindow &window, int &x, int &y){
	sf::CircleShape shapeFeed(4, 40);
	shapeFeed.setFillColor(sf::Color(100, 255, 0));
  shapeFeed.setPosition(x, y);
  window.draw(shapeFeed);
}

void catchCheck(int &feedX, int &feedY, int xpos, int ypos,  List<sf::CircleShape> &Snake){
	if ( ( xpos > feedX - sizeRect) 
		&& ( xpos < feedX + sizeRect)
		&& ( ypos > feedY - sizeRect)
		&& ( ypos < feedY + sizeRect))
		{
			sf::CircleShape snakeShape(5, 30);
			snakeShape.setFillColor(sf::Color(255, 0, 0));
			Snake.push_back(snakeShape);
			feedX = rand() % 800;
			feedY = rand() % 600;
		}
}

void game(){
	sizeRect = 10;
	direction = 2;
	gameRun = true;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake");
	int feedX = rand() % 800;
	int feedY = rand() % 600;
	bool feedCatched = false;
  
  sf::Font font;
	if (!font.loadFromFile("./font/7fonts.ru_nsecthck.ttf"))
	{
	    std::cout<<"file doesn't exist..."<<std::endl;
	}
	std::string textCst = "Points: ";

  sf::Text textPoints;
  textPoints.setPosition(350, 650);
  textPoints.setFont(font);
	textPoints.setCharacterSize(32);
	textPoints.setFillColor(sf::Color::White);
  sf::Clock clock;

  List<sf::CircleShape> Snake = initSnake();
  
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
    	if (event.type == sf::Event::Closed) window.close();
    }
    int speed = 10;
    sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds() > speed && gameRun) {
			int xpos = Snake[0].getPosition().x;
			int ypos = Snake[0].getPosition().y;
		  getDirection();

		  window.clear(sf::Color(20, 20, 30, 255));

		  catchCheck(feedX, feedY, xpos, ypos, Snake);
		  initFeed(window, feedX, feedY);
		  for (int i = 0; i < Snake.getSize(); ++i){
		  	turn(Snake, i, window);
		  	window.draw(Snake[i]);
		  }
		  std::string textPts = std::to_string(Snake.getSize() - 1);
			std::string textOutputPts = textCst + textPts;
			textPoints.setString(textOutputPts);
			window.draw(textPoints);

  		window.display();
  		clock.restart();

		}	
  }
}

int main()
{ 
  game();
  return 0;
}