#pragma once

#include <SFML/Graphics.hpp>


class Note : public sf::RectangleShape
{
public:
	Note();
	void move();


	sf::Vector2f fStartPos;
	sf::Vector2f fEndPos;

	float fBeat;


	
	//type
	//Beat
	//spawn pos
	//end pos
	
};
