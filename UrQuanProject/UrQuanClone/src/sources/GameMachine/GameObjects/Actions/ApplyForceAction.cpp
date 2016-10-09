/*
 * ApplyForceAction.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/ApplyForceAction.h>
#include <GameMachine/Components/PhysicsComponent.h>

namespace Actions
{

ApplyForceAction::ApplyForceAction(const sf::Vector2f& forceVector) :
		_forceToApply(forceVector)
{
}

ApplyForceAction::~ApplyForceAction()
{
}

bool ApplyForceAction::canExecute(GameObjects::GameObject& gameObject)
{
	return gameObject.getPhysicsComponent() != nullptr;
}

bool ApplyForceAction::execute(GameObjects::GameObject& gameObject)
{
	sf::Vector2f& forces = gameObject.getPhysicsComponent()->getForces();
	forces += _forceToApply;
	return true;
}

} /* namespace Inputs */
