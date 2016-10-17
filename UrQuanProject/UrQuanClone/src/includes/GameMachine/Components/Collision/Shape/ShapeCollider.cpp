/*
 * ShapeCollider.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/Shape/ShapeCollider.h>

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
	return VectorMath::dist(circle1->getPosition(), circle2->getPosition()) < circle1->getRadius() + circle2->getRadius();
}

bool Collision::ShapeCollider::checkCollision(
		const RectangleCollidingShape* rectangle1,
		const RectangleCollidingShape* rectangle2)
{
	return false;
}

bool Collision::ShapeCollider::checkCollision(
		const RectangleCollidingShape* rectangle,
		const CircleCollidingShape* circle)
{
	return false;
}
