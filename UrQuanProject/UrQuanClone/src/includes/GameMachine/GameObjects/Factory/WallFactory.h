/*
 * WallFactory.h
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_WALLFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_WALLFACTORY_H_

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Factory
{

class WallFactory
{
public:
	WallFactory(sf::Color color);
	virtual ~WallFactory();

	GameObjects::GameObject* createNew(sf::Vector2f position, sf::Vector2f size);

private:
	sf::Color _color;
};

} /* namespace Geometry */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_WALLFACTORY_H_ */
