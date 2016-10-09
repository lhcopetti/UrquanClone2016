/*
 * GameObjectCollection.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <vector>
#include "GameObject.h"

namespace GameObjects
{

class GameObjectCollection : public UpdatableFromTime
{
public:
	GameObjectCollection();
	virtual ~GameObjectCollection();

	void push(GameObjects::GameObject* gameObject);

	virtual void update(const sf::Time& deltaTime);
	void draw(sf::RenderWindow& window) const;

	const unsigned int size() const;

private:
	std::vector<std::unique_ptr<GameObject>> _gObjects;

	std::vector<GameObject*> _reproduction;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_ */
