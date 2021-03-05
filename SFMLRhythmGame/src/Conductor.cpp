#include "Conductor.h"
#include "Log.h"

Conductor::Conductor()
{
	_chart = new Chart("assets/music/test.flac", 
		0, "Envenomate", "MissKixx", 0, 160, 0, 4);

	_beatLength = 60.f / _chart->_bpm;
	_hitScore = _maxScore / _chart->_notes.size();
	_nearScore = _hitScore / 2;	
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
	else if(_chartStart && !_chartPlaying && !_chartEnded)
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
		const float trackBeatSpawnPos = _musicPosBeats + _track._timingLinePos;

		
		//SPAWN NOTES - CREATE NOTE OBJECTS IF THERE ARE ANY THAT NEED TO SPAWN
		//If there is another note to come in the chart and
		//The track's beat spawning position has reached the beat of the next note
		while(_noteIndex < _chart->_notes.size() &&
			trackBeatSpawnPos > _chart->_notes[_noteIndex]._beat)
		{	//Spawn that note
			GameNote* note = new GameNote(
				_chart->_notes[_noteIndex]._beat, _chart->_notes[_noteIndex]._lane,		//beat, lane
				_chart->_notes[_noteIndex]._length, convertLaneToInput(_chart->_notes[_noteIndex]._lane), //length, input
				_track._timingLinePos);	//track pos / yEnd
			//Add the not to the notes that are currently shown on the screen
			_notesOnScreen.push_back(note);
			//increase the note index to point to the next note in the chart
			_noteIndex++;
		}

		//DELETE NOTES - THAT THE PLAYER HAS MISSED
		//If there are notes on the screen


		//Has player missed note? 
		//is the music position greater than the beat of the note + near offset?  
		while (!_notesOnScreen.empty() && _musicPosBeats > _notesOnScreen.front()->_beat + _nearOffset)
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


		//update player's best combo if the current combo is their best
		if (_playerCombo > _playerComboMax) _playerComboMax = _playerCombo;

		//update the position of the notes that are on screen
		for (GameNote* note : _notesOnScreen)
		{
			note->update(_musicPosBeats, _track._beatsShown);
		}

		//if there are more notes in the chart to spawn
		//if there are no more notes on the screen
		if (_noteIndex >= _chart->_notes.size() && _notesOnScreen.empty())
		{	
			//chart has ended
			_chartEnded = true;
			//stop music
			//_chart->_music.stop();  only for now while chart isnt finished
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

void Conductor::input(int input)
{
	//TODO: Add held notes

	//Get the position of the chart where the player pressed the key (in beats)
	float hit = _musicPosBeats;

	
	if(!_notesOnScreen.empty())
	{		
		//Get the front note of the ones on the screen
		GameNote frontNote = *_notesOnScreen.front();

		//get the front note's beat
		const float frontBeat = frontNote._beat;

		//Find the time difference between the hit and the beat of the note
		const float frontTiming = frontBeat - hit;
	

		bool beatChecked = false;
		
		int x = 0;
		while(!beatChecked)	//while we haven't checked each note with the same beat as the front note
		{		
			//get the note's beat
			const float noteBeat = _notesOnScreen[x]->_beat;

			//Find the time difference between the hit and the beat of the note
			const float hitTiming = noteBeat - hit;
			
			//Create a bool which will be true if the player hits a note
			bool playerHit = false;
			
			if (_notesOnScreen[x]->_input == input) playerHit = true;
			else playerHit = false;

			if (playerHit)
			{
				if (hitTiming <= _hitOffset && hitTiming >= -_hitOffset)
				{
					_notesOnScreen.erase(_notesOnScreen.begin() + x);
					_playerScore += _hitScore;
					_hitCount++;
					_playerCombo++;
					LOG_INFO("Perfect : {0} | {1}", hit, frontTiming);
				}
				else if (hitTiming <= _nearOffset && hitTiming >= -_nearOffset)
				{
					_notesOnScreen.erase(_notesOnScreen.begin() + x);
					_playerScore += _nearScore;
					_nearCount++;
					_playerCombo++;
					LOG_INFO("Near : {0} | {1}", hit, frontTiming);
				}
			}
	
			x++;
			try
			{
				if (_notesOnScreen.at(x)->_beat != frontBeat)
				{
					beatChecked = true;
				}
			}
			catch (...)
			{
				beatChecked = true;
			}
		}
	}
	
}

void Conductor::setLaneKey(int laneInput)
{
	_laneKeys.emplace_back(laneInput);
}

int Conductor::getLaneCount() 
{
	return _chart->_lanes;
}

int Conductor::convertLaneToInput(int lane)
{
	switch (lane)
	{
	case 1: return _laneKeys[0];
	case 2: return _laneKeys[1];
	case 3: return _laneKeys[2];
	case 4: return _laneKeys[3];
	case 5: return _laneKeys[4];
	case 6: return _laneKeys[5];
	case 7: return _laneKeys[6];
	default: return 0;
	}
}

void Conductor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (GameNote* note : _notesOnScreen) target.draw(*note);
	target.draw(_track);

}

