#include <SFML/Graphics.hpp>

#include "Log.h"
#include "Conductor.h"
#include "Settings.h"

int main()
{
	//Create the logger
    Log::Init();

	//Create the window
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML Rhythm Game");

	//Create the conductor which controls the game
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
