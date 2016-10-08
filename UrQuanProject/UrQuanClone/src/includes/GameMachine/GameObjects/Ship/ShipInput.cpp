/*
 * ShipInput.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Ship/ShipInput.h>

namespace GameObjects
{

#define SHIP_INPUT_PRINT_STRING(enum_type) \
case SHIP_##enum_type: return #enum_type;

const std::string shipInputString(ShipInput shipInput)
{
	switch(shipInput)
	{
		HIGH_ORDER_SHIP_INPUT(SHIP_INPUT_PRINT_STRING)
	}

	return "[Empty Ship Input]";
}

#undef SHIP_INPUT_PRINT_STRING

} /* namespace GameObjects */
