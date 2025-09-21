#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"EndText.hpp"

using namespace sf;
using namespace std;

EndText::EndText(int score , string text ,size_t windowHeigth,size_t windowWidth)
{
    Font font;
    font.loadFromFile("arial.ttf");
    this->gameOver.setFillColor(Color::Green);
    this->gameOver.setCharacterSize(120);
    this->gameOver.setFont(font);
    this->gameOver.setString(text);
    this->Score.setCharacterSize(70);
    this->Score.setFont(font);
    this->Score.setString(to_string(score));
    gameOver.setPosition(windowWidth/2-((gameOver.getLocalBounds().width)/2),windowHeigth/2-((gameOver.getLocalBounds().height)*2));
    Score.setPosition(0,0);
}

Text EndText::getGameOver(){
return this->gameOver;
}



