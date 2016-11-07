/*
 * AimAction.h
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_AIMACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_AIMACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

class AimAction: public Action
{
public:
	AimAction();
	virtual ~AimAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_AIMACTION_H_ */
