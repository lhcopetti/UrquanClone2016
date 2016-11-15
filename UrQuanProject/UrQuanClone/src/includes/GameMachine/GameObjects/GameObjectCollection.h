/*
 * GameObjectCollection.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include "GameObject.h"

#include <vector>
#include <map>

namespace GameObjects
{

class GameObjectCollection : public UpdatableFromTime
{
public:
	GameObjectCollection();
	virtual ~GameObjectCollection();

	bool push(std::string name, GameObjects::GameObject* gameObject);
	bool push(GameObjects::GameObject* gameObject);

	virtual void update(const sf::Time& deltaTime);
	void draw(sf::RenderWindow& window) const;

	const unsigned int size() const;
	std::vector<std::unique_ptr<GameObject>>& getObjects();

	GameObject* getNamedObject(const std::string& name);

private:
	void update(GameObject* gameObject, const sf::Time& deltaTime);

	void updateGoCollection(const sf::Time& deltaTime);
	void removeDeadFromNamedGoCollection(const sf::Time& deltaTime);

	std::vector<std::unique_ptr<GameObject>> _gObjects;
	std::map<std::string, GameObject*> _namedObjects;

	std::vector<GameObject*> _reproduction;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_GAMEOBJECTCOLLECTION_H_ */
