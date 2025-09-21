#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

class SNAKE{
private:
    sf::RectangleShape snake;
    int snakeTimer;
public :
    SNAKE(RenderWindow window)
    {
        this->snake.setFillColor(Color::Blue);
        this->snake.setSize(Vector2f(12.5,12.5));
        this->snake.setPosition(window.getSize().x /2, window.getSize().y/2);
        snakeTimer=0;
    }
    SNAKE();


};
