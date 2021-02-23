#include "GameNote.h"
#include "Log.h"
#include "Settings.h"


GameNote::GameNote(float beat, int type, float yEnd) : Note(beat, type), _yEndPos(yEnd)
{	
	switch (_type)
	{
		case 1:{
			_xPos = 550;
			break;
		}
		case 2:{
			_xPos = 610;
			break;
		}
		case 3:{
			_xPos = 670;
			break;
		}
		case 4:{
			_xPos = 730;
			break;
		}
		default:{
			_xPos = 100;
			LOG_ERROR("Note Type Unknown!! T: {0}", _type);
			break;
		}
	}
	
	setSize(sf::Vector2f(60.f, 15.f));
	setPosition(_xPos, 0);
	setFillColor(sf::Color::Red);
	setOrigin(30.f, 7.5f);

	LOG_INFO("Note Spawned: B: {0}, T: {1}", _beat, _type);
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
