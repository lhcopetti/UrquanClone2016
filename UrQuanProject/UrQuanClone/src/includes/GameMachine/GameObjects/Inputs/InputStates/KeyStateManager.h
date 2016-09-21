/*
 * KeyStateManager.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATEMANAGER_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATEMANAGER_H_

#include "KeyState.h"
#include <map>
#include <vector>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>

namespace Inputs
{
class InputHandler;

class KeyStateManager
{
public:
	KeyStateManager(sf::Keyboard::Key key);
	virtual ~KeyStateManager();

	void update(const sf::Time& deltaTime,
			std::map<Inputs::InputType, std::vector<Inputs::InputHandler*>>& handlers);

	void notifyListeners(std::vector<Inputs::InputHandler*>& handlers,
			const Inputs::InputAction& inputAction);

private:
	KeyState* _currentState;

//	std::map<>
};

} /* namespace GameMachine */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATEMANAGER_H_ */
