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
		KeyState(key)
{
	// TODO Auto-generated constructor stub

}

PressedState::~PressedState()
{
	// TODO Auto-generated destructor stub
}

KeyState* PressedState::update(const sf::Time& deltaTime)
{
	if (!sf::Keyboard::isKeyPressed(_key))
	{
		return new ReleasedState(_key);
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
