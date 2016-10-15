/*
 * InputBuilderAdd.cpp
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderAdd.h>

namespace Inputs
{

InputBuilderAdd::InputBuilderAdd(InputBuilderTable table) :
		InputBuilderAbstract(table)
{
}

InputBuilderAdd::~InputBuilderAdd()
{
}

InputBuilderAdd InputBuilderAdd::andAlso(InputAction action)
{
	_table.pushToCurrentEntry(action);
	return InputBuilderAdd(_table);
}

InputBuilderTo InputBuilderAdd::to(int code)
{
	_table.pushNewEntry(code);
	return InputBuilderTo(_table);
}

} /* namespace Inputs */
