/*
 * InputController.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROLLER_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROLLER_H_

#include <GameMachine/GameObjects/Inputs/InputStates/KeyStateManager.h>
#include <GameMachine/GameObjects/Inputs/KeyInput.h>

using Inputs::KeyStateManager;

namespace GameMachine
{

class InputController
{
public:
	InputController();

	bool update(const sf::Time& deltaTime);

	virtual ~InputController();

private:

	Inputs::KeyInput _inputKey;

};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROLLER_H_ */
