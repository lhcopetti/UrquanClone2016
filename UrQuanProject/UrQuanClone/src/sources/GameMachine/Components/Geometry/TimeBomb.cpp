/*
 * TimeBomb.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Geometry/TimeBomb.h>

namespace Geometry
{

TimeBomb::TimeBomb(Components::DrawingComponent* drawingComponent, sf::Time timeToExplode) :
		GameObject(drawingComponent),
		_timeToExplode(timeToExplode),
		_counter(sf::seconds(0.0f))
{

}

TimeBomb::~TimeBomb()
{
}

void TimeBomb::update(const sf::Time& deltaTime)
{
	_counter += deltaTime;

	if (_counter > _timeToExplode)
		die();
}

} /* namespace Geometry */
