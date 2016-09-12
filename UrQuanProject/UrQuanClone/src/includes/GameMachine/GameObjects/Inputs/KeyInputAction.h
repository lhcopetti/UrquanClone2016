/*
 * InputAction.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUTACTION_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUTACTION_H_

#include "InputType.h"

namespace Inputs
{

class KeyInputAction
{
public:
	KeyInputAction(const InputType inputType);
	virtual ~KeyInputAction();

private:
	const InputType _inputType;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_KEYINPUTACTION_H_ */
