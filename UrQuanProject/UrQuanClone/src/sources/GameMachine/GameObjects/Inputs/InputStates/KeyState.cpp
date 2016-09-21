/*
 * KeyState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/KeyState.h>

namespace Inputs
{

KeyState::KeyState(sf::Keyboard::Key key, InputType type) :
		_key(key),
		_type(type)
{
}

KeyState::~KeyState()
{
}

InputType KeyState::type() const
{
	return _type;
}

sf::Keyboard::Key KeyState::key() const
{
	return _key;
}

} /* namespace GameMachine */
