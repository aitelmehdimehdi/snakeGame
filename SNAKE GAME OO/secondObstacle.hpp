#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"snake.h"

using namespace sf;
using namespace std;

class secondObstacle{
private:
    RectangleShape  specialObstacle;
    int timerSpecialObstacle;
    int specialObstacleExist;
};
