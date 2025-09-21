#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include "snake.h"

using namespace sf;
using namespace std;


SNAKE::SNAKE(size_t windowWidth ,size_t windowHeight , int & score){
        this->snakePrincipal.setFillColor(Color::Blue);
        this->snakePrincipal.setSize(Vector2f(25.f,25.f));
        this->snakePrincipal.setPosition(windowWidth /2, windowHeight/2);
        this->snake.push_back(snakePrincipal);
        snakeTimer=0;
        score = 0;
    }

void SNAKE::touchItSelf(int & permut)
{
    //intersection de SNAKE avec lui
        for(int i=0 ; i<this->snake.size() ; i++)
        {
            for(int j=0 ; j<this->snake.size() ; j++)
            {
                if(j != i)
                {
                    if(this->snake[i].getGlobalBounds().intersects(this->snake[j].getGlobalBounds()))
                    {
                        permut = 1; // echec;
                    }
                }
            }

        }
}

RectangleShape SNAKE::getSnakePrincipal(){
    return this->snakePrincipal;
}

void SNAKE::incrementerSnakeTimer(){
    this->snakeTimer++;
}

void SNAKE::snakeOriginMove(size_t windowWidth , size_t windowHeight , Vector2f & nextPosition , Vector2f & prevPosition){
            snakeTimer=0;
            nextPosition=snake[0].getPosition();
            prevPosition=snake[0].getPosition();
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                snake[0].move(0,-snake[0].getSize().y);
                if(snake[0].getPosition().y<0)
                {
                    snake[0].setPosition(snake[0].getPosition().x,windowHeight-snake[0].getSize().y);
                }

            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                snake[0].move(0,snake[0].getSize().x);
                if(snake[0].getPosition().y >= windowHeight)
                {
                    snake[0].setPosition(snake[0].getPosition().x,0);
                }

            }
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                snake[0].move(-snake[0].getSize().x,0);
                if(snake[0].getPosition().x<0)
                {
                    snake[0].setPosition(windowWidth-snake[0].getSize().x,snake[0].getPosition().y);
                }

            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                snake[0].move(snake[0].getSize().x,0);
                if(snake[0].getPosition().x >= windowWidth)
                {
                    snake[0].setPosition(0,snake[0].getPosition().y);
                }

            }
}

int SNAKE::getSnakeTimer(){
    return this->snakeTimer;
}

void SNAKE::snakeRestMove(Vector2f & nextPosition , Vector2f & prevPosition){
    for(size_t i=1;i<snake.size() ; i++)
            {
                prevPosition = snake[i].getPosition();
                snake[i].setPosition(nextPosition);
                nextPosition = prevPosition ;
            }
}

void SNAKE::drawSnake(RenderWindow &window){
    for(size_t i=0;i<snake.size() ; i++)
                window.draw(snake[i]);
}

RectangleShape SNAKE::getSnakeHead(){
    return this->snake[0];
}

void SNAKE::addSN(float f1,float f2){
    this->snake.push_back(this->snakePrincipal);
    snake[snake.size()-1].setPosition(f1,f2);
}
