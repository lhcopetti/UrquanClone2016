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

float RotateByAction::execute(float gameObjectAngle)
{
	return gameObjectAngle + _angle;
}

} /* namespace Actions */
