/*
 * KeyInput.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/KeyInput.h>
#include <GameMachine/GameObjects/Inputs/InputType.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>
#include <GameMachine/GameObjects/Inputs/InputAction.h>

#include <iostream>
#include <algorithm>

namespace Inputs
{

KeyInput::KeyInput(sf::Keyboard::Key key) :
	_key(key),
	_stateManager(key)//,
//	_inputType(Inputs::InputType::PRESS),
//	_inputHandler(nullptr)
{

}

KeyInput::~KeyInput()
{
	// TODO Auto-generated destructor stub
}


void KeyInput::update(const sf::Time& deltaTime)
{
	_stateManager.update(deltaTime, _actionHandlers);
}

const sf::Keyboard::Key Inputs::KeyInput::key() const
{
	return _key;
}

void KeyInput::registerListener(Inputs::InputType type,
		Inputs::InputHandler* handler)
{
	if (nullptr == handler)
		return;

	std::cout << "Registering a Listener for key: " << _key << " Type: " << type << std::endl;
	std::vector<Inputs::InputHandler*>& handlers = _actionHandlers[type];
	handlers.push_back(handler);


//	_inputType = type;
//	_inputHandler = handler;
}

void KeyInput::unregisterListener(Inputs::InputType type,
		Inputs::InputHandler* listener)
{
//	if (nullptr == _inputHandler)
//		return;

	if (nullptr == listener)
		return;

//	if (handler != _inputHandler)
//		return;

	std::cout << "UNRegistering a Listener for key: " << _key << " Type: " << type << std::endl;
	std::vector<Inputs::InputHandler*>& handlers = _actionHandlers[type];
	auto it = std::find(handlers.begin(), handlers.end(), listener);
	if (it != handlers.end())
		handlers.erase(it);

//	_inputHandler = nullptr;
}

} /* namespace GameMachine */
