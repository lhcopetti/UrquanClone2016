/*
 * CreditsState.cpp
 *
 *  Created on: 26 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/CreditsState.h>

#include <GameMachine/StackControl/PopStackCommand.h>

namespace GameState
{

CreditsState::CreditsState(GameMachine::GameStateController& controller) :
	GameState(controller)
{
}

CreditsState::~CreditsState()
{
}

void CreditsState::doUpdate(const sf::Time& deltaTime)
{
}

void CreditsState::onEnter()
{
	_inputController.registerAsListener(Inputs::InputAction(sf::Keyboard::Escape, Inputs::INPUT_RELEASE), this);
}

void CreditsState::onExit()
{
	_inputController.unregisterAsListener(Inputs::InputAction(sf::Keyboard::Escape, Inputs::INPUT_RELEASE), this);
}

void CreditsState::handleInput(Inputs::InputAction inputAction)
{
	if (inputAction.key() == sf::Keyboard::Escape)
		_controller.addCommand(new GameMachine::PopStackCommand);
}

void CreditsState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Green);
}

} /* namespace GameMachine */
