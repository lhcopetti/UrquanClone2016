/*
 * CircleCollidingShape.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>

namespace Collision
{

CircleCollidingShape::CircleCollidingShape(sf::Vector2f position, float radius) :
		CollidingShape(CIRCLE, position), //
		_radius(radius) //
{
	// TODO Auto-generated constructor stub

}

CircleCollidingShape::~CircleCollidingShape()
{
	// TODO Auto-generated destructor stub
}

float CircleCollidingShape::getRadius() const
{
	return _radius;
}

} /* namespace Collision */
