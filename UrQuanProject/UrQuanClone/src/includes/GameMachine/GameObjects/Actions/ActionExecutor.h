/*
 * ActionExecutor.h
 *
 *  Created on: 7 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTIONEXECUTOR_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTIONEXECUTOR_H_

#include <vector>

namespace GameObjects
{
class GameObject;
}

namespace Actions
{

class Action;

class ActionExecutor
{
public:
	ActionExecutor();
	virtual ~ActionExecutor();

	void push(Actions::Action* action);

	bool update(GameObjects::GameObject& gameObject);

private:
	bool execute(GameObjects::GameObject& gameObject, Actions::Action* action);
	std::vector<Actions::Action*> _actions;
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTIONEXECUTOR_H_ */
