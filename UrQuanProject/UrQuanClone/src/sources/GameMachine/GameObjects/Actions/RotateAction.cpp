/*
 * RotateAction.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Rotation/RotateAction.h>
#include <GameMachine/GameObjects/GameObject.h>

namespace Actions
{

RotateAction::RotateAction(float angle) :
		_angle(angle)
{
}

RotateAction::~RotateAction()
{
}

bool RotateAction::execute(GameObjects::GameObject& gameObject)
{
	float newAngle = execute(gameObject.getOrientation());

	if (newAngle < 0)
		newAngle += 360.f;

	if (newAngle >= 360.f)
		newAngle -= 360.f;

	gameObject.setOrientation(newAngle);
	return true;
}

} /* namespace Actions */
