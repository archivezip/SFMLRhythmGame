#pragma once
#include <SFML/Graphics.hpp>

class Track : public sf::Drawable
{

public:
	Track();
	~Track() override;


	//settings
	float _timingLinePos;			//The position of the timing line
	float _beatsShown;				//How many beats are shown on track

private:
	sf::Vertex _timingLine[2]; //A line on the track which shows where notes need to be hit

	//sf::Vertex _laneLines[8]; //Lines for each column per track

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
