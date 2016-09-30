/*
 * InputHandler.h
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLER_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLER_H_

namespace Inputs
{

class InputAction;

class InputHandler
{
public:
	virtual ~InputHandler() {}
	virtual void handleInput(int data) = 0;
};

} /* namespace Inputs */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLER_H_ */
