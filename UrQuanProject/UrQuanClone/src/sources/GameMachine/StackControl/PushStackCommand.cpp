/*
 * PushStackCommand.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/StackControl/PushStackCommand.h>
#include <GameMachine/GameState/GameState.h>

namespace GameMachine
{

PushStackCommand::PushStackCommand(GameState::GameState* gameState) :
		_gameState(gameState)
{
}

PushStackCommand::~PushStackCommand()
{
}

void PushStackCommand::execute(std::stack<GameState::GameState*>& stack)
{
	stack.push(_gameState);
}

} /* namespace GameMachine */
