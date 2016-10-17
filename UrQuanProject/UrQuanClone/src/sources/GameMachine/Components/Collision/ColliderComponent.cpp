/*
 * ColliderComponent.cpp
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>

namespace Collision
{

ColliderComponent::ColliderComponent(CollidingShape* collidingShape) :
		_category(CC_WALL), //
		_collidingCategory(), //
		_collidingShape(collidingShape)
{

}

ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{

}

bool ColliderComponent::checkCategoryCollision(ColliderComponent* collider)
{
	CCategories otherCategory = collider->getCategory();
	return _collidingCategory.collidesWith(otherCategory);
}

CCategories ColliderComponent::getCategory() const
{
	return _category;
}

} /* namespace Components */
