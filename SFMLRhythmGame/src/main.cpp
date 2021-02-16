#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


#include "../Note.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rhythm Game");

    bool game = true; //game loop

    Note note1;

    sf::Music music;
    if (!music.openFromFile("assets/music/MountSinai.ogg"))
        return -1;
    std::cout << music.getDuration().asSeconds() << std::endl;
    music.play();
	
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