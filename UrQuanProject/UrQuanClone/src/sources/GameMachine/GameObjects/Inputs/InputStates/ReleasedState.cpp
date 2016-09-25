/*
 * ReleasedState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/PressedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/DoubleTapState.h>
#include <iostream>


namespace Inputs
{

ReleasedState::ReleasedState(sf::Keyboard::Key key, bool doubleTap) :
		KeyState(key, InputType::INPUT_RELEASE),
		_doubleTap(doubleTap)
{

}

ReleasedState::~ReleasedState()
{
}

KeyState* ReleasedState::doUpdate(const sf::Time& deltaTime)
{
	if (!sf::Keyboard::isKeyPressed(_key))
		return nullptr;

	if (_timeElapsed.asMilliseconds() < DOUBLE_TAP_KEY_INTERVAL_MS && _doubleTap)
		return new DoubleTapState(_key);

	return new PressedState(_key);
}

void ReleasedState::onEnter()
{
	std::cout << "KEY >> " << _key << " << RELEASED" << std::endl;
}

void ReleasedState::onExit()
{
}

} /* namespace GameMachine */
