/*
 * MenuComponent.cpp
 *
 *  Created on: 24 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/MenuComponent.h>

#include <iostream>
#include <algorithm>

namespace UI
{

enum INPUT_MENU_COMMANDS
{
	UP_COMMAND, DOWN_COMMAND, ENTER_COMMAND
};

MenuComponent::MenuComponent(Inputs::InputController& inputController,
		std::vector<AbstractOption*> options, sf::Vector2f pos) :
		_inputController(inputController), _options(options), _pos(pos), _currentIndex(
				0), _menuFinished(false), _selectedOption(nullptr)
{

	int padding = 35.f; /* Valor comprovado empiricamente */

	int menuHeight = options[0]->getSize().y * options.size()
			+ (options.size() - 1) * padding;
	int menuWidth = options[0]->getSize().x;

	sf::Vector2f menuPos(pos.x - menuWidth / 2.f, pos.y - menuHeight / 2.f);

	for (unsigned int i = 0; i < options.size(); i++)
	{
		sf::Vector2f optionSize = options[i]->getSize();
		options[i]->setPosition(
				sf::Vector2f(menuPos.x,
						menuPos.y + (optionSize.y + padding) * i));
	}

	_inputController.registerAsListener(
			Inputs::InputAction(sf::Keyboard::Key::Up,
					Inputs::InputType::INPUT_RELEASE), this, UP_COMMAND);
	_inputController.registerAsListener(
			Inputs::InputAction(sf::Keyboard::Key::Down,
					Inputs::InputType::INPUT_RELEASE), this, DOWN_COMMAND);
	_inputController.registerAsListener(
			Inputs::InputAction(sf::Keyboard::Key::Return,
					Inputs::InputType::INPUT_RELEASE), this, ENTER_COMMAND);

	_options[_currentIndex]->hightlight();
}

MenuComponent::~MenuComponent()
{
}

void MenuComponent::handleInput(int data)
{
	if (_menuFinished)
	{
		std::cout << "O menu já foi selecionado e não pode ser mais alterado!"
				<< std::endl;
		return;
	}

	if (data == ENTER_COMMAND)
	{
		_menuFinished = true;
		_selectedOption = _options[_currentIndex];
		_selectedOption->select();
		return;
	}

	int newIndex = _currentIndex;

	if (data == UP_COMMAND)
		newIndex--;
	else if (DOWN_COMMAND)
		newIndex++;
	else
	{
		std::cout << "Evento de valor: " << data << " não foi mapeado!"
				<< std::endl;
		return;
	}

	newIndex = std::min((signed)_options.size() - 1, std::max(0, newIndex));

	if (newIndex != _currentIndex)
	{
		updateOptions(_currentIndex, newIndex);
		_currentIndex = newIndex;
	}

	std::cout << "Menu Component handling signal: " << data << std::endl;
}

bool MenuComponent::isMenuFinished() const
{
	return _menuFinished;
}

AbstractOption* MenuComponent::getSelected()
{
	return _menuFinished ? _selectedOption : nullptr;
}

void MenuComponent::reset()
{
	_menuFinished = false;
	_selectedOption = nullptr;

	for (auto it = _options.begin(); it != _options.end(); ++it)
	{
		(*it)->unhighlight();
		(*it)->deselect();
	}

	_options[_currentIndex]->hightlight();
}

void MenuComponent::updateOptions(const unsigned int currentIndex,
		const unsigned int newIndex)
{
	_options[currentIndex]->unhighlight();
	_options[newIndex]->hightlight();
}

} /* namespace Components */
