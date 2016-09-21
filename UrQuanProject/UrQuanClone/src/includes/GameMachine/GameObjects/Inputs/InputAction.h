/*
 * InputAction.h
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTACTION_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTACTION_H_

#include <GameMachine/GameObjects/Inputs/InputType.h>
#include <SFML/Window/Keyboard.hpp>

namespace Inputs
{

class InputAction
{
public:
	InputAction(sf::Keyboard::Key key, Inputs::InputType inputType);
	virtual ~InputAction();

	const sf::Keyboard::Key key() const;
	const Inputs::InputType inputType() const;


private:
	const sf::Keyboard::Key _key;
	const Inputs::InputType _inputType;
};

} /* namespace Inputs */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTACTION_H_ */
