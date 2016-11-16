/*
 * SteeringBehavior.cpp
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Behaviors/SteeringBehavior.h>
#include <GameMachine/GameObjects/Behaviors/Steering/Steering.h>

#include <GameMachine/GameObjects/Actions/ApplyForceAction.h>
#include <GameMachine/GameObjects/GameObjectCollection.h>

namespace Behavior
{

SteeringBehavior::SteeringBehavior(const std::string& target) :
		_target(target)
{
}

SteeringBehavior::~SteeringBehavior()
{
	for (Steering* s : _steering)
		delete s;
}

void SteeringBehavior::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	sf::Vector2f resultingForce;

	GameObjects::GameObject* namedObj = gameObject.getParent()->getNamedObject(_target);

	if (namedObj == nullptr)
		return;

	GameObjects::GameObject& origin = gameObject;
	GameObjects::GameObject& target = *namedObj;

	for (Steering* s : _steering)
		resultingForce += s->compute(deltaTime, origin, target);

	gameObject.pushAction(new Actions::ApplyForceAction(resultingForce));
}

void SteeringBehavior::add(Steering* steering)
{
	_steering.push_back(steering);
}

} /* namespace Behavior */
