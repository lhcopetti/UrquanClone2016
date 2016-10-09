/*
 * PressingState.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSINGSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSINGSTATE_H_

#include <GameMachine/GameObjects/Inputs/InputStates/KeyState.h>

namespace Inputs
{

class PressingState: public KeyState
{
public:
	PressingState(sf::Keyboard::Key, sf::Time = sf::Time());
	virtual ~PressingState();

	virtual void onEnter();
	virtual void onExit();
	virtual KeyState* doUpdate(const sf::Time& deltaTime);
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_PRESSINGSTATE_H_ */
