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

	sf::Music _music;
	std::vector<Note> _notes;

	int _id;
	String _filename;
	String _title;
	String _artist;

	int _lanes;

	int _rating;

	float _bpm;
	float _offset;


	
	Chart(String filename, int id, String title, String artist, int rating, float bpm, float offset, int lanes) :
	_filename(filename),_id(id), _title(title), _artist(artist), _rating(rating), _bpm(bpm), _offset(offset), _lanes(lanes)
	{
		if(!_music.openFromFile(_filename))
		{
			LOG_INFO("Chart audio not found at:" + _filename);
		}


		//temporary note setup.
		//TODO: Change Chart creation statistics to be from json.

		_notes.emplace_back(Note(8,			1,	0));
		_notes.emplace_back(Note(8,			2,	0));
		_notes.emplace_back(Note(8,			3,	0));
		
		_notes.emplace_back(Note(9,			1,	0));
		_notes.emplace_back(Note(9,			3,	0));
		_notes.emplace_back(Note(9,			4,	0));
		
		_notes.emplace_back(Note(10,		4,	0));
		_notes.emplace_back(Note(10,		3,	0));
		_notes.emplace_back(Note(10,		2,	0));

		_notes.emplace_back(Note(11,	    1,  0));
		_notes.emplace_back(Note(11,		2,  0));
		_notes.emplace_back(Note(11,		4,  0));
		
		_notes.emplace_back(Note(13,		4,	0));
		_notes.emplace_back(Note(14,		3,	0));
		_notes.emplace_back(Note(15,		3,	0));
		_notes.emplace_back(Note(15,		1,	0));
		
		_notes.emplace_back(Note(17,		2,	0));
		_notes.emplace_back(Note(18,		1,	0));
		_notes.emplace_back(Note(19,		1,	0));
		_notes.emplace_back(Note(19,		4,	0));
		
		_notes.emplace_back(Note(21,		2,	0));
		_notes.emplace_back(Note(22,		3,	0));
		_notes.emplace_back(Note(23,		3,	0));
		_notes.emplace_back(Note(23,		4,	0));
		
		_notes.emplace_back(Note(25,		4,	0));
		_notes.emplace_back(Note(26,		3,	0));
		_notes.emplace_back(Note(27,		2,	0));
		_notes.emplace_back(Note(27,		4,	0));

		_notes.emplace_back(Note(29,		2,	0));
		_notes.emplace_back(Note(30,		1,	0));
		_notes.emplace_back(Note(31,		2,	0));
		_notes.emplace_back(Note(31,		4,	0));
		
		_notes.emplace_back(Note(33,		2,	0));
		_notes.emplace_back(Note(34,		3,	0));
		_notes.emplace_back(Note(35,		3,	0));
		_notes.emplace_back(Note(35,		4,	0));
		
		_notes.emplace_back(Note(37,		4,	0));
		_notes.emplace_back(Note(38,		3,	0));
		_notes.emplace_back(Note(39,		4,	0));
		_notes.emplace_back(Note(40,		1,	0));
		_notes.emplace_back(Note(40,		2,	0));
		
		_notes.emplace_back(Note(41,		4,	0));
		_notes.emplace_back(Note(42,		2,	0));
		_notes.emplace_back(Note(43,		3,	0));
		_notes.emplace_back(Note(44,		4,	0));
		_notes.emplace_back(Note(44,		1,	0));
		
		_notes.emplace_back(Note(45,		4,	0));
		_notes.emplace_back(Note(46,		3,	0));
		_notes.emplace_back(Note(47,		3,	0));
		_notes.emplace_back(Note(48,		4,	0));
		_notes.emplace_back(Note(48,		1,	0));
		
		_notes.emplace_back(Note(49,		2,	0));
		_notes.emplace_back(Note(50,		1,	0));
		_notes.emplace_back(Note(51,		3,	0));
		_notes.emplace_back(Note(52,		2,	0));
		_notes.emplace_back(Note(52,		4,	0));
		
		_notes.emplace_back(Note(53,		2,	0));
		_notes.emplace_back(Note(54,		3,	0));
		_notes.emplace_back(Note(55,		4,	0));
		_notes.emplace_back(Note(56,		1,	0));
		_notes.emplace_back(Note(56,		2,	0));
		
		_notes.emplace_back(Note(57,		4,	0));
		_notes.emplace_back(Note(58,		3,	0));
		_notes.emplace_back(Note(59,		3,	0));
		_notes.emplace_back(Note(60,		1,	0));
		_notes.emplace_back(Note(60,		2,	0));
		
		_notes.emplace_back(Note(61,		1,	0));
		_notes.emplace_back(Note(62,		2,	0));
		_notes.emplace_back(Note(63,		2,	0));
		_notes.emplace_back(Note(64,		4,	0));
		_notes.emplace_back(Note(64,		3,	0));
		
		_notes.emplace_back(Note(65,		2,	0));
		_notes.emplace_back(Note(66,		4,	0));
		_notes.emplace_back(Note(67,		4,	0));
		_notes.emplace_back(Note(68,		1,	0));
		_notes.emplace_back(Note(68,		3,	0));
		
		_notes.emplace_back(Note(69,		4,	0));
		_notes.emplace_back(Note(70.5,		1,	0));
		_notes.emplace_back(Note(71,		1,	0));
		_notes.emplace_back(Note(72,		3,	0));
		_notes.emplace_back(Note(72,		2,	0));

		
		_notes.emplace_back(Note(73,		2,	0));
		_notes.emplace_back(Note(73.5,		3,	0));
		_notes.emplace_back(Note(74,		4,	0));
		_notes.emplace_back(Note(75,		4,	0));
		_notes.emplace_back(Note(75.5,		3,	0));
		_notes.emplace_back(Note(76,		2,	0));
		
		_notes.emplace_back(Note(77,		1,	0));
		_notes.emplace_back(Note(77.5,		2,	0));
		_notes.emplace_back(Note(78,		3,	0));
		_notes.emplace_back(Note(79,		3,	0));
		_notes.emplace_back(Note(79.5,		2,	0));
		_notes.emplace_back(Note(80,		1,	0));
		
		_notes.emplace_back(Note(81,		2,	0));
		_notes.emplace_back(Note(82,		4,	0));
		_notes.emplace_back(Note(83,		1,	0));
		_notes.emplace_back(Note(84,		2,	0));
		
		_notes.emplace_back(Note(85,		2,	0));
		_notes.emplace_back(Note(86,		3,	0));
		_notes.emplace_back(Note(87,		4,	0));
		_notes.emplace_back(Note(88,		1,	0));
		_notes.emplace_back(Note(88.5,		2,	0));
		_notes.emplace_back(Note(89,		3,	0));
		_notes.emplace_back(Note(89.5,		4,	0));
		_notes.emplace_back(Note(90,		1,	0));
		_notes.emplace_back(Note(90.5,		2,	0));
		_notes.emplace_back(Note(91,		3,	0));
		_notes.emplace_back(Note(91.5,		4,	0));
		
		_notes.emplace_back(Note(92,		1,	0));
		_notes.emplace_back(Note(92.25,		3,	0));
		_notes.emplace_back(Note(92.5,		2,	0));
		_notes.emplace_back(Note(92.75,		4,	0));
		_notes.emplace_back(Note(93,		1,	0));
		_notes.emplace_back(Note(93.25,		3,	0));
		_notes.emplace_back(Note(93.5,		2,	0));
		_notes.emplace_back(Note(93.75,		4,	0));
		_notes.emplace_back(Note(94,		2,	0));
		_notes.emplace_back(Note(94.25,		3,	0));
		_notes.emplace_back(Note(94.5,		1,	0));
		_notes.emplace_back(Note(94.75,		4,	0));
		_notes.emplace_back(Note(95,		2,	0));
		_notes.emplace_back(Note(95.25,	    3,	0));
		_notes.emplace_back(Note(95.5,		1,	0));
		_notes.emplace_back(Note(95.75,		4,	0));
		_notes.emplace_back(Note(96,		2,	0));
		
	}
};

