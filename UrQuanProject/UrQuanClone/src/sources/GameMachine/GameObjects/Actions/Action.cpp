/*
 * Action.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

Action::Action(bool isCallback) :
		_context(nullptr), _isCallback(isCallback)
{
}

Action::~Action()
{
}

bool Action::canExecute(GameObjects::GameObject& gameObject)
{
	/* Default empty implementation */
	return true;
}

void Action::setContext(GameObjects::GameObject* context)
{
	_context = context;
}

bool Action::isCallback()
{
	return _isCallback;
}

void Action::setCallback()
{
	_isCallback = true;
}

} /* namespace Components */
