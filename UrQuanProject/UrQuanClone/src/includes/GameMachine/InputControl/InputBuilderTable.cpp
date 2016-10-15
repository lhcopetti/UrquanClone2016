/*
 * InputBuilderTable.cpp
 *
 *  Created on: 13 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/InputControl/InputController.h>
#include <GameMachine/InputControl/InputBuilderTable.h>

#include <iostream>

namespace Inputs
{

InputBuilderTable::InputBuilderTable() :
		_controller(nullptr)
{
}

InputBuilderTable::~InputBuilderTable()
{
}

void Inputs::InputBuilderTable::startEntry(InputAction action)
{
	_currentEntry.reset();
	_currentEntry.pushbackAction(action);
}

void InputBuilderTable::pushToCurrentEntry(InputAction action)
{
	_currentEntry.pushbackAction(action);
}

void InputBuilderTable::pushNewEntry(int code)
{
	_currentEntry.setCode(code);

	if (_currentEntry.getActions().size() == 0)
	{
		std::cout << "Criando entrada em InputBuilder vazia para o código: "
				<< code << "!" << std::endl;
	}

	_entries.push_back(_currentEntry);
	_currentEntry.reset();
}

void InputBuilderTable::pushHandler(InputHandler* handler)
{
	if (nullptr == handler)
	{
		std::cout
				<< "Tentativa de inserir InputHandler nulo no InputBuilderTable"
				<< std::endl;
		return;
	}

	_handlers.push_back(handler);
}

void InputBuilderTable::setInputController(InputController* controller)
{
	if (nullptr == controller)
	{
		std::cout << "Tentativa de atribuir valor nulo ao InputController"
				<< std::endl;
		return;
	}
	_controller = controller;
}

void InputBuilderTable::execute()
{
	if (nullptr == _controller)
	{
		std::cout << "Nenhum InputController foi definido, abortando operação."
				<< std::endl;
		return;
	}

	if (_handlers.empty())
	{
		std::cout << "Nenhum InputHandler foi registrado, abortando operação"
				<< std::endl;
		return;
	}

	if (_entries.empty())
	{
		std::cout << "Nenhum registro foi adicionado, abortando operação"
				<< std::endl;
		return;
	}

	for (unsigned int index = 0; index < _handlers.size(); ++index)
		executeHandler(_handlers[index], index);
}

void InputBuilderTable::executeHandler(InputHandler* handler, unsigned int index)
{
	std::vector<InputBuilderEntry>::iterator entry = _entries.begin();
	while (entry != _entries.end())
	{
		executeEntryForHandler(handler, index, *entry);
		++entry;
	}
}

void InputBuilderTable::executeEntryForHandler(InputHandler* handler, unsigned int index,
		const InputBuilderEntry& entry)
{
	const std::vector<InputAction>& actions = entry.getActions();

	if (actions.size() < index)
	{
		std::cout << "Não foi possível utilizar um index: " << index
				<< " para uma lista de actions de tamanho: " << actions.size()
				<< std::endl;
		return;
	}

	_controller->registerAsListener(actions[index], handler, entry.getCode());
}

}
/* namespace Inputs */
