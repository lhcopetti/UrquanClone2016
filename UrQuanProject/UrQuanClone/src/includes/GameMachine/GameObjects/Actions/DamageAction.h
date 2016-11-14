/*
 * DamageAction.h
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DAMAGEACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DAMAGEACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

class DamageAction : public Action
{
public:
	DamageAction(int damage);
	virtual ~DamageAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);

private:
	const int _damage;

};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DAMAGEACTION_H_ */
