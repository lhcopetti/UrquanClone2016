/*
 * ShipFactory.h
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_FACTORY_SHIPFACTORY_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_FACTORY_SHIPFACTORY_H_

#include <string>

namespace GameObjects
{
class GameObject;
class Ship;
}

namespace Components
{

class ShipFactory
{
public:
	ShipFactory();
	virtual ~ShipFactory();

	GameObjects::GameObject* createNew(const std::string& shipType);

};

}

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_FACTORY_SHIPFACTORY_H_ */
