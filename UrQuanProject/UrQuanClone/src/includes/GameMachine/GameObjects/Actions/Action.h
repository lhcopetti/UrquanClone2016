/*
 * Action.h
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace Actions
{

class Action
{
public:
	Action(bool isCallback = false);
	virtual ~Action();

	virtual bool canExecute(GameObjects::GameObject& gameObject);
	virtual bool execute(GameObjects::GameObject& gameObject) = 0;

	virtual void setContext(GameObjects::GameObject* context);

	bool isCallback();
	void setCallback();

protected:
	/*
	 * TODO: Substituir por um objeto que defina o contexto na qual a a��o ser� executada.
	 * Provavelmente abranger� bem mais que simplesmente o outro GameObject.
	 * Ex: Vetor normal, Separating Axis Theorem
	 */
	GameObjects::GameObject* _context;

private:
	/*
	 * Se a a��o � marcada como callback ela n�o ser� mais deletada
	 * ao fim de sua execu��o
	 */
	bool _isCallback;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ACTIONS_ACTION_H_ */
