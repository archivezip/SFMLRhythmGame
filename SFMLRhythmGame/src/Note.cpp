#include "Note.h"
#include "Log.h"

Note::Note(float b, int t)
{

	_beat = b;
	_type = t;

	_xPosition = 540;
	_yStart = 0;
	_yEnd = 720;
	
	setSize(sf::Vector2f(40.f, 15.f));
	setPosition(540, 0);
	setFillColor(sf::Color::Red);
	setOrigin(20.f, 7.5f);



}

void Note::update(float currentPosInBeats, float beatsOnTrack)
{
	float timingGap = _beat - currentPosInBeats;
	float noteInterpolateRatio = (beatsOnTrack - timingGap) / beatsOnTrack;

	float lp = lerp(_yStart, _yEnd, noteInterpolateRatio);
	float yPos = getPosition().y;
	
	setPosition(getPosition().x, lp);
	LOG_INFO("Note: {0}   |  yPos: {1}", _beat, getPosition().y);
}

float Note::lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}
