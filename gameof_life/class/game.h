#pragma once
#include "list.cpp"
#include <utility>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#define sizeCircle 16;

class Game
{
private:
    std::vector<sf::CircleShape> alive;
    std::vector<sf::CircleShape> mesh;
public:
    Game(const std::vector<std::pair<int,int>> &V){
        for (int i = 1; i <= 50; ++i)
            for (int j = 1; j <= 50; j+= 1){
                sf::CircleShape circleDead;
                circleDead.setRadius(6);
                circleDead.setOutlineColor(sf::Color::Black);
                circleDead.setPosition(i*= 6, j*= 6);
                this->mesh.emplace_back(circleDead);
            }
        for (int i = 0; i < V.size(); ++i){
            sf::CircleShape circleAlive;
            circleAlive.setRadius(6);
            circleAlive.setOutlineColor(sf::Color::Black);
            circleAlive.setPosition(V[i].first * 6, V[i].second * 6);
            this->alive.emplace_back(circleAlive);
        }
        this->run();
    };
    void correctNeibourhood(){

    }

    void check(){
        for (int i = 0; i < mesh.size(); ++i){
            for (int j = 0; j < alive.size(); ++j){
                
            }
        }
    }

    void run(){
        sf::RenderWindow window(sf::VideoMode(800, 800), "Game of life");
        sf::Clock clock;
        while (window.isOpen()){
            sf::Event event;
                while (window.pollEvent(event)){
                    if (event.type == sf::Event::Closed) window.close();
                }
            int speed = 100;
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asMilliseconds() > speed) {
                check();
                for(auto var : alive){
                    window.draw(var);
                }
                window.display();
                clock.restart();
            }	
        }
    }
    ~Game(){};
};