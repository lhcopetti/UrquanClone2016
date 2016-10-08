/*
 * RotateToAction.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Rotation/RotateToAction.h>
#include <GameMachine/GameObjects/GameObject.h>

namespace Actions
{

RotateToAction::RotateToAction(float angle) :
				RotateAction(angle)
{
}

RotateToAction::~RotateToAction()
{
}

bool RotateToAction::execute(GameObjects::GameObject& gameObject)
{
	gameObject.setOrientation(_angle);
	return true;
}

} /* namespace Actions */
