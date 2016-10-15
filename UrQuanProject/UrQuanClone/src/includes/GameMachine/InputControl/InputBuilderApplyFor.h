/*
 * InputBuilderApplyFor.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERAPPLYFOR_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERAPPLYFOR_H_

#include <GameMachine/InputControl/InputBuilderAbstract.h>
#include <GameMachine/GameObjects/GameObject.h>

namespace Inputs
{
class InputController;
class InputBuilderOn;

class InputBuilderApplyFor: public InputBuilderAbstract
{
public:
	InputBuilderApplyFor(InputBuilderTable table);
	virtual ~InputBuilderApplyFor();

	InputBuilderApplyFor andAlso(InputHandler* handler);

	InputBuilderOn on(InputController& inputController);
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERAPPLYFOR_H_ */
