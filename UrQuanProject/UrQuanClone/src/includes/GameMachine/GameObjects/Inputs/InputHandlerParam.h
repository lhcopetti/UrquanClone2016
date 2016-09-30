/*
 * InputHandlerParam.h
 *
 *  Created on: 29 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLERPARAM_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLERPARAM_H_

namespace Inputs
{

class InputHandler;

class InputHandlerParam
{
public:
	InputHandlerParam(InputHandler* handler = nullptr, const int data = -1);
	virtual ~InputHandlerParam();


	InputHandler* getHandler() const;
	int getData() const;

private:
	InputHandler* _handler;
	int _handlerData;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTHANDLERPARAM_H_ */
