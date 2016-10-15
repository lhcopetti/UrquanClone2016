/*
 * InputBuilderInit.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERINIT_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERINIT_H_

#include <GameMachine/GameObjects/Inputs/InputAction.h>
#include <GameMachine/InputControl/InputBuilderAdd.h>

namespace Inputs
{

class InputBuilderInit
{
public:
	InputBuilderInit();
	virtual ~InputBuilderInit();

	virtual InputBuilderAdd bind(InputAction action) = 0;
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERINIT_H_ */
