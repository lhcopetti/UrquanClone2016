/*
 * InputBuilderOn.h
 *
 *  Created on: 12 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERON_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERON_H_

#include <GameMachine/InputControl/InputBuilderAbstract.h>
#include <GameMachine/InputControl/InputController.h>

namespace Inputs
{

class InputBuilderOn : public InputBuilderAbstract
{
public:
	InputBuilderOn(InputBuilderTable table);
	virtual ~InputBuilderOn();

	void run();
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERON_H_ */
