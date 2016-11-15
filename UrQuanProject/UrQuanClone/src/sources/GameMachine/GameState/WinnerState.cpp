/*
 * WinnerState.cpp
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/WinnerState.h>

#include <GameMachine/StackControl/PopStackCommand.h>

#include <GameMachine/InputControl/InputBuilder.h>

#include <GameMachine/GameObjects/Factory/ShipFactory.h>
#include <GameMachine/ResourceManager.h>
#include <GameClone/Defs.h>

#include <iostream>

namespace GameState
{

enum WINNER_INPUT
{
	ESCAPE
};

WinnerState::WinnerState(GameMachine::GameStateController& controller, GameObjects::ShipType winner, GameObjects::ShipType looser) :
				GameState(controller),
				_winner(winner),
				_looser(looser)
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

	Components::ShipFactory shipFactory;
	GameObjects::GameObject* shipWinner = shipFactory.createNew(PLAYER_ONE,
			_winner);
	GameObjects::GameObject* shipLooser = shipFactory.createNew(PLAYER_TWO,
			_looser);

	_textWinner.setFont(Resources::ResourceManager::get().getDefaultFont());
	_textWinner.setString("WINNER");
	_textWinner.setOrigin(sf::Vector2f(+60.f, +85.f));

	_textLooser.setFont(Resources::ResourceManager::get().getDefaultFont());
	_textLooser.setString("LOOSER");
	_textLooser.setOrigin(sf::Vector2f(+60.f, +85.f));

	sf::Vector2f center = GAME_SCREEN_CENTER_VECTOR;
	sf::Vector2f halfCenter(center.x / 2, center.y);
	shipWinner->setPosition(halfCenter);
	_textWinner.setPosition(halfCenter);

	shipLooser->setPosition(sf::Vector2f(halfCenter.x * 3, halfCenter.y));
	_textLooser.setPosition(sf::Vector2f(halfCenter.x * 3, halfCenter.y));

	shipWinner->setOrientation(+270);
	shipLooser->setOrientation(+270);

	_goCollection.push(shipWinner);
	_goCollection.push(shipLooser);
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
	window.draw(_textWinner);
	window.draw(_textLooser);
}

} /* namespace Armory */
