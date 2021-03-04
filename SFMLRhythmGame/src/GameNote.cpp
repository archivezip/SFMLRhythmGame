#include "GameNote.h"
#include "Log.h"
#include "Settings.h"

//TODO: Make lane spawning positions changeable/based upon resolution
//TODO: Change yEnd to be a globally configured setting

GameNote::GameNote(float beat, int lane, float length, int input, float yEnd) : Note(beat, lane, length), _input(input),  _yEndPos(yEnd)
{	
	switch (_lane)
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
			LOG_ERROR("Note Type Unknown!! T: {0}", _lane);
			break;
		}
	}
	
	setSize(sf::Vector2f(50.f, 10.0f));
	setOrigin(getSize().x / 2, getSize().y / 2);
	setPosition(_xPos, _yStartPos);
}

void GameNote::update(float currentPosInBeats, float beatsOnTrack)
{
	const auto timingGap = _beat - currentPosInBeats;
	const auto noteInterpolateRatio = (beatsOnTrack - timingGap) / beatsOnTrack;
	const auto lp = lerp(_yStartPos, _yEndPos, noteInterpolateRatio);
	
	setPosition(getPosition().x, lp);
}

float GameNote::lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}
