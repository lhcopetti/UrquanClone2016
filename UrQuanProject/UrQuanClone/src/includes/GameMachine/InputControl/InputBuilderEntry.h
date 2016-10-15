/*
 * BuilderEntry.h
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERENTRY_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERENTRY_H_

#include <GameMachine/GameObjects/Inputs/InputAction.h>
#include <vector>

namespace Inputs
{

class InputBuilderEntry
{
public:
	InputBuilderEntry();
	virtual ~InputBuilderEntry();

	void reset();
	void pushbackAction(InputAction action);

	void setCode(int code);

	const std::vector<InputAction>& getActions() const;
	int getCode() const;

private:
	int _code;
	std::vector<InputAction> _actions;
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERENTRY_H_ */
