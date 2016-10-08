/*
 * RotateAction.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATEACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATEACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace GameObjects
{
class GameObject;
}

namespace Actions
{

class RotateAction: public Action
{
public:
	RotateAction(float angle);
	virtual ~RotateAction();

	virtual bool execute(GameObjects::GameObject& gameObject) = 0;

protected:
	float _angle;
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ROTATEACTION_H_ */
