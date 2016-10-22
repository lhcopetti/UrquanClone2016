/*
 * TurretFactory.h
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_TURRETFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_TURRETFACTORY_H_

#include <SFML/System/Vector2.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Factory
{

class TurretFactory
{
public:
	TurretFactory();
	virtual ~TurretFactory();

	GameObjects::GameObject* createNew(sf::Vector2f position);
};

} /* namespace Factory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_TURRETFACTORY_H_ */
