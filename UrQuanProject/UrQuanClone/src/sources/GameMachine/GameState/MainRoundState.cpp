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

#include <GameMachine/GameObjects/Ship/Ship.h>

#include <iostream>

namespace GameState
{

MainRoundState::MainRoundState(GameMachine::GameStateController& controller) :
		GameState(controller)
{
	Components::ShipFactory shipFactory;
	GameObjects::GameObject* shipPlayer1 = shipFactory.createNew(GameObjects::ShipType::SHIP_Soldier74);
	GameObjects::GameObject* shipPlayer2 = shipFactory.createNew(GameObjects::ShipType::SHIP_GAIJIN);

	sf::Vector2f center = GAME_SCREEN_CENTER_VECTOR;
	sf::Vector2f halfCenter(center.x / 2, center.y);

	shipPlayer1->setPosition(halfCenter);
	shipPlayer2->setPosition(sf::Vector2f(halfCenter.x * 3, halfCenter.y));
	_goCollection.push(shipPlayer1);
	_goCollection.push(shipPlayer2);
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
