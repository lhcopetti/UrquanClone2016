/*
 * InputBuilderTo.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTO_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTO_H_

#include <GameMachine/InputControl/InputBuilderAbstract.h>
#include <GameMachine/InputControl/InputBuilderAdd.h>
#include <GameMachine/InputControl/InputBuilderApplyFor.h>


namespace GameObjects
{
class GameObject;
}

namespace Inputs
{
class InputAction;
class InputBuilderAdd;
class InputBuilderApplyFor;
class InputHandler;

class InputBuilderTo : public InputBuilderAbstract
{
public:
	InputBuilderTo(InputBuilderTable table);
	virtual ~InputBuilderTo();

	InputBuilderAdd bind(InputAction action);

	InputBuilderApplyFor applyFor(InputHandler* inputHandler);
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTO_H_ */
