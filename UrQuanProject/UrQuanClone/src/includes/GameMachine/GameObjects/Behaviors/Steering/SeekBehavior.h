/*
 * SeekBehavior.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_SEEKBEHAVIOR_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_SEEKBEHAVIOR_H_

#include <GameMachine/GameObjects/Behaviors/Steering/Steering.h>

namespace Behavior
{

class SeekBehavior: public Steering
{
public:
	SeekBehavior();
	virtual ~SeekBehavior();

	virtual sf::Vector2f compute(const sf::Time deltaTime,
			GameObjects::GameObject& origin, GameObjects::GameObject& target);
};

} /* namespace Behavior */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERING_SEEKBEHAVIOR_H_ */
