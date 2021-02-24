#include "Conductor.h"
#include "Log.h"
#include "Settings.h"

Conductor::Conductor()
{
	_chart = new Chart("assets/music/test.flac", 
		0, "Envenomate", "MissKixx", 0, 160, 0);
	_beatLength = 60.f / _chart->_bpm;

	_chart->_music.play();

	_trackTLPosition = static_cast<float>(SCR_HEIGHT) - _trackTLOffset;
	
	_trackLine[0] = sf::Vertex(sf::Vector2f(0, _trackTLPosition));
	_trackLine[1] = sf::Vertex(sf::Vector2f(SCR_WIDTH, _trackTLPosition));

	_hitScore = _maxScore / _chart->_notes.size();
	_nearScore = _hitScore / 2;
}

Conductor::~Conductor()
{
	for (GameNote* note : _notesOnScreen)
	delete note;
	
	delete _chart;
}

void Conductor::update(int input)
{
	if (!_ended)
	{
		//Get the songs current position in time
		const float currentPosition = _chart->_music.getPlayingOffset().asSeconds() - _chart->_offset;

		//Convert the songs current time into beats
		_musicPos = currentPosition / _beatLength;

		//Spawn next note - if there is one and its time in the song has come
		//If there is another note to come and
		//the note's beat is less than the music's current position in beats + the beats that are shown on the track 
		//TODO: Look into the next note in the list to check if it is also on the same beat, if so spawn it this cycle.
		if (_noteIndex < _chart->_notes.size() &&
			_chart->_notes[_noteIndex]._beat < _musicPos + _trackBeatCount)
		{
			//spawn the note
			GameNote* note = new GameNote(_chart->_notes[_noteIndex]._beat, _chart->_notes[_noteIndex]._type, _trackTLPosition);
			_notesOnScreen.push_back(note);
			//increase the note index to point to the next note
			_noteIndex++;
		}

		//poll
		if(input) inputted(input);
		
		if (!_notesOnScreen.empty())
		{
			GameNote currentNote = *_notesOnScreen[0];

			float noteDuration = currentNote._beat - _musicPos;

			if (noteDuration < -_nearOffset)
			{
				_notesOnScreen.erase(_notesOnScreen.begin());
				_missCount++;
				_playerCombo = 0;
				LOG_INFO("Miss");
			}
		}

		if (_playerCombo > _playerComboMax) _playerComboMax = _playerCombo;

		//update the notes that are on screens position
		for (GameNote* note : _notesOnScreen)
		{
			note->update(_musicPos, _trackBeatCount);
		}

		//check if ended
		if (_noteIndex >= _chart->_notes.size() && _notesOnScreen.empty())
		{
			_ended = true;
			LOG_INFO("Chart Ended");
			LOG_INFO("H: {0}  N:  {1}  M:  {2}", _hitCount, _nearCount, _missCount);
		}
	}
}

void Conductor::inputted(int type)
{
	float hit = _musicPos;

	if(!_notesOnScreen.empty())
	{
		GameNote currentNote = *_notesOnScreen[0];

		float hitTiming = currentNote._beat - hit;

		bool playerHit = false;

		if (currentNote._type == type) playerHit = true;

		if(playerHit)
		{
			if(hitTiming <= _hitOffset && hitTiming >= -_hitOffset)
			{
				_notesOnScreen.erase(_notesOnScreen.begin());
				_playerScore += _hitScore;
				_hitCount++;
				_playerCombo++;
				LOG_INFO("Hit");
			}
			else if(hitTiming <= _nearOffset && hitTiming >= -_nearOffset)
			{
				_notesOnScreen.erase(_notesOnScreen.begin());
				_playerScore += _nearScore;
				_nearCount++;
				_playerCombo++;
				LOG_INFO("Near");
			}
		}
		else if (hitTiming < _nearOffset)
		{
			_notesOnScreen.erase(_notesOnScreen.begin());
			_missCount++;
			_playerCombo = 0;
			LOG_INFO("Miss");
		}
	}
	
}

void Conductor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (GameNote* note : _notesOnScreen) target.draw(*note);
	target.draw(_trackLine, 2, sf::Lines);
}

