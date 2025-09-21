#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"snake.h"

using namespace sf;
using namespace std;

class Nouriture{
private:
    CircleShape nouritureNormal;
    int depA , depB ;
    CircleShape nouritureSpecial;
    int timerNouritureSpecial;
    int timerExistanceNouritureSpecial;
public :
    Nouriture(SNAKE snake , size_t width , size_t height);
    CircleShape getNouritureSpecial();
    CircleShape getNouritureNormal();
    int getTimerNouritureSpecial();
    int getTimerExistanceNouritureSpecial();
    void incrementerTimerNouritureSpecial();
    void incrementerTimerExistanceNouritureSpecial();
    void depNormalNouriture(SNAKE snake, size_t windowWidth , size_t windowHeight);
    void depSpecialNouriture(SNAKE snake, size_t windowWidth , size_t windowHeight);
    void hideSpecialNouriture();
    void drawNouriture(RenderWindow &window);
};


namespace METHODE{
    void intersectionDeSnakeWNouriture(SNAKE & snake  , Nouriture & nouriture ,size_t windowWidth , size_t windowHeight , int & score);
    void intersectionDeSnakeWNouritureSpe(SNAKE & snake  , Nouriture & nouriture ,size_t windowWidth , size_t windowHeight , int & score);

}





