/*
 * SetVelocityAction.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>
#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/Components/PhysicsComponent.h>

namespace Actions
{

SetVelocityAction::SetVelocityAction(const sf::Vector2f& velocity) :
		_velocity(velocity)
{
}

SetVelocityAction::~SetVelocityAction()
{
	// TODO Auto-generated destructor stub
}

bool SetVelocityAction::canExecute(GameObjects::GameObject& gameObject)
{
	return gameObject.getPhysicsComponent() != nullptr;
}

bool SetVelocityAction::execute(GameObjects::GameObject& gameObject)
{
	gameObject.getPhysicsComponent()->setVelocity(_velocity);
	return true;
}

} /* namespace Actions */
