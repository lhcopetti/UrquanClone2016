/*
 * InputAction.cpp
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Inputs/InputAction.h>

namespace Inputs
{

InputAction::InputAction(sf::Keyboard::Key key, Inputs::InputType inputType) :
		_key(key),
		_inputType(inputType)
{
}

InputAction::~InputAction()
{
}

const sf::Keyboard::Key InputAction::key() const
{
	return _key;
}

const Inputs::InputType InputAction::inputType() const
{
	return _inputType;
}

} /* namespace Inputs */

