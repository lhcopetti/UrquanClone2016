/*
 * PressedState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/PressedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h>
#include <iostream>

namespace Inputs
{

PressedState::PressedState(sf::Keyboard::Key key) :
		KeyState(key, InputType::INPUT_PRESS)
{

}

PressedState::~PressedState()
{
	// TODO Auto-generated destructor stub
}

KeyState* PressedState::doUpdate(const sf::Time& deltaTime)
{
	if (!sf::Keyboard::isKeyPressed(_key))
	{
		return new ReleasedState(_key, _timeElapsed.asMilliseconds() < DOUBLE_TAP_KEY_INTERVAL_MS);
	}

	return nullptr;
}

void PressedState::onEnter()
{
	std::cout << "KEY >> " << _key << " << PRESSED" << std::endl;
}

void PressedState::onExit()
{
}


} /* namespace Inputs */
