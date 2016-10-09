/*
 * Component.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENT_H_


namespace sf
{
class Time;
}

namespace GameObjects
{
class GameObject;
}

namespace Components
{

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject) = 0;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENT_H_ */
