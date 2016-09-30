/*
 * InputController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputController.h>

#include <algorithm>
#include <iostream>

namespace GameMachine
{

InputController::InputController()
{
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
		Inputs::InputHandler* inpHandler, int handlerData)
{
	bool isNew = false;
	Inputs::KeyInput* inputKey = retrieveOrNew(inputAction, &isNew);

	if (isNew)
		_inputKeys.push_back(inputKey);

	inputKey->registerListener(inputAction.inputType(), inpHandler, handlerData);
}

void InputController::unregisterAsListener(Inputs::InputAction inputAction,
		Inputs::InputHandler* inpHandler)
{
	std::vector<Inputs::KeyInput*>::iterator it = _inputKeys.begin();

	for (auto it = _inputKeys.begin(); it != _inputKeys.end(); ++it)
		if ((*it)->key() == inputAction.key())
		{
			if ((*it)->unregisterListener(inputAction.inputType(), inpHandler) && (*it)->getNumListeners() == 0)
			{
				delete *it;
				_inputKeys.erase(it);
				return;
			}
		}

//	for (auto* inpKey : _inputKeys)
//	{
//		if (inpKey->key() == inputAction.key())
//		{
//			if (inpKey->unregisterListener(inputAction.inputType(), inpHandler) && inpKey->getNumListeners() == 0)
//
//			return;
//		}
//	}

	std::cout << "Attempt to unregister a Listener Failed. Input: "
			<< inputAction.key() << " Type: " << inputAction.inputType()
			<< std::endl;
}

Inputs::KeyInput* InputController::retrieveOrNew(
		const Inputs::InputAction& inputAction, bool* isNew)
{
	auto found = std::find_if(_inputKeys.begin(), _inputKeys.end(),
				[&, inputAction] (Inputs::KeyInput* kI)
				{	return kI->key() == inputAction.key();});

	if (found == _inputKeys.end() && nullptr != isNew)
	{
		*isNew = true;
		return new Inputs::KeyInput(inputAction.key());
	}

	*isNew = false;
	return *found;
}

} /* namespace GameMachine */
