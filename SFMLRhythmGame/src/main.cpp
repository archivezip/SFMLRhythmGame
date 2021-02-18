#include <SFML/Graphics.hpp>

#include "Log.h"
#include "Note.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rhythm Game");
	
    bool game = true; //game loop

    Log::Init();
	
	
    Note note1;
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    	if(game)
    	{
            note1.move();
    	}

        window.clear();
        window.draw(note1);
        window.display();
    }

    return 0;
}
