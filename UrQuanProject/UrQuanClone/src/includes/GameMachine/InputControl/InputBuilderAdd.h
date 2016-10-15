/*
 * InputBuilderAdd.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERADD_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERADD_H_

#include <GameMachine/InputControl/InputBuilderAbstract.h>
#include <GameMachine/InputControl/InputBuilderTo.h>

namespace Inputs
{

class InputBuilderTo;
class InputAction;

class InputBuilderAdd : public InputBuilderAbstract
{
public:
	InputBuilderAdd(InputBuilderTable table);
	virtual ~InputBuilderAdd();

	InputBuilderAdd andAlso(InputAction action);

	InputBuilderTo to(int code);

private:

};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERADD_H_ */
