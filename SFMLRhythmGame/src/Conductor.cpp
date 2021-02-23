#include "Conductor.h"
#include "Log.h"

Conductor::Conductor()
{	
	_chart = new Chart("assets/music/test.ogg", 0, "Mount Sinai", "SuicideBoys", 0,
		132, 0);
	_beatDuration = 60.f / _chart->_bpm;

	sf::Time time = _chart->getPlayingOffset();
	_elapsedTime = time.asSeconds();
	_chart->play();	
}

void Conductor::update()
{
	if (!_ended)
	{
		//Get the songs current position in time
		_currentPosition = (_chart->getPlayingOffset().asSeconds() - _elapsedTime) - _chart->_offset;

		//Convert the songs current time into beats
		_currentPosInBeats = _currentPosition / _beatDuration;

		//Spawn next note - if there is one and its time in the song has come
		//If there is a next note and it's beat is less than the songs position on the track
		if(_noteIndex < _chart->_beats.size() 
			&& _chart->_beats[_noteIndex] < _currentPosInBeats + _beatsShownOnTrack)
		{
			switch (_chart->_types[_noteIndex])
			{
				case 0:
				{
					Note* note = new Note(_chart->_beats[_noteIndex], _chart->_types[_noteIndex]);
					_notesOnScreen.push_back(note);
					break;
				}

				default: break;
			}
			_noteIndex++;
		}

		for(Note* note : _notesOnScreen)
		{
			note->update(_currentPosInBeats, _beatsShownOnTrack);
		}
	}
}

void Conductor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (Note* note : _notesOnScreen) target.draw(*note);
}

