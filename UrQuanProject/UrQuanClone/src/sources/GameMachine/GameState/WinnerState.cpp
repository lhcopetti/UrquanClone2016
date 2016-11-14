/*
 * WinnerState.cpp
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/WinnerState.h>

#include <GameMachine/StackControl/PopStackCommand.h>

#include <GameMachine/InputControl/InputBuilder.h>

#include <iostream>

namespace GameState
{

enum WINNER_INPUT
{
	ESCAPE
};

WinnerState::WinnerState(GameMachine::GameStateController& controller) :
				GameState(controller)
{
	// TODO Auto-generated constructor stub
}

WinnerState::~WinnerState()
{
	// TODO Auto-generated destructor stub
}

void WinnerState::onEnter()
{
	using namespace Inputs;

	InputBuilder builder;
	builder.bind(
	{ sf::Keyboard::Escape, INPUT_RELEASE }).to(ESCAPE).applyFor(this).on(
			_inputController).run();
}

void WinnerState::onExit()
{
	_inputController.unregisterAsListener(
			Inputs::InputAction(sf::Keyboard::Escape, Inputs::INPUT_RELEASE),
			this);
}

void WinnerState::handleInput(int data)
{
	if (data != ESCAPE)
	{
		std::cout << "No handling routine for this type of data: " << data
				<< std::endl;
		return;
	}

	_controller.addCommand(new GameMachine::PopStackCommand);
}

void WinnerState::doUpdate(const sf::Time& deltaTime)
{
}

void WinnerState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Cyan);
}

} /* namespace Armory */
