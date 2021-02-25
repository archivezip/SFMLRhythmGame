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
		
		_notes.emplace_back(Note(41, 4));
		_notes.emplace_back(Note(42, 4));

		_notes.emplace_back(Note(45, 4));
		_notes.emplace_back(Note(46, 3));

		_notes.emplace_back(Note(49, 2));
		_notes.emplace_back(Note(50, 1));

		_notes.emplace_back(Note(53, 2));
		_notes.emplace_back(Note(54, 3));
		
		_notes.emplace_back(Note(57, 4));
		_notes.emplace_back(Note(58, 3));

		_notes.emplace_back(Note(61, 1));
		_notes.emplace_back(Note(62, 2));

		_notes.emplace_back(Note(65, 2));
		_notes.emplace_back(Note(66, 4));

		_notes.emplace_back(Note(69, 4));
		_notes.emplace_back(Note(70, 1));

		_notes.emplace_back(Note(73, 2));
		_notes.emplace_back(Note(73.5, 3));
		_notes.emplace_back(Note(74, 4));
		
		_notes.emplace_back(Note(75, 4));

		_notes.emplace_back(Note(77, 1));
		_notes.emplace_back(Note(77.5, 2));
		_notes.emplace_back(Note(78, 3));
		
		_notes.emplace_back(Note(79, 3));

		_notes.emplace_back(Note(81, 2));
		_notes.emplace_back(Note(81.5, 3));
		_notes.emplace_back(Note(82, 4));

		_notes.emplace_back(Note(83, 1));
		
		_notes.emplace_back(Note(85, 2));
		_notes.emplace_back(Note(86, 3));
		_notes.emplace_back(Note(87, 4));
		
		_notes.emplace_back(Note(88, 1));
		_notes.emplace_back(Note(88.5, 2));
		_notes.emplace_back(Note(89, 3));
		_notes.emplace_back(Note(89.5, 4));

		_notes.emplace_back(Note(90, 1));
		_notes.emplace_back(Note(90.5, 2));
		_notes.emplace_back(Note(91, 3));
		_notes.emplace_back(Note(91.5, 4));

		_notes.emplace_back(Note(92, 1));
		_notes.emplace_back(Note(92.25, 3));
		_notes.emplace_back(Note(92.5, 2));
		_notes.emplace_back(Note(92.75, 4));

		_notes.emplace_back(Note(93, 1));
		_notes.emplace_back(Note(93.25, 3));
		_notes.emplace_back(Note(93.5, 2));
		_notes.emplace_back(Note(93.75, 4));

		_notes.emplace_back(Note(94, 4));
		_notes.emplace_back(Note(94.25, 2));
		_notes.emplace_back(Note(94.5, 3));
		_notes.emplace_back(Note(94.75, 1));

		_notes.emplace_back(Note(95, 4));
		_notes.emplace_back(Note(95.25, 2));
		_notes.emplace_back(Note(95.5, 3));
		_notes.emplace_back(Note(95.75, 1));
		
		_notes.emplace_back(Note(96, 2));
		
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

