/*
 * InputType.cpp
 *
 *  Created on: 23 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Inputs/InputType.h>

namespace Inputs
{

#define TO_STRING_INPUT_TYPE(type) case INPUT_##type: return "INPUT_" #type; break;

const std::string stringInputType(InputType inputType)
{
	switch (inputType)
	{
	HIGH_ORDER_INPUT_TYPE(TO_STRING_INPUT_TYPE)

	default:
		return "";

	}

}

#undef TO_STRING_INPUT_TYPE

}
