/*
 * GameStateController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameStateController.h>
#include <GameMachine/GameState/GameState.h>

#include <GameMachine/StackControl/StackControlCommand.h>

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

	_states.push(initialState);
	_states.top()->onEnter();

	return true;
}

void GameStateController::deinit()
{
}

bool GameStateController::update(const sf::Time& time)
{
	_states.top()->update(time);

	executeCommands();

	return _states.size() > 0;
}

void GameStateController::draw(sf::RenderWindow& window)
{
	GameState::GameState* gameState = _states.top();

	gameState->draw(window);
}

void GameStateController::addCommand(StackControlCommand* command)
{
	_stackCommands.push_back(command);
}

void GameStateController::executeCommands()
{
	for (auto it = _stackCommands.begin(); it != _stackCommands.end(); ++it)
	{
		(*it)->execute(_states);
		delete *it;
	}
	_stackCommands.clear();
}

} /* namespace GameMachine */
