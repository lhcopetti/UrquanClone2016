/*
 * Steering.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_STEERING_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_STEERING_H_

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Behavior
{

class Steering
{
public:
	Steering();
	virtual ~Steering();

	virtual sf::Vector2f compute(const sf::Time deltaTime,
			GameObjects::GameObject& origin, GameObjects::GameObject& target) = 0;
};

} /* namespace Behavior */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_STEERING_H_ */
