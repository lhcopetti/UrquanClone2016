/*
 * InputBuilder.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDER_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDER_H_

#include <GameMachine/InputControl/InputBuilderInit.h>
#include <GameMachine/InputControl/InputBuilderTo.h>
#include <GameMachine/InputControl/InputBuilderOn.h>

namespace Inputs
{

class InputBuilder : public InputBuilderAbstract
{
public:
	InputBuilder();
	virtual ~InputBuilder();

	virtual InputBuilderAdd bind(InputAction action);
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDER_H_ */
