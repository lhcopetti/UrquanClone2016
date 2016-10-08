/*
 * RotateToAction.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATETOACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATETOACTION_H_

#include <GameMachine/GameObjects/Actions/Rotation/RotateAction.h>

namespace Actions
{

class RotateToAction: public RotateAction
{
public:
	RotateToAction(float angle);
	virtual ~RotateToAction();

	virtual bool execute(GameObjects::GameObject& gameObject);
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATETOACTION_H_ */
