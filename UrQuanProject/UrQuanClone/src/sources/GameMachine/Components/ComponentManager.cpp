/*
 * ComponentManager.cpp
 *
 *  Created on: 7 de nov de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/ComponentManager.h>

#include <iostream>

namespace Components
{

ComponentManager::ComponentManager()
{
	// TODO Auto-generated constructor stub

}

ComponentManager::~ComponentManager()
{
	// TODO Auto-generated destructor stub
}

bool ComponentManager::init()
{
	return false;
}

bool ComponentManager::putComponent(GameObjectID id, Component* component)
{
	ComponentMap& map = _components[component->getType()];

	if (map[id] != nullptr)
	{
		std::cout << "Não é possível sobescrever o componente "
				<< component->toString() << " para o GameObject [" << id << "]"
				<< std::endl;
		return false;
	}

	map[id] = component;
	return true;
}

bool ComponentManager::removeComponent(GameObjectID id, Component* component)
{
	return false;
}

bool ComponentManager::removeComponent(GameObjectID id, ComponentType type)
{
	return false;
}

} /* namespace Components */
