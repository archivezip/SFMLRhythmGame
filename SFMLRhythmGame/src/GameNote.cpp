#include "GameNote.h"
#include "Log.h"
#include "Settings.h"


GameNote::GameNote(float beat, int type, float yEnd) : Note(beat, type), _yEndPos(yEnd)
{	
	switch (_type)
	{
		case 1:{
			_xPos = 550;
			setFillColor(sf::Color::Red);
			break;
		}
		case 2:{
			_xPos = 610;
			setFillColor(sf::Color::White);
			break;
		}
		case 3:{
			_xPos = 670;
			setFillColor(sf::Color::White);
			break;
		}
		case 4:{
			_xPos = 730;
			setFillColor(sf::Color::Red);
			break;
		}
		default:{
			_xPos = 100;
			setFillColor(sf::Color::Green);
			LOG_ERROR("Note Type Unknown!! T: {0}", _type);
			break;
		}
	}
	
	setSize(sf::Vector2f(50.f, 10.0f));
	setPosition(_xPos, 0);
	setOrigin(25.f, 5.f);

	//LOG_INFO("Note Spawned: B: {0}, T: {1}", _beat, _type);
}

void GameNote::update(float currentPosInBeats, float beatsOnTrack)
{
	const auto timingGap = _beat - currentPosInBeats;
	const auto noteInterpolateRatio = (beatsOnTrack - timingGap) / beatsOnTrack;
	const auto lp = lerp(_yStartPos, _yEndPos, noteInterpolateRatio);
	
	setPosition(getPosition().x, lp);
	//LOG_INFO("Note: {0}   |  yPos: {1}", _beat, getPosition().y);
}

float GameNote::lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}
