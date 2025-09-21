#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"laNouriture.hpp"
#include "AFFICHAGEFINAL.hpp"
#include "EndText.hpp"

using namespace sf;
using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);




    //vecteur de deplacement de snake;
    Vector2f nextPosition , prevPosition ;

    //dimention de window
    size_t windowWidth = window.getSize().x ;
    size_t windowHeight = window.getSize().y ;

    //score
    int score;

    // Draw score
    Font font;
    font.loadFromFile("arial.ttf");
    Text scoreText("Score: " + to_string(score), font, 20);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(10, 10);



    // snake
    SNAKE snake( windowWidth , windowHeight , score);
    int permut=0;


    //nouriture
    Nouriture nouriture(snake,windowWidth,windowHeight);

    //EndText
    Text gameOver;
    Text Score;
    font.loadFromFile("arial.ttf");
    gameOver.setFillColor(Color::Green);
    gameOver.setCharacterSize(120);
    gameOver.setFont(font);
    gameOver.setString("Game Over");
    Score.setCharacterSize(70);
    Score.setFont(font);
    Score.setString("SCORE : "+to_string(score));
    gameOver.setPosition(windowWidth/2-((gameOver.getLocalBounds().width)/2),windowHeight/2-((gameOver.getLocalBounds().height)*2));
    Score.setPosition(windowWidth/2-((Score.getLocalBounds().width)/2),windowHeight/2/*-((gameOver.getLocalBounds().height)*2)*/);









    while (window.isOpen())
    {




        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed && event.key.code== Keyboard::Escape)
                window.close();
        }


        //UPDATE
        if(snake.getSnakeTimer() < 4)
            snake.incrementerSnakeTimer();

        if((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)) && snake.getSnakeTimer() >= 4)
        {
            snake.snakeOriginMove(windowWidth,windowHeight,nextPosition,prevPosition);
            snake.snakeRestMove(nextPosition,prevPosition);
        }
        //nouriture.depSpecialNouriture(snake,windowWidth,windowHeight);
        //nouriture.hideSpecialNouriture();

        METHODE::intersectionDeSnakeWNouriture(snake,nouriture,windowWidth,windowHeight,score);
        //METHODE::intersectionDeSnakeWNouritureSpe(snake,nouriture,windowWidth,windowHeight,score);
        snake.touchItSelf(permut);
        Score.setString("SCORE : "+to_string(score));

        scoreText.setString("Score: " + to_string(score));







    // Clear screen
    window.clear(Color::Magenta);

    if(permut==0)
    {
        // Draw the sprite
        snake.drawSnake(window);
        nouriture.drawNouriture(window);
        window.draw(scoreText);
    }
    else
    {
        window.clear(Color::Red);
        window.draw(gameOver);
        window.draw(Score);

    }


    // Update the window
        window.display();


    }

    return EXIT_SUCCESS;
}
