/*
 * CollisionManager.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONMANAGER_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONMANAGER_H_

namespace GameObjects
{
class GameObjectCollection;
}

namespace Collision
{

class CollisionManager
{
public:
	CollisionManager();
	virtual ~CollisionManager();

	void run(GameObjects::GameObjectCollection& collection);

private:
	bool checkCollision(GameObjects::GameObject& g1, GameObjects::GameObject& g2);
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLISIONMANAGER_H_ */
