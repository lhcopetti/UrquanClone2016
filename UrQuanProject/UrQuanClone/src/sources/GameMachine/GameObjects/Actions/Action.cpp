/*
 * Action.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

Action::Action() :
		_context(nullptr)
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

} /* namespace Components */
