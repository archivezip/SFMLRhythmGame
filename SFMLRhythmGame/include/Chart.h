#pragma once
#include <string>
//TODO: Change from sfml audio to statically linkable library.
#include <SFML/Audio.hpp>
#include "GameNote.h"
#include "Log.h"

using String = std::string;

class Chart 
{
public:

	Chart(String filename, int id, String title, String artist, int rating, float bpm, float offset) :
	_filename(filename),_id(id), _title(title), _artist(artist), _rating(rating), _bpm(bpm), _offset(offset)
	{
		if(!_music.openFromFile(_filename))
		{
			LOG_INFO("Chart audio not found at:" + _filename);
		}


		//temporary note setup.
		//TODO: Change Chart creation statistics to be from json.

		_notes.emplace_back(Note(8,  1));
		_notes.emplace_back(Note(9,  2));
		_notes.emplace_back(Note(10, 3));
		_notes.emplace_back(Note(13, 4));
		_notes.emplace_back(Note(14, 3));
		_notes.emplace_back(Note(17, 2));
		_notes.emplace_back(Note(18, 1));
		_notes.emplace_back(Note(21, 2));
		_notes.emplace_back(Note(22, 3));
		_notes.emplace_back(Note(25, 4));
		_notes.emplace_back(Note(26, 3));
		_notes.emplace_back(Note(29, 2));
		_notes.emplace_back(Note(30, 1));
		_notes.emplace_back(Note(33, 2));
		_notes.emplace_back(Note(34, 3));
		_notes.emplace_back(Note(37, 4));
		_notes.emplace_back(Note(38, 4));
	}

	sf::Music _music;
	std::vector<Note> _notes;

	
	int _id;
	String _filename;
	String _title;
	String _artist;

	int _rating;

	float _bpm;
	float _offset;

	//TODO: Chart Image Data

};

