/*
 * Action.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

Action::Action()
{
	// TODO Auto-generated constructor stub

}

Action::~Action()
{
	// TODO Auto-generated destructor stub
}

bool Action::canExecute(GameObjects::GameObject& gameObject)
{
	/* Default empty implementation */
	return true;
}

} /* namespace Components */
