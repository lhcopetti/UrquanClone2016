/*
 * InputController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputController.h>

namespace GameMachine
{

InputController::InputController()
{
	_inputKeys.push_back(new Inputs::KeyInput(sf::Keyboard::Key::W));
//	_inputKeys.push_back(Inputs::KeyInput(sf::Keyboard::Key::A));
//	_inputKeys.push_back(Inputs::KeyInput(sf::Keyboard::Key::S));
//	_inputKeys.push_back(Inputs::KeyInput(sf::Keyboard::Key::D));
//	_inputKeys.push_back(Inputs::KeyInput(sf::Keyboard::Key::BackSpace));
}

bool InputController::update(const sf::Time& deltaTime)
{
	for (auto& input : _inputKeys)
		input->update(deltaTime);
	return true;
}

InputController::~InputController()
{
}

void InputController::registerAsListener(Inputs::InputAction inputAction,
		Inputs::InputHandler* inpHandler)
{
	for (auto* inpKey : _inputKeys)
		if (inpKey->key() == inputAction.key())
			inpKey->registerListener(inputAction.inputType(), inpHandler);
}

void InputController::unregisterAsListener(Inputs::InputAction inputAction,
		Inputs::InputHandler* inpHandler)
{
	for (auto* inpKey : _inputKeys)
		if (inpKey->key() == inputAction.key())
			inpKey->unregisterListener(inputAction.inputType(), inpHandler);
}

} /* namespace GameMachine */
