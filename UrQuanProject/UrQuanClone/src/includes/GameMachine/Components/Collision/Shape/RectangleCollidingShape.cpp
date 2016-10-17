/*
 * RectangleCollidingShape.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/Shape/RectangleCollidingShape.h>

namespace Collision
{

RectangleCollidingShape::RectangleCollidingShape(sf::Vector2f position,
		sf::Vector2f size) :
		CollidingShape(AABB_RECTANGLE, position), //
		_size(size) //
{
	// TODO Auto-generated constructor stub

}

RectangleCollidingShape::~RectangleCollidingShape()
{
	// TODO Auto-generated destructor stub
}

const sf::Vector2f& RectangleCollidingShape::getSize() const
{
	return _size;
}

} /* namespace Collision */
