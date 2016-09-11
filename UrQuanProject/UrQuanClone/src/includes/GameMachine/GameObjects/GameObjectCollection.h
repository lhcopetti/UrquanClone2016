/*
 * GameObjectCollection.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_

#include <vector>
#include "GameObject.h"

namespace GameObjects
{

class GameObjectCollection
{
public:
	GameObjectCollection();
	virtual ~GameObjectCollection();

	void push(GameObjects::GameObject* gameObject);
	void draw(sf::RenderWindow& window) const;

private:
	std::vector<std::unique_ptr<GameObject>> _gObjects;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_ */
