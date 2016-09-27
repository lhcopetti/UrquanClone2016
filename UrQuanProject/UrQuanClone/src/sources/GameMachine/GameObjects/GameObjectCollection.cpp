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
	// TODO Auto-generated constructor stub
}

GameObjectCollection::~GameObjectCollection()
{
	// TODO Auto-generated destructor stub
}


void GameObjectCollection::push(
		GameObjects::GameObject* gameObject)
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
	auto it = _gObjects.begin();

	while(it != _gObjects.end())
	{
		(*it)->update(deltaTime);

		if (!(*it)->isAlive())
			it = _gObjects.erase(it);
		else
			++it;
	}
	for (auto it = _gObjects.begin(); it != _gObjects.end(); ++it)
	{
		if (!(*it)->isAlive())
			_gObjects.erase(it);
	}
//	for (auto const& gO : _gObjects)
//	{
//		gO->update(deltaTime);
//	}
}

const unsigned int GameObjectCollection::size() const
{
	return _gObjects.size();
}

} /* namespace Components */
