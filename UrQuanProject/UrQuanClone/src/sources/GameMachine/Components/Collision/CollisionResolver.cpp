/*
 * CollisionResolver.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/CollisionResolver.h>
#include <GameMachine/Components/Collision/ColliderComponent.h>

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

	return false;
}

} /* namespace Collision */
