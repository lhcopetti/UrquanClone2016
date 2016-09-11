/*
 * GameStateController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameStateController.h>
#include "SFML/System/Time.hpp"

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
	return true;
}

void GameStateController::deinit()
{
}

void GameStateController::update(const sf::Time& time)
{
}

void GameStateController::draw()
{
}

} /* namespace GameMachine */
