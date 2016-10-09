/*
 * ShipInput.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_SHIP_SHIPINPUT_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_SHIP_SHIPINPUT_H_

#include <string>

namespace GameObjects
{

#define HIGH_ORDER_SHIP_INPUT(code) \
	code(THRUST) \
	code(ROTATE_LEFT) \
	code(ROTATE_RIGHT) \


#define DEFINE_ENUM_SHIP_INPUT(enum_type) SHIP_##enum_type,

enum ShipInput
{
	HIGH_ORDER_SHIP_INPUT(DEFINE_ENUM_SHIP_INPUT)
};

const std::string shipInputString(ShipInput shipInput);

#undef DEFINE_ENUM_SHIP_INPUT

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_SHIP_SHIPINPUT_H_ */
