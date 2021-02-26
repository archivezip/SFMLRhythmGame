#pragma once

#include "Chart.h"
#include "SFML/Graphics.hpp"

class Conductor : public sf::Drawable
{

public:
	Conductor();
	~Conductor();

	void update();
	
	void input(int playerInput);

	void setLaneKey(int playerInput);

	//loop control
	bool _chartEnded = false;
	bool _chartPlaying = false;
	bool _chartStart = false;

	int _chartLanes = 0;


private:
	
	//chart data
	Chart* _chart;

	std::vector<int> _laneKeys;

	//Timing System Variables
	float _musicPosBeats = 0.f;		//music current position in beats
	float _beatLength = 0.f;	//length of each beat in the music
	float _nearOffset = 0.25f;	//Time window for a near
	float _hitOffset = 0.15f;		//Time window for a hit

	//settings
	float _trackBeatsShown = 5.0f;	//How many beats are shown on the track
	float _trackTLOffset = 100.f;	//The offset of the timing line from the bottom of the screen
	float _trackTLPosition;			//The position of the timing line


	//scoring / note count
	int _hitCount = 0;
	int _nearCount = 0;
	int _missCount = 0;
	float _maxScore = 100;
	float _hitScore = 0.f;
	float _nearScore = 0.f;
	float _playerScore = 0.f;
	int _playerCombo = 0;
	int _playerComboMax = 0;

	//notes
	int _noteIndex = 0;	//index for which note in the song comes next
	std::vector<GameNote*> _notesOnScreen;

	//TODO: Make track visuals with a track class
	//track
	sf::Vertex _trackLine[2];


	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

