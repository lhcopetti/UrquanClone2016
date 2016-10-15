/*
 * InputBuilderOn.cpp
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderOn.h>

namespace Inputs
{

InputBuilderOn::InputBuilderOn(InputBuilderTable table) :
		InputBuilderAbstract(table)
{
}

InputBuilderOn::~InputBuilderOn()
{
}

void InputBuilderOn::run()
{
	_table.execute();
}

} /* namespace Inputs */
