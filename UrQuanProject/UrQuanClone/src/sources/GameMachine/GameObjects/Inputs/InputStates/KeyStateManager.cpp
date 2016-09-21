/*
 * KeyStateManager.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameMachine/GameObjects/Inputs/InputStates/KeyStateManager.h"
#include "GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h"

#include "GameMachine/GameObjects/Inputs/InputAction.h"

namespace Inputs
{

KeyStateManager::KeyStateManager(sf::Keyboard::Key key) :
		_currentState(new Inputs::ReleasedState(key))
{
}

KeyStateManager::~KeyStateManager()
{
}

void KeyStateManager::update(const sf::Time& deltaTime,
		std::map<Inputs::InputType, std::vector<Inputs::InputHandler*>>& handlers)
{
	if (nullptr == _currentState)
		return;

	KeyState* nextState = nullptr;
	if ((nextState = _currentState->update(deltaTime)) == nullptr)
		return;

	_currentState->onExit();
	delete _currentState;
	_currentState = nextState;

	std::vector<Inputs::InputHandler*>& vectorHandler =
			handlers[_currentState->type()];
	_currentState->onEnter();

	notifyListeners(vectorHandler,
			Inputs::InputAction(_currentState->key(), _currentState->type()));
}

void KeyStateManager::notifyListeners(std::vector<Inputs::InputHandler*>& handlers,
		const Inputs::InputAction& inputAction)
{
	for (auto* handler : handlers)
		handler->handleInput(inputAction);
}

} /* namespace GameMachine */
