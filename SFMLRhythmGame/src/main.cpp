#include <SFML/Graphics.hpp>

#include "Log.h"
#include "Conductor.h"

const int W_WIDTH = 1280;
const int W_HEIGHT = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "SFML Rhythm Game");

	Log::Init();

    Conductor conductor;
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        conductor.update();
    	
        window.clear();
        window.draw(conductor);
        window.display();
    }

    return 0;
}
