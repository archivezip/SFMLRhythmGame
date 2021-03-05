#include "Track.h"
#include "Settings.h"

Track::Track()
{
	_timingLinePos = static_cast<float>(SCR_HEIGHT) - HEIGHT_OFFSET;
	_timingLine[0] = sf::Vertex(sf::Vector2f(0, _timingLinePos));
	_timingLine[1] = sf::Vertex(sf::Vector2f(SCR_WIDTH, _timingLinePos));

	_beatsShown = static_cast<float>(BEATS_SHOWN) / 100.f;
}

Track::~Track() = default;

void Track::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_timingLine, 2, sf::Lines);
}
