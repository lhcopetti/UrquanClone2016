/*
 * ApplyForceAction.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_APPLYFORCEACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_APPLYFORCEACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>

namespace Actions
{

class ApplyForceAction: public Action
{
public:
	ApplyForceAction(const sf::Vector2f& forceVector);
	virtual ~ApplyForceAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);

private:
	sf::Vector2f _forceToApply;
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_APPLYFORCEACTION_H_ */
