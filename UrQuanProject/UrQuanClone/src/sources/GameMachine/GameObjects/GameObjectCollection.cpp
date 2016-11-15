/*
 * GameObjectCollection.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObjectCollection.h>

#include <iostream>
#include <string>

namespace GameObjects
{

GameObjectCollection::GameObjectCollection()
{
}

GameObjectCollection::~GameObjectCollection()
{
}

bool GameObjectCollection::push(GameObjects::GameObject* gameObject)
{
	gameObject->_parent = this;
	_gObjects.push_back(std::unique_ptr<GameObject>(gameObject));
	return true;
}

bool GameObjectCollection::push(std::string name,
		GameObjects::GameObject* gameObject)
{
	if (name.empty())
	{
		std::cout << "Cannot name a GameObject to the empty string" << std::endl;
		return false;
	}

	if (_namedObjects.find(name) != _namedObjects.end())
	{
		std::cout << "There is already a GameObject named: " << name << " in this collection" << std::endl;
		return false;
	}

	_namedObjects[name] = gameObject;
	return push(gameObject);
}

void GameObjectCollection::draw(sf::RenderWindow& window) const
{
	for (auto const& gO : _gObjects)
	{
		gO->draw(window);
	}
}

void GameObjectCollection::update(const sf::Time& deltaTime)
{
	/* Add the reproduction list from the last pass */
	for (unsigned int i = 0; i < _reproduction.size(); ++i)
		_gObjects.push_back(std::unique_ptr<GameObject>(_reproduction[i]));
	_reproduction.clear();

	/*
	 * This one gotta go first!
	 * It will eventually hold invalid pointers if one of the gameObject dies
	 * */
	removeDeadFromNamedGoCollection(deltaTime);


	updateGoCollection(deltaTime);
}

void GameObjectCollection::updateGoCollection(const sf::Time& deltaTime)
{
	auto it = _gObjects.begin();

	while (it != _gObjects.end())
	{
		update(it->get(), deltaTime);

		if (!(*it)->isAlive())
			it = _gObjects.erase(it);
		else
			++it;
	}
}

GameObject* GameObjectCollection::getNamedObject(const std::string& name)
{
	auto it = _namedObjects.find(name);

	if (it == _namedObjects.end())
	{
		std::cout << "Não foi possível encontrar o GameObject: " << name << std::endl;
		return nullptr;
	}

	return it->second;
}

void GameObjectCollection::removeDeadFromNamedGoCollection(const sf::Time& deltaTime)
{
	auto mapIt = _namedObjects.begin();

	while (mapIt != _namedObjects.end())
	{
		if (!mapIt->second->isAlive())
			mapIt = _namedObjects.erase(mapIt);
		else
			++mapIt;
	}
}

void GameObjectCollection::update(GameObject* gameObject,
	const sf::Time& deltaTime)
{
	gameObject->update(deltaTime);

	std::vector<GameObject*>& reproduction = gameObject->getProduced();

	for (unsigned int i = 0; i < reproduction.size(); ++i)
		_reproduction.push_back(reproduction[i]);
	reproduction.clear();
}

const unsigned int GameObjectCollection::size() const
{
	return _gObjects.size();
}

std::vector<std::unique_ptr<GameObject>>& GameObjectCollection::getObjects()
{
	return _gObjects;
}

} /* namespace Components */
