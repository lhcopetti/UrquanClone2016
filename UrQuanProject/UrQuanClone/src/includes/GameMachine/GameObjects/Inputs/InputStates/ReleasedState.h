/*
 * ReleasedState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_RELEASEDSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_RELEASEDSTATE_H_

#include "GameMachine/GameObjects/Inputs/InputStates/KeyState.h"

namespace Inputs
{

class ReleasedState : public KeyState
{
public:
	ReleasedState(sf::Keyboard::Key key, bool doubleTap = false);
	virtual ~ReleasedState();

	virtual KeyState* doUpdate(const sf::Time& deltaTime);

	virtual void onEnter();
	virtual void onExit();

private:
	bool _doubleTap;

};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_RELEASEDSTATE_H_ */
