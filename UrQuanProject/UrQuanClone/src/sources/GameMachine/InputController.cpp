/*
 * InputController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputController.h>

namespace GameMachine
{

InputController::InputController() :
		_inputKey(sf::Keyboard::Key::W)
{

}

bool InputController::update(const sf::Time& deltaTime)
{
	_inputKey.update(deltaTime);
	return true;
}

InputController::~InputController()
{
	// TODO Auto-generated destructor stub
}

} /* namespace GameMachine */
