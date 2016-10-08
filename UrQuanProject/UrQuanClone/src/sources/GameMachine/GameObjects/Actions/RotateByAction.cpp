/*
 * RotateByAction.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Rotation/RotateByAction.h>
#include <GameMachine/GameObjects/GameObject.h>

namespace Actions
{

RotateByAction::RotateByAction(float angle) :
		RotateAction(angle)
{
}

RotateByAction::~RotateByAction()
{
}

bool RotateByAction::execute(GameObjects::GameObject& gameObject)
{
	float newAngle = (gameObject.getOrientation() + _angle);

	if (newAngle > 360.f)
		newAngle -= 360.f;
	else if (newAngle < 0.f)
		newAngle += 360.f;

	gameObject.setOrientation(newAngle);
	return true;
}

} /* namespace Actions */
