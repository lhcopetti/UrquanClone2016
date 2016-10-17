/*
 * ColliderComponent.h
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLIDERCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLIDERCOMPONENT_H_

#include <GameMachine/Components/Collision/ColliderCategory.h>
#include <GameMachine/Components/Component.h>

namespace Collision
{
class CollidingShape;

class ColliderComponent: public Components::Component
{
public:
	ColliderComponent(CollidingShape* collidingShape);
	virtual ~ColliderComponent();

	virtual void update(const sf::Time& deltaTime,
			GameObjects::GameObject& gameObject);

	bool checkCategoryCollision(ColliderComponent* collider);

	CCategories getCategory() const;

private:
	CCategories _category;
	ColliderCategory _collidingCategory;

	CollidingShape* _collidingShape;
};

} /* namespace Geometry */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLIDERCOMPONENT_H_ */
