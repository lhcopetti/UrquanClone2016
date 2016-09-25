/*
 * DoubleTapState.h
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_DOUBLETAPSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_DOUBLETAPSTATE_H_

#include <GameMachine/GameObjects/Inputs/InputStates/KeyState.h>

namespace Inputs
{

class DoubleTapState: public KeyState
{
public:
	DoubleTapState(sf::Keyboard::Key key);
	virtual ~DoubleTapState();

	virtual void onEnter();
	virtual void onExit();
	virtual KeyState* doUpdate(const sf::Time& deltaTime);
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_DOUBLETAPSTATE_H_ */
