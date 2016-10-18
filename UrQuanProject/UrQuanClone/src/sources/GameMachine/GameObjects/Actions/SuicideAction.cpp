/*
 * SuicideAction.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Actions/SuicideAction.h>

namespace Actions
{

SuicideAction::SuicideAction()
{
	// TODO Auto-generated constructor stub

}

SuicideAction::~SuicideAction()
{
	// TODO Auto-generated destructor stub
}

bool SuicideAction::canExecute(GameObjects::GameObject& gameObject)
{
	return gameObject.isAlive();
}

bool SuicideAction::execute(GameObjects::GameObject& gameObject)
{
	gameObject.die();
	return true;
}

} /* namespace Actions */
