#pragma once
#include <string>
#include <SFML/Audio.hpp>


class Chart : public sf::Music
{
public:

	Chart(const char* filename);
	
	int songID;
	std::string songTitle;
	std::string songArtist;
	//std::string songImage;
	int rating;

	float bpm;
	float songOffset;

	//vector? notes;

};

