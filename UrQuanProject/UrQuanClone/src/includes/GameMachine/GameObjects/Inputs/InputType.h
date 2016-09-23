/*
 * InputType.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTTYPE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTTYPE_H_

#include <string>

namespace Inputs
{


#define HIGH_ORDER_INPUT_TYPE(code) \
	code(PRESS) \
	code(RELEASE) \
	code(DOUBLE_TAP) \
	code(PRESSING)


#define DEFINE_ENUM(enum_type) INPUT_##enum_type,

enum InputType
{
	HIGH_ORDER_INPUT_TYPE(DEFINE_ENUM)
};
#undef DEFINE_ENUM

const std::string stringInputType(InputType inputType);

//enum InputType
//{
//	PRESS,
//	RELEASE,
//	DOUBLE_TAP,
//	PRESSING
//};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTTYPE_H_ */
