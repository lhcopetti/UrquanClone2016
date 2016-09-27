/*
 * MainRoundState.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/MainRoundState.h>
#include <GameMachine/GameObjects/Factory/BlueCircle.h>

namespace GameState
{

MainRoundState::MainRoundState(GameMachine::GameStateController& controller) :
		GameState(controller)
{
	// TODO Auto-generated constructor stub

}

MainRoundState::~MainRoundState()
{
	// TODO Auto-generated destructor stub
}

void MainRoundState::onEnter()
{
	_goCollection.push(Components::BlueCircle::newBlueCircle());
}

void MainRoundState::onExit()
{

}

void MainRoundState::doUpdate(const sf::Time& deltaTime)
{

}

void MainRoundState::draw(sf::RenderWindow& window)
{
}

} /* namespace GameState */
