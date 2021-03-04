#pragma once
#include "Note.h"


class GameNote : public Note
{
public:
	GameNote(float beat, int lane, float length, int input, float yEnd);
	void update(float currentPosInBeats, float beatsOnTrack);

	int _input;
	
	float _xPos = 0.f;
	float _yStartPos = 0.f;
	float _yEndPos = 0.f;


private:
	
	// Linear interpolation
	float lerp(float a, float b, float t);

	
};
