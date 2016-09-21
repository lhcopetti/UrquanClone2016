/*
 * PressedState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSEDSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSEDSTATE_H_

#include "GameMachine/GameObjects/Inputs/InputStates/KeyState.h"

namespace Inputs
{

class PressedState: public KeyState
{
public:
	PressedState(sf::Keyboard::Key key);
	virtual ~PressedState();

	virtual void onEnter();
	virtual void onExit();
	virtual KeyState* update(const sf::Time& deltaTime);


};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSEDSTATE_H_ */
