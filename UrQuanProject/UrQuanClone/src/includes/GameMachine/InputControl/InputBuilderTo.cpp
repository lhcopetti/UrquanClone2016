/*
 * InputBuilderTo.cpp
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderTo.h>

namespace Inputs
{

InputBuilderTo::InputBuilderTo(InputBuilderTable table) :
		InputBuilderAbstract(table)
{
}

InputBuilderTo::~InputBuilderTo()
{
}

InputBuilderAdd Inputs::InputBuilderTo::bind(InputAction action)
{
	_table.startEntry(action);
	return InputBuilderAdd(_table);
}

InputBuilderApplyFor Inputs::InputBuilderTo::applyFor(
		InputHandler* inputHandler)
{
	_table.pushHandler(inputHandler);
	return InputBuilderApplyFor(_table);
}

} /* namespace Inputs */
