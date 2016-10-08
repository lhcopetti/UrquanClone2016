/*
 * RotateByAction.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATEBYACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATEBYACTION_H_

#include <GameMachine/GameObjects/Actions/Rotation/RotateAction.h>

namespace Actions
{

class RotateByAction: public RotateAction
{
public:
	RotateByAction(float angle);
	virtual ~RotateByAction();

	virtual float execute(float gameObjectAngle);
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATION_ROTATEBYACTION_H_ */
