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

} /* namespace Components */
