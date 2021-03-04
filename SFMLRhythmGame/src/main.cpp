#include <SFML/Graphics.hpp>

#include "Log.h"
#include "Conductor.h"
#include "Settings.h"

int main()
{
	//Create the logger
    Log::Init();

	//Create the window
    sf::RenderWindow _window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML Rhythm Game");

    //Create the conductor which controls the game
    Conductor _conductor;

    int _laneControlInput = 999;
    int _laneControlIndex = 1;
	
	//While the SFML window is open
    while (_window.isOpen())
    {
        sf::Event event;
        // while there are pending events...
        while (_window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed event
            case sf::Event::Closed:
                _window.close();
                break;

                // key pressed event
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) _window.close();

                if (!_conductor._chartStart) _laneControlInput = event.key.code;
                else if (!_conductor._chartEnded) _conductor.input(event.key.code);

            	
                break;
                // we don't process other types of events
            default:
                break;
            }
        }

        if(!_conductor._chartStart)
        {
            if (_laneControlIndex <= _conductor.getLaneCount())
            {
                LOG_WARN("Lane {0} of {1}", _laneControlIndex, _conductor.getLaneCount());
                if (_laneControlInput != 999)
                {
                    _conductor.setLaneKey(_laneControlInput);
                    _laneControlIndex++;
                }
            }   
            else
            {
                _conductor._chartStart = true;
            }
            _laneControlInput = 999;
        }


    	//Update
        _conductor.update();

    	//Drawing
        _window.clear();
        _window.draw(_conductor);
        _window.display();
    }

    return 0;
}
