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
	const sf::Vector2f boardSize = sf::Vector2f(width, height);

	_board.setSize(boardSize);
	_board.setFillColor(color);

	_outlineHighlight.setSize(boardSize);
	_outlineSelect.setSize(boardSize);

	_outlineHighlight.setOutlineColor(sf::Color::Yellow);
	_outlineHighlight.setFillColor(sf::Color::Transparent);
	_outlineSelect.setOutlineColor(sf::Color::Green);
	_outlineSelect.setFillColor(sf::Color::Transparent);
	// Centering
	const sf::FloatRect textRect = text.getLocalBounds();

	_text.setOrigin(-(width - (textRect.left + textRect.width)) / 2.f,
			-(height - (textRect.top + textRect.height)) / 2.f + 5.f);
	/* 5.f Valor comprovado empiricamente */
}

ColorBoard::~ColorBoard()
{
}

void ColorBoard::update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject)
{
	const sf::Vector2f pos = gameObject.getPosition();

	_board.setPosition(pos);
	_text.setPosition(pos);
	_outlineHighlight.setPosition(pos);
	_outlineSelect.setPosition(pos);
}

void ColorBoard::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(_board);
	window.draw(_text);
	window.draw(_outlineSelect);
	window.draw(_outlineHighlight);
}

void ColorBoard::sendMessage(const std::string& msg)
{
	if (msg == "HIGHLIGHT")
	{
		_outlineHighlight.setOutlineThickness(-3.f);
		return;
	}
	if (msg == "UNHIGHLIGHT")
	{
		_outlineHighlight.setOutlineThickness(0.f);
		return;
	}

	if (msg == "SELECT")
	{
		_outlineSelect.setOutlineThickness(-5.f);
		return;
	}

	if (msg == "DESELECT")
	{
		_outlineSelect.setOutlineThickness(0.f);
		return;
	}
}

} /* namespace Components */
