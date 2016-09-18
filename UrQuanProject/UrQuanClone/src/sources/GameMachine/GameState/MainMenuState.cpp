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

sf::Text MainMenuState::getDefaultSfText(const std::string& text)
{
	sf::Text sfText;
	sfText.setFont(getDefaultFont());
	sfText.setFillColor(sf::Color::Black);
	sfText.setString(text);
	return sfText;
}

void MainMenuState::onEnter()
{
	_goCollection.push(Components::BlueCircle::newBlueCircle());

	sf::Text text;
	text.setFont(getDefaultFont());
	text.setFillColor(sf::Color::Black);
	text.setString("Start Game");
	GameObjects::GameObject* startMenu = new GameObjects::GameObject(
			new Components::ColorBoard(getDefaultSfText("Start Game")));
	startMenu->setPosition(sf::Vector2f(100.f, 100.f));
	_goCollection.push(startMenu);

	GameObjects::GameObject* creditsMenu = new GameObjects::GameObject(
			new Components::ColorBoard(getDefaultSfText("Credits")));
	creditsMenu->setPosition(sf::Vector2f(100.f, 200.f));
	_goCollection.push(creditsMenu);

	GameObjects::GameObject* quitMenu = new GameObjects::GameObject(
			new Components::ColorBoard(getDefaultSfText("Quit Game")));
	quitMenu->setPosition(sf::Vector2f(100.f, 300.f));
	_goCollection.push(quitMenu);
}

void MainMenuState::onExit()
{
}

const sf::Font& MainMenuState::getDefaultFont() const
{
	return _defaultFont;
}
} /* namespace GameState */

