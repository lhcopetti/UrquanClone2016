/*
 * ReleasedState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/PressedState.h>
#include <iostream>


namespace Inputs
{

ReleasedState::ReleasedState(sf::Keyboard::Key key) :
		KeyState(key)
{

}

ReleasedState::~ReleasedState()
{
}

KeyState* ReleasedState::update(const sf::Time& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(_key))
	{
		return new PressedState(_key);
	}

	return nullptr;
}

void ReleasedState::onEnter()
{
	std::cout << "KEY >> " << _key << " << RELEASED" << std::endl;
}

void ReleasedState::onExit()
{
}

} /* namespace GameMachine */
