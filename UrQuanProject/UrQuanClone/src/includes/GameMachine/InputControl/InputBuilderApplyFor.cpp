/*
 * InputBuilderApplyFor.cpp
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderApplyFor.h>
#include <GameMachine/InputControl/InputBuilderOn.h>

namespace Inputs
{

InputBuilderApplyFor::InputBuilderApplyFor(InputBuilderTable table) :
		InputBuilderAbstract(table)
{

}

InputBuilderApplyFor::~InputBuilderApplyFor()
{
	// TODO Auto-generated destructor stub
}

InputBuilderApplyFor InputBuilderApplyFor::andAlso(
		InputHandler* handler)
{
	_table.pushHandler(handler);
	return InputBuilderApplyFor(_table);
}

InputBuilderOn InputBuilderApplyFor::on(InputController& inputController)
{
	_table.setInputController(&inputController);
	return InputBuilderOn(_table);
}

} /* namespace Inputs */
