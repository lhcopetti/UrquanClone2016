/*
 * SteeringBehavior.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERINGBEHAVIOR_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERINGBEHAVIOR_H_

#include <GameMachine/GameObjects/Behaviors/Behavior.h>
#include <string>

#include <vector>


namespace Behavior
{

class Steering;

class SteeringBehavior: public Behavior
{
public:
	SteeringBehavior(const std::string& target);
	virtual ~SteeringBehavior();

	void add(Steering* steering);
	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);

private:
	std::string _target;

	std::vector<Steering*> _steering;
};

} /* namespace Behavior */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_BEHAVIORS_STEERINGBEHAVIOR_H_ */
