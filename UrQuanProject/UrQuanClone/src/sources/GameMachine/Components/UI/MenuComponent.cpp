/*
 * MenuComponent.cpp
 *
 *  Created on: 24 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/MenuComponent.h>

namespace UI
{

MenuComponent::MenuComponent(GameMachine::InputController& inputController,
		std::vector<AbstractOption*> options, sf::Vector2f pos) :
		_inputController(inputController), _options(options), _pos(pos)
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

	_options[0]->select();
	_options[1]->hightlight();
}

MenuComponent::~MenuComponent()
{
}

void MenuComponent::handleInput(Inputs::InputAction inputAction)
{
}

} /* namespace Components */
