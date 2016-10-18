/*
 * GameObjectCollection.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObjectCollection.h>

namespace GameObjects
{

GameObjectCollection::GameObjectCollection()
{
}

GameObjectCollection::~GameObjectCollection()
{
}

void GameObjectCollection::push(GameObjects::GameObject* gameObject)
{
	_gObjects.push_back(std::unique_ptr<GameObject>(gameObject));
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


	auto it = _gObjects.begin();

	while (it != _gObjects.end())
	{
		(*it)->update(deltaTime);

		std::vector<GameObject*>& reproduction = (*it)->getProduced();
		for (unsigned int i = 0; i < reproduction.size(); ++i)
			_reproduction.push_back(reproduction[i]);
		reproduction.clear();

		if (!(*it)->isAlive())
			it = _gObjects.erase(it);
		else
			++it;
	}

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
