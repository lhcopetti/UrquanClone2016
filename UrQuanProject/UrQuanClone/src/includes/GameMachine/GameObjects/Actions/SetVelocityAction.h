/*
 * SetVelocityAction.h
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SETVELOCITYACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SETVELOCITYACTION_H_

#include <GameMachine/GameObjects/Actions/Action.h>
#include <SFML/System.hpp>

namespace Actions
{

class SetVelocityAction: public Action
{
public:
	SetVelocityAction(const sf::Vector2f& velocity);
	virtual ~SetVelocityAction();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);

private:
	const sf::Vector2f _velocity;
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_SETVELOCITYACTION_H_ */
