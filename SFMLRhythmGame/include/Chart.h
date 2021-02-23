#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include "Note.h"

using String = std::string;

//TODO: Change from sfml audio to statically linkable library.
//TODO: Change Chart creation statistics to be from json.
class Chart : public sf::Music
{
public:

	Chart(String filename, int id, String title, String artist, int rating, float bpm, float offset) :
	_filename(filename),_id(id), _title(title), _artist(artist), _rating(rating), _bpm(bpm), _offset(offset)
	{
		openFromFile(_filename);
		_beats.push_back(8);
		_beats.push_back(12);
		_beats.push_back(16);
		_beats.push_back(20);
		_beats.push_back(24);
		_beats.push_back(28);
		_beats.push_back(32);
		_beats.push_back(36);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
		_types.push_back(0);
	}

	
	int _id;
	String _filename;
	String _title;
	String _artist;

	int _rating;

	float _bpm;
	float _offset;

	//image 


	std::vector<float> _beats;
	std::vector<int> _types;

};

