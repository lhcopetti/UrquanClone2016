/*
 * ColorBoard.cpp
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/UI/ColorBoard.h>
#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

ColorBoard::ColorBoard(sf::Text text, sf::Color color, int height, int width) :
		_text(text)
{
	_board.setSize(sf::Vector2f(width, height));
	_board.setFillColor(color);

	// Centering
	const sf::FloatRect textRect = text.getLocalBounds();

	_text.setOrigin(-(width - (textRect.left + textRect.width)) / 2.f,
			-(height - (textRect.top + textRect.height)) / 2.f + 5.f);
	/* 5.f Valor comprovado empiricamente */
}

ColorBoard::~ColorBoard()
{
}

void ColorBoard::update(const GameObjects::GameObject& gameObject)
{
	const sf::Vector2f pos = gameObject.getPosition();

	_board.setPosition(pos);
	_text.setPosition(pos);
}

void ColorBoard::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(_board);
	window.draw(_text);
}

} /* namespace Components */
