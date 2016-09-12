/*
 * KeyStateManager.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameMachine/GameObjects/Inputs/InputStates/KeyStateManager.h"
#include "GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h"

namespace Inputs
{

KeyStateManager::KeyStateManager(sf::Keyboard::Key key) :
		_currentState(new Inputs::ReleasedState(key))
{
	_currentState->onEnter();
}

KeyStateManager::~KeyStateManager()
{
}


void KeyStateManager::update(const sf::Time& deltaTime)
{
	if (nullptr == _currentState)
		return;

	KeyState* nextState = nullptr;
	if ((nextState = _currentState->update(deltaTime)) == nullptr)
		return;

	_currentState->onExit();
	delete _currentState;
	_currentState = nextState;
	_currentState->onEnter();
}

} /* namespace GameMachine */
