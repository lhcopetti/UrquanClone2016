/*
 * MainMenuState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/MainMenuState.h>

#include "GameMachine/GameObjects/Factory/BlueCircle.h"
#include "GameMachine/Components/UI/ColorBoard.h"

namespace GameState
{

MainMenuState::MainMenuState(const sf::Font& font) :
		_defaultFont(font)
{
}

MainMenuState::~MainMenuState()
{
	// TODO Auto-generated destructor stub
}

void MainMenuState::update(const sf::Time& deltaTime)
{
	_goCollection.update(deltaTime);
}

void MainMenuState::draw(sf::RenderWindow& window)
{

	window.clear(sf::Color::Red);

	_goCollection.draw(window);
}

void MainMenuState::onEnter()
{
	_goCollection.push(Components::BlueCircle::newBlueCircle());

	sf::Text text;
	text.setFont(getDefaultFont());
	text.setFillColor(sf::Color::Black);
	text.setString("Start Game");
	Components::DrawingComponent* drawing = new Components::ColorBoard(
			text);

	GameObjects::GameObject* board = new GameObjects::GameObject(drawing);
	board->setPosition(sf::Vector2f(100.f, 100.f));

	_goCollection.push(board);
}

void MainMenuState::onExit()
{
}

const sf::Font& MainMenuState::getDefaultFont() const
{
	return _defaultFont;
}
} /* namespace GameState */

