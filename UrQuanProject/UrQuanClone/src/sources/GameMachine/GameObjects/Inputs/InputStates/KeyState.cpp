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
		_timeElapsed(sf::seconds(0.0f)),
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

KeyState* KeyState::update(const sf::Time& deltaTime)
{
	_timeElapsed += deltaTime;

	return doUpdate(deltaTime);
}

const sf::Time& KeyState::getTimeElapsed() const
{
	return _timeElapsed;
}

} /* namespace GameMachine */
