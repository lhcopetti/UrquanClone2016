/*
 * ComponentManager.h
 *
 *  Created on: 7 de nov de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTMANAGER_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTMANAGER_H_

#include <GameMachine/Components/Component.h>
#include <GameMachine/Components/ComponentEnum.h>

#include <map>

namespace Components
{

enum Components
{
};

class ComponentManager
{
public:
	ComponentManager();
	virtual ~ComponentManager();

	bool init();

	bool putComponent(GameObjectID id, Component* component);

	bool removeComponent(GameObjectID id, Component* component);
	bool removeComponent(GameObjectID id, ComponentType type);

private:
	typedef std::map<GameObjectID, Component*> ComponentMap;
	std::map<ComponentType, ComponentMap> _components;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTMANAGER_H_ */
