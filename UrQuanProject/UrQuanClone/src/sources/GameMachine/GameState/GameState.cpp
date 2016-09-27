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
	// TODO Auto-generated destructor stub
}

void GameState::update(const sf::Time& deltaTime)
{
	_goCollection.update(deltaTime);
	_inputController.update(deltaTime);
	doUpdate(deltaTime);
}

//bool GameState::pushState(GameState* gameState)
//{
//	std::stack<GameState*> stateStack = _controller.getStack();
//	stateStack.push(gameState);
//
//	return true;
//}
//
//bool GameState::popState()
//{
//	std::stack<GameState*> stateStack = _controller.getStack();
//
//	GameState* lastState = stateStack.top();
//	stateStack.pop();
//	delete lastState;
//
//	return true;
//}

} /* namespace GameState */

