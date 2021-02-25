#pragma once

class Settings
{
public:
	static const int SET_SCR_WIDTH = 800;
	static const int SET_SCR_HEIGHT = 600;
	
};

#define SCR_WIDTH ::Settings::SET_SCR_WIDTH
#define SCR_HEIGHT ::Settings::SET_SCR_HEIGHT
