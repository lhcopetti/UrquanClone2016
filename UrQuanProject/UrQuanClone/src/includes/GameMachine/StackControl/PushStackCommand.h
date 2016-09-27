/*
 * PushStackCommand.h
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_STACKCONTROL_PUSHSTACKCOMMAND_H_
#define INCLUDES_GAMEMACHINE_STACKCONTROL_PUSHSTACKCOMMAND_H_

#include <GameMachine/StackControl/StackControlCommand.h>

namespace GameState
{
class GameState;
}

namespace GameMachine
{

class PushStackCommand: public StackControlCommand
{
public:
	PushStackCommand(GameState::GameState* gameState);
	virtual ~PushStackCommand();

	virtual void execute(std::stack<GameState::GameState*>& stack);

private:
	GameState::GameState* const _gameState;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_STACKCONTROL_PUSHSTACKCOMMAND_H_ */
