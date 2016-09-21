/*
 * GameState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/GameState.h>

namespace GameState
{

GameState::GameState()
{
	// TODO Auto-generated constructor stub

}

GameState::~GameState()
{
	// TODO Auto-generated destructor stub
}

void GameState::update(const sf::Time& deltaTime)
{
	_goCollection.update(deltaTime);
	_inputController.update(deltaTime);
	doUpdate(deltaTime);
}

} /* namespace GameState */
