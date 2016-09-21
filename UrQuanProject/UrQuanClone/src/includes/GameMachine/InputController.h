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
#include "GameMachine/GameObjects/Inputs/InputType.h"
#include "GameMachine/GameObjects/Inputs/InputAction.h"
#include "GameMachine/GameObjects/Inputs/InputHandler.h"
#include <vector>

using Inputs::KeyStateManager;

namespace GameObjects
{
class GameObject;
}

namespace GameMachine
{

class InputController
{
public:
	InputController();

	bool update(const sf::Time& deltaTime);

	virtual ~InputController();

	void registerAsListener(Inputs::InputAction inputAction,
			Inputs::InputHandler* inpHandler);
	void unregisterAsListener(Inputs::InputAction inputAction, Inputs::InputHandler* inpHandler);

private:

	Inputs::KeyInput* retrieveOrNew(const Inputs::InputAction& inputAction, bool* isNew = nullptr);

	std::vector<Inputs::KeyInput*> _inputKeys;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROLLER_H_ */
