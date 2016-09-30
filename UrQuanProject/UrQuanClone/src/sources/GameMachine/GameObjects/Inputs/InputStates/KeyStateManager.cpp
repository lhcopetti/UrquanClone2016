/*
 * KeyStateManager.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameMachine/GameObjects/Inputs/InputStates/KeyStateManager.h"
#include "GameMachine/GameObjects/Inputs/InputStates/ReleasedState.h"

#include "GameMachine/GameObjects/Inputs/InputAction.h"
#include <GameMachine/GameObjects/Inputs/InputHandlerParam.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>

namespace Inputs
{

KeyStateManager::KeyStateManager(sf::Keyboard::Key key) :
		_currentState(new ReleasedState(key))
{
}

KeyStateManager::~KeyStateManager()
{
}

void KeyStateManager::update(const sf::Time& deltaTime,
		std::map<InputType, std::vector<InputHandlerParam>>& handlers)
{
	if (nullptr == _currentState)
		return;

	KeyState* nextState = nullptr;
	if ((nextState = _currentState->update(deltaTime)) == nullptr)
		return;

	_currentState->onExit();
	delete _currentState;
	_currentState = nextState;

	std::vector<Inputs::InputHandlerParam>& vectorHandler =
			handlers[_currentState->type()];
	_currentState->onEnter();

//	notifyListeners(vectorHandler,
//			Inputs::InputAction(_currentState->key(), _currentState->type()));
	notifyListeners(vectorHandler);
}

void KeyStateManager::notifyListeners(std::vector<InputHandlerParam>& handlers)
{
	for (auto handler : handlers)
	{
		InputHandler *const inputHandler = handler.getHandler();
		int userData = handler.getData();
		inputHandler->handleInput(userData);
	}
}
//void KeyStateManager::notifyListeners(std::vector<InputHandlerParam>& handlers,
//		const Inputs::InputAction& inputAction)
//{
//	for (auto* handler : handlers)
//		handler->handleInput(inputAction);
//}

} /* namespace GameMachine */
