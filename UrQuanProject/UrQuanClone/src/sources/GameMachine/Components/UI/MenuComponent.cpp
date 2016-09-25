/*
 * MenuComponent.cpp
 *
 *  Created on: 24 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/MenuComponent.h>

#include <iostream>

namespace UI
{

MenuComponent::MenuComponent(GameMachine::InputController& inputController,
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
					Inputs::InputType::INPUT_RELEASE), this);
	_inputController.registerAsListener(
			Inputs::InputAction(sf::Keyboard::Key::Down,
					Inputs::InputType::INPUT_RELEASE), this);
	_inputController.registerAsListener(
			Inputs::InputAction(sf::Keyboard::Key::Return,
					Inputs::InputType::INPUT_RELEASE), this);

	_options[_currentIndex]->hightlight();
}

MenuComponent::~MenuComponent()
{
}

void MenuComponent::handleInput(Inputs::InputAction inputAction)
{
	if (_menuFinished)
	{
		std::cout << "O menu já foi selecionado e não pode ser mais alterado!"
				<< std::endl;
		return;
	}

	if (inputAction.key() == sf::Keyboard::Return)
	{
		_menuFinished = true;
		_selectedOption = _options[_currentIndex];
		_selectedOption->select();
		return;
	}

	unsigned int newIndex = _currentIndex;

	if (inputAction.key() == sf::Keyboard::Up)
		newIndex--;
	else if (inputAction.key() == sf::Keyboard::Down)
		newIndex++;
	else
	{
		std::cout << "Key: " << inputAction.key() << " não foi mapeada!"
				<< std::endl;
		return;
	}

	newIndex = newIndex < 0 ? 0 :
				newIndex > _options.size() - 1 ? _options.size() - 1 : newIndex;

	if (newIndex != _currentIndex)
	{
		updateOptions(_currentIndex, newIndex);
		_currentIndex = newIndex;
	}

	std::cout << "Handling -> Key: " << inputAction.key() << " Action: "
			<< inputAction.inputType() << std::endl;
}

bool MenuComponent::isMenuFinished() const
{
	return _menuFinished;
}

AbstractOption* MenuComponent::getSelected()
{
	return _menuFinished ? _selectedOption : nullptr;
}

void MenuComponent::updateOptions(const unsigned int currentIndex, const unsigned int newIndex)
{
	_options[currentIndex]->unhighlight();
	_options[newIndex]->hightlight();
}

} /* namespace Components */
