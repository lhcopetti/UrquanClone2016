/*
 * InputHandlerParam.cpp
 *
 *  Created on: 29 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/InputHandlerParam.h>

namespace Inputs
{

InputHandlerParam::InputHandlerParam(InputHandler *const handler, const int data) :
		_handler(handler),
		_handlerData(data)
{
}

InputHandlerParam::~InputHandlerParam()
{
}

InputHandler* InputHandlerParam::getHandler() const
{
	return _handler;
}

int InputHandlerParam::getData() const
{
	return _handlerData;
}

} /* namespace Components */
