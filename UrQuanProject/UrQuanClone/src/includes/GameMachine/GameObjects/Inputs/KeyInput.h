/*
 * KeyInput.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/system/Time.hpp>

#include "GameMachine/GameObjects/Inputs/InputStates/KeyStateManager.h"
#include <GameMachine/GameObjects/Inputs/InputType.h>

#include <map>
#include <vector>

namespace Inputs
{

class InputHandler;
class InputHandlerParam;

class KeyInput
{
public:
	KeyInput(sf::Keyboard::Key key);
	virtual ~KeyInput();

	void update(const sf::Time& deltaTime);

	const sf::Keyboard::Key key() const;

	bool registerListener(const InputType type, InputHandler* handler, int handlerData);
	bool unregisterListener(InputType type, InputHandler* handler);

	int getNumListeners() const;

private:

	bool doRegister(const InputType& type, InputHandler* handler, int handlerData);
	bool doUnregister(const InputType& type, InputHandler* handler);

	sf::Keyboard::Key _key;
	KeyStateManager _stateManager;
	int _numListeners;

	std::map<InputType, std::vector<InputHandlerParam>> _actionHandlers;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_ */
