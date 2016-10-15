/*
 * KeyInput.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/KeyInput.h>
#include <GameMachine/GameObjects/Inputs/InputType.h>
#include <GameMachine/GameObjects/Inputs/InputAction.h>

#include <GameMachine/GameObjects/Inputs/InputHandler.h>
#include <GameMachine/GameObjects/Inputs/InputHandlerParam.h>

#include <iostream>
#include <algorithm>

namespace Inputs
{

KeyInput::KeyInput(sf::Keyboard::Key key) :
		_key(key), _stateManager(key), _numListeners(0)
{

}

KeyInput::~KeyInput()
{
}

void KeyInput::update(const sf::Time& deltaTime)
{
	_stateManager.update(deltaTime, _actionHandlers);
}

const sf::Keyboard::Key Inputs::KeyInput::key() const
{
	return _key;
}

bool KeyInput::registerListener(Inputs::InputType type,
		Inputs::InputHandler* const handler, int handlerData)
{
	if (nullptr == handler)
		return false;

	if (!doRegister(type, handler, handlerData))
		return false;

	std::cout << "Registered Listener. Key: " << _key << " Type: "
			<< Inputs::stringInputType(type) << std::endl;
	_numListeners++;
	return true;
}

struct HandlerParamComp
{
	HandlerParamComp(InputHandler* handler) :
		_handler(handler) {}

	inline bool operator()(InputHandlerParam& handler) const
	{
		return handler.getHandler() == _handler;
	}

private:
	const InputHandler* _handler;
};

bool KeyInput::doRegister(const InputType& type, InputHandler* handler,
		int handlerData)
{
	std::vector<InputHandlerParam>& inputHandlersParam = _actionHandlers[type];

	auto it = std::find_if(inputHandlersParam.begin(), inputHandlersParam.end(), HandlerParamComp(handler));

	if (it != inputHandlersParam.end())
	{
		std::cout << "Listener already registered for: "
				<< stringInputType(type) << " and key: " << _key
				<< ". Aborting operation!" << std::endl;
		return false;
	}

	InputHandlerParam param(handler, handlerData);
	inputHandlersParam.push_back(param);
	return true;
}

bool KeyInput::unregisterListener(Inputs::InputType type,
		Inputs::InputHandler* listener)
{
	if (nullptr == listener)
		return false;

	if (!doUnregister(type, listener))
		return false;

	std::cout << "Unregistered Listener. Key: " << _key << " Type: "
			<< Inputs::stringInputType(type) << std::endl;
	_numListeners--;
	return true;
}

bool KeyInput::doUnregister(const Inputs::InputType& type,
		Inputs::InputHandler* handler)
{
	std::vector<Inputs::InputHandlerParam>& handlers = _actionHandlers[type];

	auto it = std::find_if(handlers.begin(), handlers.end(),
			HandlerParamComp(handler));

	if (it == handlers.end())
	{
		std::cout << "It was not possible to unregister a listener of type: "
				<< Inputs::stringInputType(type) << std::endl;
		return false;
	}

	handlers.erase(it);
	return true;
}

int KeyInput::getNumListeners() const
{
	return _numListeners;
}

} /* namespace GameMachine */
