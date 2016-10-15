/*
 * InputAction.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Inputs/KeyInputAction.h>

namespace Inputs
{

KeyInputAction::KeyInputAction(const InputType inputType) :
		_inputType(inputType)
{
}

KeyInputAction::~KeyInputAction()
{
}

} /* namespace Components */
