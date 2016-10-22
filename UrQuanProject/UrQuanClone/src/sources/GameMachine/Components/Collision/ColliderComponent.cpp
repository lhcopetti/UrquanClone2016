/*
 * ColliderComponent.cpp
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Collision
{

ColliderComponent::ColliderComponent(CollidingShape* collidingShape,
		Actions::Action* action, CCategories categories,
		ColliderCategory colliderCategory) :
		_category(categories), //
		_collidingCategory(colliderCategory), //
		_collidingShape(collidingShape), //
		_triggerAction(action) //
{

}

ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_collidingShape->setPosition(gameObject.getPosition());
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

const CollidingShape* ColliderComponent::getCollidingShape() const
{
	return _collidingShape;
}

CollidingShapeType ColliderComponent::getShapeType() const
{
	return _collidingShape->getType();
}

Actions::Action* ColliderComponent::getTriggerActionCopy()
{
	Actions::Action* temp(_triggerAction);
	_triggerAction = nullptr;
	return temp;
}

} /* namespace Components */
