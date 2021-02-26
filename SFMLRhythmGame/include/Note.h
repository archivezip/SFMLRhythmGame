#pragma once
#include <SFML/Graphics.hpp>

class Note : public sf::RectangleShape 
{
public:
	Note(float beat, int lane, float length) : _beat(beat), _lane(lane), _length(length){}

	float	_beat;
	int		_lane;
	float	_length;
};

