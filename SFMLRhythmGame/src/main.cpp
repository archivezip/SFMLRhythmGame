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

    int playerInput = 0;
	
	
	//While the SFML window is open
    while (window.isOpen())
    {
        sf::Event event;
        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed event
            case sf::Event::Closed:
                window.close();
                break;

                // key pressed event
            case sf::Event::KeyPressed:
                // what key was pressed
                switch (event.key.code)
                {
                case sf::Keyboard::Escape: { 
                    window.close();
                    break;
					}
                case sf::Keyboard::D: {
                    playerInput = 1;
                    break;
					}
                case sf::Keyboard::F: {
                    playerInput = 2;
                    break;
					}
                case sf::Keyboard::J: {
                    playerInput = 3;
                    break;
					}
                case sf::Keyboard::K: {
                    playerInput = 4;
                    break;
					}
                }
                // we don't process other types of events
            default:
                break;
            }
        }

        conductor.update(playerInput);
        playerInput = 0;
    	
        window.clear();
        window.draw(conductor);
        window.display();
    }

    return 0;
}
