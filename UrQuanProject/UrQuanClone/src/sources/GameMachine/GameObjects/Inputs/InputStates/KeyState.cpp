/*
 * KeyState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/KeyState.h>

namespace Inputs
{

KeyState::KeyState(sf::Keyboard::Key key) :
		_key(key)
{
}

KeyState::~KeyState()
{
}

} /* namespace GameMachine */
