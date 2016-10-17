/*
 * CollisionManager.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/GameObjectCollection.h>

#include <GameMachine/Components/Collision/CollisionManager.h>
#include <GameMachine/Components/Collision/CollisionResolver.h>

#include <iostream>

namespace Collision
{

CollisionManager::CollisionManager()
{
	// TODO Auto-generated constructor stub

}

CollisionManager::~CollisionManager()
{
	// TODO Auto-generated destructor stub
}

bool CollisionManager::checkCollision(GameObjects::GameObject& g1,
		GameObjects::GameObject& g2)
{
	CollisionResolver collider;

	if (!collider.resolve(g1, g2))
		return false;

	return true;
}

} /* namespace Collision */

void Collision::CollisionManager::run(
		GameObjects::GameObjectCollection& collection)
{
	std::vector<std::unique_ptr<GameObjects::GameObject>>& gameObjects =
			collection.getObjects();

	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		for (unsigned int j = i + 1; j < gameObjects.size(); j++)
		{
			if (!checkCollision(*gameObjects[i].get(), *gameObjects[j].get()))
				continue;

			std::cout << "Colisão detectada!" << std::endl;
		}
	}

}
