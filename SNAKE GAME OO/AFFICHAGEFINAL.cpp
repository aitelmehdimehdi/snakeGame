#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"AFFICHAGEFINAL.hpp"

using namespace sf;
using namespace std;

FinalPage::FinalPage(){
    text1.setPosition(0.f,0.f);
    text1.setFillColor(Color::Red);
    text1.setString("THANKS");
    text1.setCharacterSize(10);
    text1.setColor(Color::Red);
}

void FinalPage::drawText(RenderWindow & window){
    window.clear();
    window.draw(this->text1);
}
