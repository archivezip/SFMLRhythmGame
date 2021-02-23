#pragma once

#include "Chart.h"
#include "SFML/Graphics.hpp"

class Conductor : public sf::Drawable
{

public:
	Conductor();

	void update();


private:

	Chart *_chart;

	std::vector<Note*> _notesOnScreen;

	
	bool _ended = false;

	float _currentPosition = 0.f;
	float _beatDuration = 0.f;
	float _elapsedTime = 0.f;
	float _currentPosInBeats = 0.f;


	int _noteIndex = 0;

	float _beatsShownOnTrack = 24.0f;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

