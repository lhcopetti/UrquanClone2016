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

namespace Inputs
{

class KeyInput
{
public:
	KeyInput(sf::Keyboard::Key key);
	virtual ~KeyInput();

	void update(const sf::Time& deltaTime);


private:
	sf::Keyboard::Key _key;
	KeyStateManager _stateManager;

};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUT_H_ */
