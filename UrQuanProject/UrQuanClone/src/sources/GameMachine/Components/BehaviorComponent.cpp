/*
 * BehaviorComponent.cpp
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/BehaviorComponent.h>

#include <GameMachine/GameObjects/Behaviors/Behavior.h>

namespace Components
{

BehaviorComponent::BehaviorComponent(Behavior::Behavior* behavior) :
		_behavior(behavior)
{
}

BehaviorComponent::~BehaviorComponent()
{
	delete _behavior;
	_behavior = nullptr;
}

void BehaviorComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	if (nullptr == _behavior)
		return;

	_behavior->update(deltaTime, gameObject);
}

} /* namespace Behavior */
