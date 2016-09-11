/*
 * GameStateController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameStateController.h>
#include "SFML/System/Time.hpp"
#include <iostream>

namespace GameMachine
{

GameStateController::GameStateController()
{

}

GameStateController::~GameStateController()
{
}

bool GameStateController::init(GameState::GameState* initialState)
{
	if (nullptr == initialState)
	{
		std::cout << "Null pointer at GameStateController!" << std::endl;
		return false;
	}

	_currentState = std::unique_ptr<GameState::GameState>(initialState);
	_currentState->onEnter();

	return true;
}

void GameStateController::deinit()
{
}

void GameStateController::update(const sf::Time& time)
{
	_currentState->update(time);
}

void GameStateController::draw(sf::RenderWindow& window)
{
	_currentState->draw(window);
}

} /* namespace GameMachine */
