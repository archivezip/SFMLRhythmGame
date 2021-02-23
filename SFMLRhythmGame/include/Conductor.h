#pragma once

#include "Chart.h"
#include "SFML/Graphics.hpp"

class Conductor : public sf::Drawable
{

public:
	Conductor();
	~Conductor();

	void update();


private:
	//chart data
	Chart* _chart;

	//settings
	float _trackBeatCount = 10.0f;	//How many beats are shown on the track
	float _trackTLOffset = 100.f;	//The offset of the timing line from the bottom of the screen
	float _trackTLPosition;			//The position of the timing line

	//loop control
	bool _ended = false;

	//notes
	int _noteIndex = 0;	//index for which note in the song comes next
	std::vector<GameNote*> _notesOnScreen;

	//visuals
	sf::Vertex _trackLine[2];

	//Timing System Variables
	float _musicPos = 0.f;		//music current position in beats
	float _beatLength = 0.f;	//length of each beat in the music
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

