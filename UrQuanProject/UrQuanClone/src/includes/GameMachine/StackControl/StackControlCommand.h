/*
 * StackControlCommand.h
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_STACKCONTROL_STACKCONTROLCOMMAND_H_
#define INCLUDES_GAMEMACHINE_STACKCONTROL_STACKCONTROLCOMMAND_H_

#include <stack>
#include <GameMachine/GameState/GameState.h>

namespace GameMachine
{

class StackControlCommand
{
public:
	StackControlCommand();
	virtual ~StackControlCommand();

	virtual void execute(std::stack<GameState::GameState*>& stack) = 0;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_STACKCONTROL_STACKCONTROLCOMMAND_H_ */
