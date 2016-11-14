/*
 * ActionBundle.h
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DECORATIONS_ACTIONBUNDLE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DECORATIONS_ACTIONBUNDLE_H_

#include <GameMachine/GameObjects/Actions/Action.h>
#include <vector>

namespace Actions
{

class ActionBundle : public Action
{
public:
	ActionBundle();
	virtual ~ActionBundle();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject);

	virtual void setContext(GameObjects::GameObject* context);

	void add(Action* action);

private:
	std::vector<Action*> _bundle;
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_DECORATIONS_ACTIONBUNDLE_H_ */
