/*
 * KeyInput.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/KeyInput.h>

namespace Inputs
{

KeyInput::KeyInput(sf::Keyboard::Key key) :
	_key(key),
	_stateManager(key)
{

}

KeyInput::~KeyInput()
{
	// TODO Auto-generated destructor stub
}

} /* namespace GameMachine */

void Inputs::KeyInput::update(const sf::Time& deltaTime)
{
	_stateManager.update(deltaTime);
}
