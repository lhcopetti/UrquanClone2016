/*
 * ActionExecutor.cpp
 *
 *  Created on: 7 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/ActionExecutor.h>
#include <GameMachine/GameObjects/Actions/Action.h>
#include <GameMachine/GameObjects/GameObject.h>

#include <iostream>


namespace Actions
{

ActionExecutor::ActionExecutor()
{
}

ActionExecutor::~ActionExecutor()
{
}

void ActionExecutor::push(Actions::Action* action)
{
	_actions.push_back(action);
}

bool ActionExecutor::update(GameObjects::GameObject& gameObject)
{
	std::vector<Actions::Action*>::iterator it = _actions.begin();

	while (it != _actions.end())
	{
		update(gameObject, *it);
		delete *it;
		it = _actions.erase(it);
	}

	return true;
}

bool ActionExecutor::update(GameObjects::GameObject& gameObject,
		Actions::Action* action)
{
	if (!action->canExecute(gameObject))
	{
		std::cout << "Ação não pôde ser executada!" << std::endl;
		return false;
	}

	return action->execute(gameObject);
}

} /* namespace Actions */
