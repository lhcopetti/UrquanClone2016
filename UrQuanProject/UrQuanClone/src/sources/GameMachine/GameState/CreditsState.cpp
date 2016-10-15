/*
 * CreditsState.cpp
 *
 *  Created on: 26 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/CreditsState.h>

#include <GameMachine/StackControl/PopStackCommand.h>
#include <GameMachine/Components/Geometry/TimeBomb.h>

#include <GameMachine/Components/BlueDotComponent.h>
#include <GameMachine/InputControl/InputBuilder.h>

#include <iostream>

namespace GameState
{

enum CREDITS_INPUT
{
	ESCAPE
};

CreditsState::CreditsState(GameMachine::GameStateController& controller) :
		GameState(controller)
{
}

CreditsState::~CreditsState()
{
}

void CreditsState::doUpdate(const sf::Time& deltaTime)
{
	if (_goCollection.size() > 0)
		return;

	_counter += deltaTime;
	if (_counter < sf::seconds(5.0f))
		return;

	_counter = sf::Time::Zero;

	_goCollection.push(
			new Geometry::TimeBomb(new Components::BlueDotComponent,
					sf::seconds(5.0f)));
}

void CreditsState::onEnter()
{
	using namespace Inputs;

	InputBuilder builder;
	builder
		.bind({sf::Keyboard::Escape, INPUT_RELEASE})
		.to(ESCAPE)
		.applyFor(this)
		.on(_inputController)
		.run();
}

void CreditsState::onExit()
{
	_inputController.unregisterAsListener(
			Inputs::InputAction(sf::Keyboard::Escape, Inputs::INPUT_RELEASE),
			this);
}

void CreditsState::handleInput(int data)
{
	if (data != ESCAPE)
	{
		std::cout << "No handling routine for this data: " << data << std::endl;
		return;
	}

	_controller.addCommand(new GameMachine::PopStackCommand);
}

void CreditsState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Green);
}

} /* namespace GameMachine */
