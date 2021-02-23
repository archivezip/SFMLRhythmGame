#pragma once
#include <SFML/Graphics.hpp>

class Note : public sf::RectangleShape 
{
public:
	Note(float beat, int type) : _beat(beat), _type(type) {}
	float _beat;
	int _type;
};

