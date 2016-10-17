/*
 * CollisionResolver.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/CollisionResolver.h>
#include <GameMachine/Components/Collision/ColliderComponent.h>

#include <GameMachine/Components/Collision/Shape/RectangleCollidingShape.h>
#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>
#include <GameMachine/Components/Collision/Shape/ShapeCollider.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Collision
{

CollisionResolver::CollisionResolver()
{
	// TODO Auto-generated constructor stub

}

CollisionResolver::~CollisionResolver()
{
	// TODO Auto-generated destructor stub
}

bool CollisionResolver::resolve(GameObjects::GameObject& g1,
		GameObjects::GameObject& g2)
{
	ColliderComponent* colliderG1 = g1.getColliderComponent();

	if (nullptr == colliderG1)
		return false;

	ColliderComponent* colliderG2 = g2.getColliderComponent();

	if (nullptr == colliderG2)
		return false;

	if (!checkCategoriesCollision(colliderG1, colliderG2))
		return false;

	if (!checkShapeCollision(colliderG1, colliderG2))
		return false;

	return true;
}

bool CollisionResolver::checkCategoriesCollision(ColliderComponent* c1,
		ColliderComponent* c2)
{
	return c1->checkCategoryCollision(c2) && c2->checkCategoryCollision(c1);
}

bool CollisionResolver::checkShapeCollision(ColliderComponent* c1,
		ColliderComponent* c2)
{
	const CollidingShape* shape1 = c1->getCollidingShape();
	const CollidingShape* shape2 = c2->getCollidingShape();

	if (c1->getShapeType() == AABB_RECTANGLE && c2->getShapeType() == AABB_RECTANGLE)
	{
		const RectangleCollidingShape* rect1 = static_cast<const RectangleCollidingShape*>(shape1);
		const RectangleCollidingShape* rect2 = static_cast<const RectangleCollidingShape*>(shape2);
		return ShapeCollider::checkCollision(rect1, rect2);
	}
	else if (c1->getShapeType() == CIRCLE && c2->getShapeType() == CIRCLE)
	{
		const CircleCollidingShape* circle1 = static_cast<const CircleCollidingShape*>(shape1);
		const CircleCollidingShape* circle2 = static_cast<const CircleCollidingShape*>(shape2);
		return ShapeCollider::checkCollision(circle1, circle2);
	}

	const RectangleCollidingShape* rect = static_cast<const RectangleCollidingShape*>(c1->getShapeType() == AABB_RECTANGLE ? shape1 : shape2);
	const CircleCollidingShape* circle = static_cast<const CircleCollidingShape*>(c1->getShapeType() == CIRCLE ? shape1 : shape2);
	return ShapeCollider::checkCollision(rect, circle);

	return false;
}

} /* namespace Collision */
