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

	void registerListener(Inputs::InputType type, Inputs::InputHandler* handler);
	void unregisterListener(Inputs::InputType type, Inputs::InputHandler* handler);

private:
	sf::Keyboard::Key _key;
	KeyStateManager _stateManager;


	Inputs::InputType _inputType;
	Inputs::InputHandler* _inputHandler;

};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_ */
