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

class KeyInput
{
public:
	KeyInput(sf::Keyboard::Key key);
	virtual ~KeyInput();

	void update(const sf::Time& deltaTime);

	const sf::Keyboard::Key key() const;

	bool registerListener(const Inputs::InputType type, Inputs::InputHandler* handler);
	bool unregisterListener(Inputs::InputType type, Inputs::InputHandler* handler);

	int getNumListeners() const;

private:

	bool doRegister(const Inputs::InputType& type, Inputs::InputHandler* handler);
	bool doUnregister(const Inputs::InputType& type, Inputs::InputHandler* handler);

	sf::Keyboard::Key _key;
	KeyStateManager _stateManager;
	int _numListeners;

	std::map<Inputs::InputType, std::vector<Inputs::InputHandler*>> _actionHandlers;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_ */
