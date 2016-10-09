/*
 * PressedState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/PressedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/PressingState.h>
#include <iostream>

namespace Inputs
{

PressedState::PressedState(sf::Keyboard::Key key) :
		KeyState(key, InputType::INPUT_PRESS)
{

}

PressedState::~PressedState()
{
}

KeyState* PressedState::doUpdate(const sf::Time& deltaTime)
{
	return new PressingState(_key);
}

void PressedState::onEnter()
{
	std::cout << "KEY >> " << _key << " << PRESSED" << std::endl;
}

void PressedState::onExit()
{
}

} /* namespace Inputs */
