#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

class SNAKE{
private:
    sf::RectangleShape snakePrincipal;
    std::vector<RectangleShape> snake;
    int snakeTimer;
public :
    SNAKE(size_t windowWidth , size_t windowHeight , int & score);
    void addSN(float f1,float f2);
    RectangleShape getSnakeHead();
    int getSnakeTimer();
    void incrementerSnakeTimer();
    void snakeOriginMove(size_t windowWidth , size_t windowHeight , Vector2f & nextPosition , Vector2f & prevPosition);
    void snakeRestMove(Vector2f & nextPosition , Vector2f & prevPosition);
    void drawSnake(RenderWindow &window);
    RectangleShape getSnakePrincipal();
    void touchItSelf(int & permut);

};
