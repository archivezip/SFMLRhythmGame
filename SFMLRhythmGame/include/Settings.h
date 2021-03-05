#pragma once

class Settings
{
public:
	static const int SET_SCR_WIDTH = 800;
	static const int SET_SCR_HEIGHT = 600;

	static const int TRACK_BEATS_SHOWN = 400;	//How many beats are shown on the track
	static const int TRACK_HEIGHT_OFFSET = 100;	//The offset of the timing line from the bottom of the screen
	
};


#define SCR_WIDTH ::Settings::SET_SCR_WIDTH
#define SCR_HEIGHT ::Settings::SET_SCR_HEIGHT
#define BEATS_SHOWN ::Settings::TRACK_BEATS_SHOWN
#define HEIGHT_OFFSET ::Settings::TRACK_HEIGHT_OFFSET
