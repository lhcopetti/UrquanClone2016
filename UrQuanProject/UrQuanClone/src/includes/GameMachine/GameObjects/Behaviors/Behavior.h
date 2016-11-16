/*
 * Behavior.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_BEHAVIOR_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_BEHAVIOR_H_

#include <SFML/System/Time.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Behavior
{

class Behavior
{
public:
	Behavior();
	virtual ~Behavior();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject) = 0;
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_BEHAVIOR_H_ */
