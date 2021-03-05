#pragma once

#include "Chart.h"
#include "Track.h"
#include "SFML/Graphics.hpp"

class Conductor : public sf::Drawable
{

public:
	Conductor();
	~Conductor() override;

	void update();
	
	void input(int input);

	void setLaneKey(int lane);
	int getLaneCount();

	
	//loop control
	bool _chartEnded = false;
	bool _chartPlaying = false;
	bool _chartStart = false;

private:
	
	//Chart
	Chart* _chart;

	//Track
	Track _track;

	//Timing System Variables
	float _musicPosBeats = 0.f;		//music current position in beats
	float _beatLength = 0.f;	//length of each beat in the music
	float _nearOffset = 0.25f;	//Time window for a near
	float _hitOffset = 0.15f;		//Time window for a hit

	//scoring / note count
	int _hitCount = 0;
	int _nearCount = 0;
	int _missCount = 0;
	int _playerCombo = 0;
	int _playerComboMax = 0;

	float _maxScore = 100;
	float _hitScore = 0.f;
	float _nearScore = 0.f;
	float _playerScore = 0.f;

	//notes
	int _noteIndex = 0;	//index for which note in the song comes next
	std::vector<GameNote*> _notesOnScreen;

	std::vector<int> _laneKeys;

	int convertLaneToInput(int lane);
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

