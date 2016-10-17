/*
 * GameState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/GameState.h>
#include <iostream>

namespace GameState
{

GameState::GameState(GameMachine::GameStateController& controller) :
		_controller(controller)
{
}

GameState::~GameState()
{
}

void GameState::update(const sf::Time& deltaTime)
{
	_goCollection.update(deltaTime);
	_collisionManager.run(_goCollection);
	_inputController.update(deltaTime);
	doUpdate(deltaTime);
}

void GameState::draw(sf::RenderWindow& window)
{
	doBeforeDraw(window);
	_goCollection.draw(window);
	doDraw(window);
}

void GameState::doBeforeDraw(sf::RenderWindow& window) const
{
}

void GameState::GameState::doDraw(sf::RenderWindow& window)
{
}

} /* namespace GameState */

