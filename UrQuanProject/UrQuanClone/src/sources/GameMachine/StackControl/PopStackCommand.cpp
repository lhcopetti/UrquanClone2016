/*
 * PopStackCommand.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/StackControl/PopStackCommand.h>

#include <iostream>

namespace GameMachine
{

PopStackCommand::PopStackCommand()
{
}

PopStackCommand::~PopStackCommand()
{
}

void PopStackCommand::execute(std::stack<GameState::GameState*>& stack)
{
	if (stack.size() == 0)
	{
		std::cout << "Tentativa de desempilhar uma pilha vazia!" << std::endl;
		return;
	}

	GameState::GameState* gameState = stack.top();
	stack.pop();
	delete gameState;
}

} /* namespace GameMachine */
