/*
 * MainRoundState.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/MainRoundState.h>
#include <GameMachine/GameObjects/Factory/BlueCircle.h>

#include <GameMachine/GameObjects/Factory/ShipFactory.h>
#include <GameClone/Defs.h>

#include <iostream>

namespace GameState
{

MainRoundState::MainRoundState(GameMachine::GameStateController& controller) :
		GameState(controller)
{
	Components::ShipFactory shipFactory;

	GameObjects::GameObject* ship = shipFactory.createNew("PLAYER1");
	ship->setPosition(GAME_SCREEN_CENTER_VECTOR);
	_goCollection.push(ship);
}

MainRoundState::~MainRoundState()
{
}

void MainRoundState::onEnter()
{
	std::cout << "Entering MainRoundState" << std::endl;
	_goCollection.push(Components::BlueCircle::newBlueCircle());
}

void MainRoundState::onExit()
{
	std::cout << "Leaving MainRoundState" << std::endl;
}

void MainRoundState::doUpdate(const sf::Time& deltaTime)
{

}

void MainRoundState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Blue);
}

void MainRoundState::doDraw(sf::RenderWindow& window)
{
}

} /* namespace GameState */
