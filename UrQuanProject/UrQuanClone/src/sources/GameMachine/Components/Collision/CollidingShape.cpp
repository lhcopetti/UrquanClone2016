/*
 * CollidingShape.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/Shape/CollidingShape.h>

namespace Collision
{

CollidingShape::CollidingShape(CollidingShapeType shapeType,
		const sf::Vector2f& position) :
		_position(position), //
		_shapeType(shapeType) //
{
}

CollidingShape::~CollidingShape()
{
}

CollidingShapeType CollidingShape::getType() const
{
	return _shapeType;
}

const sf::Vector2f& CollidingShape::getPosition() const
{
	return _position;
}

void CollidingShape::setPosition(const sf::Vector2f& position)
{
	_position = position;
}

} /* namespace Collision */
