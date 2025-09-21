#include<SFML/Config.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

using namespace sf;

class FinalPage{
private:
    Text text1 , text2;
public:
    FinalPage();
    void drawText(RenderWindow & window);
};
