/*
 * ShootAction.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SHOOTACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SHOOTACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Armory
{
class Weapon;
}

namespace Actions
{

class ShootAction : public Action
{
public:
	ShootAction();
	virtual ~ShootAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SHOOTACTION_H_ */
