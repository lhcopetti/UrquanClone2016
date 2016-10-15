/*
 * InputBuilderAbstract.h
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERABSTRACT_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERABSTRACT_H_

#include <GameMachine/InputControl/InputBuilderTable.h>

namespace Inputs
{

class InputBuilderAbstract
{
public:
	virtual ~InputBuilderAbstract();

protected:
	InputBuilderTable _table;
	InputBuilderAbstract(InputBuilderTable);

private:

};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERABSTRACT_H_ */
