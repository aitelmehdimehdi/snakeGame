#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;


class EndText{
    Text gameOver;
    Text Score;
public:
    EndText(int score,string endtext,size_t windowHeigth,size_t windowWidth);
    Text getGameOver();
};
