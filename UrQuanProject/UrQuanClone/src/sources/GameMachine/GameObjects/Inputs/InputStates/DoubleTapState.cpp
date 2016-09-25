/*
 * DoubleTapState.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/DoubleTapState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/PressedState.h>

#include <iostream>

namespace Inputs
{

DoubleTapState::DoubleTapState(sf::Keyboard::Key key) :
		KeyState(key, InputType::INPUT_DOUBLE_TAP)
{
}

DoubleTapState::~DoubleTapState()
{
}

void DoubleTapState::onEnter()
{
	std::cout << "KEY >> " << _key << " << DOUBLE-TAPPED" << std::endl;
}

void DoubleTapState::onExit()
{

}

KeyState* DoubleTapState::doUpdate(const sf::Time& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(_key))
	{
		return new PressedState(_key);
	}
	else
	{
		return new ReleasedState(_key);
	}
}

} /* namespace Components */
