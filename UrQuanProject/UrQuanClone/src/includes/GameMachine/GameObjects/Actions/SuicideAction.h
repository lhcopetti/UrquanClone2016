/*
 * SuicideAction.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SUICIDEACTION_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SUICIDEACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

class SuicideAction: public Action
{
public:
	SuicideAction();
	virtual ~SuicideAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);
};

} /* namespace Actions */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SUICIDEACTION_H_ */
