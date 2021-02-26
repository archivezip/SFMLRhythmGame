#include "Conductor.h"
#include "Log.h"
#include "Settings.h"

Conductor::Conductor()
{
	_chart = new Chart("assets/music/test.flac", 
		0, "Envenomate", "MissKixx", 0, 160, 0, 4);
	_beatLength = 60.f / _chart->_bpm;

	_trackTLPosition = static_cast<float>(SCR_HEIGHT) - _trackTLOffset;
	
	_trackLine[0] = sf::Vertex(sf::Vector2f(0, _trackTLPosition));
	_trackLine[1] = sf::Vertex(sf::Vector2f(SCR_WIDTH, _trackTLPosition));

	_hitScore = _maxScore / _chart->_notes.size();
	_nearScore = _hitScore / 2;
	_chartLanes = _chart->_lanes;
}

Conductor::~Conductor()
{
	for (GameNote* note : _notesOnScreen)
	delete note;
	
	delete _chart;
}

void Conductor::update()
{
	//If the chart has not started yet
	if(!_chartStart)
	{
		//Do nothing
	}
	//If the chart has started but the chart is not playing
	else if(_chartStart && !_chartPlaying)
	{
		//start the chart by setting it to play
		_chart->_music.play();
		_chartPlaying = true;
	}
	//If the chart has started and hasn't finished yet
	else if (!_chartEnded)
	{	//Chart is playing

		//TIMING SYSTEM - CALCULATE WHERE WE ARE IN THE CHART
		//Calculate the current playing position of the music stream in seconds
		const float musicPos = _chart->_music.getPlayingOffset().asSeconds();
		//Convert the current playing position into beats
		_musicPosBeats = musicPos / _beatLength;		
		//Calculate the track's beat spawning position
		const float trackBeatSpawnPos = _musicPosBeats + _trackBeatsShown;

		
		//SPAWN NOTES - CREATE NOTE OBJECTS IF THERE ARE ANY THAT NEED TO SPAWN
		//If there is another note to come in the chart and
		//The track's beat spawning position has reached the beat of the next note
		while(_noteIndex < _chart->_notes.size() &&
			trackBeatSpawnPos > _chart->_notes[_noteIndex]._beat)
		{	//Spawn that note
			GameNote* note = new GameNote(_chart->_notes[_noteIndex]._beat, _chart->_notes[_noteIndex]._lane,
				_chart->_notes[_noteIndex]._length, _trackTLPosition);
			//Add the not to the notes that are currently shown on the screen
			_notesOnScreen.push_back(note);
			//increase the note index to point to the next note in the chart
			_noteIndex++;
		}

		//DELETE NOTES - THAT THE PLAYER HAS MISSED
		//If there are notes on the screen
		if (!_notesOnScreen.empty())
		{
			//While the music position is greater than the beat of the note next to come
			//(The player has not hit the note, and the note is now behind the current point in the song)
			//(Is a while so that if there are more than one notes on the same beat, they will be deleted at the same time)
			while(_musicPosBeats > _notesOnScreen.front()->_beat)
			{
				//Get the note 
				GameNote currentNote = *_notesOnScreen.front();

				//Check how long its been since the player was supposed to hit the note
				float noteDuration = currentNote._beat - _musicPosBeats;

				//if that duration has fallen out of the near threshold
				if (noteDuration < -_nearOffset)
				{
					//delete the note
					_notesOnScreen.erase(_notesOnScreen.begin());
					//count it as a miss
					_missCount++;
					//reset the players combo
					_playerCombo = 0;
					LOG_INFO("Miss");
				}
			}
			
		}

		//update player's best combo if the current combo is their best
		if (_playerCombo > _playerComboMax) _playerComboMax = _playerCombo;

		//update the position of the notes that are on screen
		for (GameNote* note : _notesOnScreen)
		{
			note->update(_musicPosBeats, _trackBeatsShown);
		}

		//if there are more notes in the chart to spawn
		//if there are no more notes on the screen
		if (_noteIndex >= _chart->_notes.size() && _notesOnScreen.empty())
		{	
			//chart has ended
			_chartEnded = true;
			//stop music
			_chart->_music.stop();
			//chart has stopped playing
			_chartPlaying = false;

			LOG_INFO("Chart Ended");
			LOG_INFO("H: {0}  N:  {1}  M:  {2}", _hitCount, _nearCount, _missCount);
		}
	}
	//Chart has been started, but has ended
	else
	{
		//end of the chart
	}
}

void Conductor::input(int laneInput)
{
	//TODO: fix input so that multiple notes on the same beat can be checked
	//TODO: Allow multi input???
	//TODO: Add held notes

	//Get the position of the chart where the player pressed the key (in beats)
	float hit = _musicPosBeats;

	LOG_INFO(hit);
	
	if(!_notesOnScreen.empty())
	{
		//Get the front note of the ones on the screen
		GameNote currentNote = *_notesOnScreen.front();

		//Find the time difference between the hit and the beat of the note
		float hitTiming = currentNote._beat - hit;

		//Create a bool which will be true if the player hit the correct note 
		bool playerHit = false;

		if (currentNote._lane == laneInput) playerHit = true;

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

void Conductor::setLaneKey(int playerInput)
{
	_laneKeys.emplace_back(playerInput);
}

void Conductor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (GameNote* note : _notesOnScreen) target.draw(*note);
	target.draw(_trackLine, 2, sf::Lines);
}

