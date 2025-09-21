#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include <time.h>
#include "laNouriture.hpp"

using namespace sf;
using namespace std;

Nouriture::Nouriture(SNAKE snake , size_t width , size_t height){
    nouritureNormal.setFillColor(Color::Green);
    nouritureNormal.setRadius(18.f);
    nouritureSpecial.setFillColor(Color::Red);
    nouritureSpecial.setRadius(21.f);
    nouritureSpecial.setOutlineThickness(1.5);
    nouritureSpecial.setOutlineColor(Color ::Magenta);
    nouritureSpecial.setPosition(Vector2f(-50.f , -50.f));
    this->timerNouritureSpecial=0;
    this->timerExistanceNouritureSpecial=0;
    depA=0;
    depB=0;
    this->hideSpecialNouriture();
    this->depNormalNouriture(snake,width,height);

}

void Nouriture::depNormalNouriture(SNAKE snake , size_t windowWidth , size_t windowHeight){
    depA = (int)rand()%(int)(windowWidth/snake.getSnakePrincipal().getSize().x);
    depA *= snake.getSnakePrincipal().getSize().x;
    depA += snake.getSnakePrincipal().getSize().x/2;
    depA -= nouritureNormal.getRadius();
    depB = (int)rand()%(int)(windowHeight/snake.getSnakePrincipal().getSize().y);
    depB *= snake.getSnakePrincipal().getSize().y;
    depB += snake.getSnakePrincipal().getSize().y/2;
    depB -= nouritureNormal.getRadius();
    nouritureNormal.setPosition(depA,depB);
}

int Nouriture::getTimerNouritureSpecial(){
    return this->timerNouritureSpecial;
}

int Nouriture::getTimerExistanceNouritureSpecial(){
    return this->timerExistanceNouritureSpecial;
}

void Nouriture::depSpecialNouriture(SNAKE snake, size_t windowWidth , size_t windowHeight){
    if(this->getTimerNouritureSpecial() < 300)
            this->incrementerTimerNouritureSpecial();
    if(this->getTimerNouritureSpecial() >= 300)
    {
        this->timerExistanceNouritureSpecial=0;
        this->timerNouritureSpecial=0;
        depA = (int)rand()%(int)(windowWidth/snake.getSnakePrincipal().getSize().x);
        depA *= snake.getSnakePrincipal().getSize().x;
        depA += snake.getSnakePrincipal().getSize().x/2;
        depA -= nouritureNormal.getRadius();
        depB = (int)rand()%(int)(windowHeight/snake.getSnakePrincipal().getSize().y);
        depB *= snake.getSnakePrincipal().getSize().y;
        depB += snake.getSnakePrincipal().getSize().y/2;
        depB -= nouritureNormal.getRadius();
        this->nouritureSpecial.setPosition(depA,depA);
    }
}

void Nouriture::incrementerTimerNouritureSpecial(){
    timerNouritureSpecial++;
}

void Nouriture::incrementerTimerExistanceNouritureSpecial(){
    timerExistanceNouritureSpecial++;
}

void Nouriture::hideSpecialNouriture(){
    if(this->getTimerExistanceNouritureSpecial()<200)
            this->incrementerTimerExistanceNouritureSpecial();
    if(this->getTimerExistanceNouritureSpecial() >= 200)
    {
        this->getNouritureSpecial().setPosition(-250.f , -250.f);
    }
}

CircleShape Nouriture::getNouritureSpecial(){
    return this->nouritureSpecial;
}

void Nouriture::drawNouriture(RenderWindow &window){
    window.draw(this->getNouritureSpecial());
    window.draw(this->nouritureNormal);
}


CircleShape Nouriture::getNouritureNormal(){
    return this->nouritureNormal;
}

void METHODE::intersectionDeSnakeWNouriture(SNAKE & snake  , Nouriture & nouriture ,size_t windowWidth , size_t windowHeight , int & score){
    if(snake.getSnakeHead().getGlobalBounds().intersects(nouriture.getNouritureNormal().getGlobalBounds())){
            score++;
            float f=-350;
            nouriture.depNormalNouriture(snake,windowWidth,windowHeight);
            snake.addSN(f,f);
    }
}

void METHODE::intersectionDeSnakeWNouritureSpe(SNAKE & snake  , Nouriture & nouriture ,size_t windowWidth , size_t windowHeight , int & score)
{
    if(snake.getSnakeHead().getGlobalBounds().intersects(nouriture.getNouritureSpecial().getGlobalBounds())){
            score++;
            float f=-350;
            nouriture.depSpecialNouriture(snake,windowWidth,windowHeight);
            snake.addSN(f,f);
    }
}


