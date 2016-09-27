/*
 * PopStackCommand.h
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_STACKCONTROL_POPSTACKCOMMAND_H_
#define INCLUDES_GAMEMACHINE_STACKCONTROL_POPSTACKCOMMAND_H_

#include <GameMachine/StackControl/StackControlCommand.h>

namespace GameMachine
{

class PopStackCommand : public StackControlCommand
{
public:
	PopStackCommand();
	virtual ~PopStackCommand();

	virtual void execute(std::stack<GameState::GameState*>& stack);
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_STACKCONTROL_POPSTACKCOMMAND_H_ */
