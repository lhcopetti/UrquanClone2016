/*
 * InputBuilderTable.h
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTABLE_H_
#define INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTABLE_H_

#include <GameMachine/GameObjects/Inputs/InputAction.h>
#include <GameMachine/InputControl/InputBuilderEntry.h>

namespace Inputs
{

class InputController;
class InputHandler;


class InputBuilderTable
{
public:
	InputBuilderTable();
	virtual ~InputBuilderTable();

	void startEntry(InputAction action);

	void pushToCurrentEntry(InputAction action);
	void pushNewEntry(int code);

	void pushHandler(InputHandler* inputHandler);

	void setInputController(InputController* controller);


	void execute();

private:
	void executeHandler(InputHandler* handler, unsigned int index);
	void executeEntryForHandler(InputHandler* handler, unsigned int index, const InputBuilderEntry& entry);


	InputBuilderEntry _currentEntry;
	std::vector<InputBuilderEntry> _entries;
	std::vector<InputHandler*> _handlers;

	InputController* _controller;
};

} /* namespace Inputs */

#endif /* INCLUDES_GAMEMACHINE_INPUTCONTROL_INPUTBUILDERTABLE_H_ */
