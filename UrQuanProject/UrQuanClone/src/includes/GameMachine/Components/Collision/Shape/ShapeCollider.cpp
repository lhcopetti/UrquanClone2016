/*
 * ShapeCollider.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/Shape/ShapeCollider.h>
#include <SFML/System/Vector2.hpp>

#include <VectorMath/VectorMath.h>

namespace Collision
{

ShapeCollider::ShapeCollider()
{
	// TODO Auto-generated constructor stub

}

ShapeCollider::~ShapeCollider()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Collision */

bool Collision::ShapeCollider::checkCollision(
		const CircleCollidingShape* circle1,
		const CircleCollidingShape* circle2)
{
	return VectorMath::dist(circle1->getPosition(), circle2->getPosition())
			< circle1->getRadius() + circle2->getRadius();
}

bool Collision::ShapeCollider::checkCollision(
		const RectangleCollidingShape* rectangle1,
		const RectangleCollidingShape* rectangle2)
{
	const sf::Vector2f& rect1Pos = rectangle1->getPosition();
	const sf::Vector2f& rect1Size = rectangle1->getSize();

	const sf::Vector2f& rect2Pos = rectangle2->getPosition();
	const sf::Vector2f& rect2Size = rectangle2->getSize();

	if (rect1Pos.x < rect2Pos.x + rect2Size.x
			&& rect1Pos.x + rect1Size.x > rect2Pos.x
			&& rect1Pos.y < rect2Pos.y + rect2Size.y
			&& rect1Pos.y + rect1Size.y > rect2Pos.y)
		return true;

	return false;
}

bool Collision::ShapeCollider::checkCollision(
		const RectangleCollidingShape* rectangle,
		const CircleCollidingShape* circle)
{
	const sf::Vector2f& circlePos = circle->getPosition();
	const sf::Vector2f& rectPos = rectangle->getPosition();
	const sf::Vector2f& rectSize = rectangle->getSize();

	float deltaX = circlePos.x
			- std::max(rectPos.x,
					std::min(circlePos.x, rectPos.x + rectSize.x));
	float deltaY = circlePos.y
			- std::max(rectPos.y,
					std::min(circlePos.y, rectPos.y + rectSize.y));

	return deltaX * deltaX + deltaY * deltaY
			< circle->getRadius() * circle->getRadius();
}
