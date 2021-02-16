#include "../Note.h"
#include "iostream"

Note::Note()
{	
	setSize(sf::Vector2f(10.f, 10.f));
	setPosition(0, 0);
	setFillColor(sf::Color::Red);

	fBeat = 10.f;

}

void Note::move()
{
	
	//std::cout << getPosition().x << "   " << getPosition().y << std::endl;
	setPosition(getPosition().x, getPosition().y + 0.1);
}

