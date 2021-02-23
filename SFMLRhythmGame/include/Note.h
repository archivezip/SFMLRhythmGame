#pragma once

#include <SFML/Graphics.hpp>


class Note : public sf::RectangleShape
{
public:
	Note(float b, int t);
	void update(float currentPosInBeats, float beatsOnTrack);

	// Linear interpolation
	float lerp(float a, float b, float t);

	float _beat;
	int _type;

	float _xPosition;
	float _yStart;
	float _yEnd;

	
	//type
	//Beat
	//spawn pos
	//end pos
	
};
