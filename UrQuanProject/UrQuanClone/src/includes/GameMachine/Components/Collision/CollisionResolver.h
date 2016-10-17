/*
 * CollisionResolver.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONRESOLVER_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONRESOLVER_H_

namespace GameObjects
{
class GameObject;
}

namespace Collision
{
class ColliderComponent;

class CollisionResolver
{
public:
	CollisionResolver();
	virtual ~CollisionResolver();

	bool resolve(GameObjects::GameObject& g1, GameObjects::GameObject& g2);

private:
	bool checkCategoriesCollision(ColliderComponent* c1, ColliderComponent* c2);
	bool checkShapeCollision(ColliderComponent* c1, ColliderComponent* c2);
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONRESOLVER_H_ */
