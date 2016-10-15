/*
 * BuilderEntry.cpp
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputBuilderEntry.h>

namespace Inputs
{

InputBuilderEntry::InputBuilderEntry() :
		_code(-1)
{
}

InputBuilderEntry::~InputBuilderEntry()
{
	// TODO Auto-generated destructor stub
}

void InputBuilderEntry::reset()
{
	_code = -1;
	_actions.clear();
}

void InputBuilderEntry::pushbackAction(InputAction action)
{
	_actions.push_back(action);
}

void InputBuilderEntry::setCode(int code)
{
	_code = code;
}

const std::vector<InputAction>& Inputs::InputBuilderEntry::getActions() const
{
	return _actions;
}

int Inputs::InputBuilderEntry::getCode() const
{
	return _code;
}

} /* namespace Inputs */
