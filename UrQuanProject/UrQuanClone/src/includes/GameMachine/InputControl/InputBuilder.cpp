/*
 * InputBuilder.cpp
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilder.h>

namespace Inputs
{

InputBuilder::InputBuilder() :
		InputBuilderAbstract(InputBuilderTable())
{
}

InputBuilder::~InputBuilder()
{
}

InputBuilderAdd InputBuilder::bind(InputAction action)
{
	_table.startEntry(action);
	return InputBuilderAdd(_table);
}

} /* namespace Actions */

