/*
 * Action.h
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace Actions
{

class Action
{
public:
	Action();
	virtual ~Action();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject) = 0;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_ */
