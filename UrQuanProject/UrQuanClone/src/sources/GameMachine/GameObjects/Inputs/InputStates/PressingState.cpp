/*
 * PressingState.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputStates/PressingState.h>
#include <GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h>

namespace Inputs
{

PressingState::PressingState(sf::Keyboard::Key key, sf::Time time) :
		KeyState(key, InputType::INPUT_PRESSING, time)
{
}

PressingState::~PressingState()
{
}

void PressingState::onEnter()
{

}

void PressingState::onExit()
{

}

KeyState* PressingState::doUpdate(const sf::Time& deltaTime)
{
	if (!sf::Keyboard::isKeyPressed(_key))
	{
		return new ReleasedState(_key,
				_timeElapsed.asMilliseconds() < DOUBLE_TAP_KEY_INTERVAL_MS);
	}

	return new PressingState(_key, _timeElapsed);
}

} /* namespace Inputs */
