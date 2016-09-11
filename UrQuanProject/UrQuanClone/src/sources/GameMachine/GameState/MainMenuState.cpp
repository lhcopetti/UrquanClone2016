/*
 * MainMenuState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/MainMenuState.h>

#include "GameMachine/GameObjects/Factory/BlueCircle.h"

namespace GameState
{

MainMenuState::MainMenuState()
{
	// TODO Auto-generated constructor stub

}

MainMenuState::~MainMenuState()
{
	// TODO Auto-generated destructor stub
}

void MainMenuState::update(const sf::Time& deltaTime)
{
}

void MainMenuState::draw(sf::RenderWindow& window)
{

	window.clear(sf::Color::Red);

	_goCollection.draw(window);
}


void MainMenuState::onEnter()
{
	_goCollection.push(Components::BlueCircle::newBlueCircle());
}

void MainMenuState::onExit()
{
}

} /* namespace GameState */
