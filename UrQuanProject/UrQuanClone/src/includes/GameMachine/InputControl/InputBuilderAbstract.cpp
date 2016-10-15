/*
 * InputBuilderAbstract.cpp
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderAbstract.h>

namespace Inputs
{

InputBuilderAbstract::InputBuilderAbstract(InputBuilderTable table) :
		_table(table)
{

}

InputBuilderAbstract::~InputBuilderAbstract()
{
}

} /* namespace Inputs */
