/*
 * AimAction.cpp
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/AimAction.h>

#include <VectorMath/VectorMath.h>
#include <math.h>

#include <iostream>

namespace Actions
{

AimAction::AimAction()
{
	// TODO Auto-generated constructor stub

}

AimAction::~AimAction()
{
	// TODO Auto-generated destructor stub
}

bool AimAction::canExecute(GameObjects::GameObject& gameObject)
{
	return _context != nullptr;
}

bool AimAction::execute(GameObjects::GameObject& gameObject)
{
	sf::Vector2f angleVector = _context->getPosition() - gameObject.getPosition();

	float angle = VectorMath::toDegree(atan2f(angleVector.y, angleVector.x));
	gameObject.setOrientation(angle);
	return true;
}

} /* namespace Actions */
