/*
 * MainMenuState.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameState/MainMenuState.h>
#include <GameMachine/GameState/MainRoundState.h>

#include <GameMachine/GameObjects/Inputs/InputAction.h>

#include "GameMachine/GameObjects/Factory/BlueCircle.h"
#include "GameMachine/Components/UI/ColorBoard.h"

#include <GameMachine/Components/UI/Options/AbstractOptionFactory.h>
#include <GameMachine/Components/UI/Options/AbstractOption.h>

#include <GameMachine/StackControl/PopStackCommand.h>
#include <GameMachine/StackControl/PushStackCommand.h>

#include <GameClone/Defs.h>

#include <iostream>



namespace GameState
{

MainMenuState::MainMenuState(GameMachine::GameStateController& controller, const sf::Font& font) :
		GameState(controller),
		_defaultFont(font),
		_startMenu(nullptr),
		_testCounter(0),
		_registered(false),
		_optionStart(nullptr),
		_optionCredits(nullptr),
		_optionQuitGame(nullptr),
		_menuComponent(nullptr)

{
	Inputs::InputAction inpA(sf::Keyboard::W, Inputs::InputType::INPUT_DOUBLE_TAP);
	_inputController.unregisterAsListener(inpA, this);

	_inputController.registerAsListener(inpA, this);
	_inputController.registerAsListener(inpA, this);

	_inputController.unregisterAsListener(inpA, this);

}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::doUpdate(const sf::Time& deltaTime)
{
	_testCounter += deltaTime.asMilliseconds();

	Inputs::InputAction inpA(sf::Keyboard::W, Inputs::InputType::INPUT_DOUBLE_TAP);
	Inputs::InputAction inpB(sf::Keyboard::F, Inputs::InputType::INPUT_RELEASE);

	if (_testCounter > 15 * 1000) // 20 Seconds
	{
		if (!_registered)
		{
			_inputController.registerAsListener(inpA, this);
			_inputController.registerAsListener(inpB, this);
		}
		else
		{
			_inputController.unregisterAsListener(inpA, this);
			_inputController.unregisterAsListener(inpB, this);
		}
		_testCounter = 0;
		_registered ^= true;
	}

	if (!_menuComponent->isMenuFinished())
		return;

	UI::AbstractOption* selectedOption = _menuComponent->getSelected();

	if (selectedOption == _optionStart)
	{
		_controller.addCommand(new GameMachine::PopStackCommand());
		_controller.addCommand(new GameMachine::PushStackCommand(new MainRoundState(_controller)));
	}
	else
		std::cout << "Ainda não foi implementado outros tipos de opções!" << std::endl;
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
	std::cout << "Entering MainMenuState" << std::endl;

	UI::AbstractOptionFactory factory(sf::Vector2f(200.f, 100.f), getDefaultSfText(""));
	_optionStart 	= factory.newOption("Start Game!");
	_optionCredits 	= factory.newOption("Credits");
	_optionQuitGame = factory.newOption("Quit Game!");

	_goCollection.push(_optionStart);
	_goCollection.push(_optionCredits);
	_goCollection.push(_optionQuitGame);

	std::vector<UI::AbstractOption*> _options = {_optionStart, _optionCredits, _optionQuitGame };
	_menuComponent = new UI::MenuComponent(_inputController, _options, GAME_SCREEN_CENTER_VECTOR);


//	_goCollection.push(Components::BlueCircle::newBlueCircle());
//
//	sf::Text text;
//	text.setFont(getDefaultFont());
//	text.setFillColor(sf::Color::Black);
//	text.setString("Start Game");
//	_startMenu = new GameObjects::GameObject(
//			new Components::ColorBoard(getDefaultSfText("Start Game")));
//	_startMenu->setPosition(sf::Vector2f(100.f, 100.f));
//	_goCollection.push(_startMenu);
//
//	GameObjects::GameObject* creditsMenu = new GameObjects::GameObject(
//			new Components::ColorBoard(getDefaultSfText("Credits")));
//	creditsMenu->setPosition(sf::Vector2f(100.f, 200.f));
//	_goCollection.push(creditsMenu);
//
//	GameObjects::GameObject* quitMenu = new GameObjects::GameObject(
//			new Components::ColorBoard(getDefaultSfText("Quit Game")));
//	quitMenu->setPosition(sf::Vector2f(100.f, 300.f));
//	_goCollection.push(quitMenu);
}

void MainMenuState::onExit()
{
	std::cout << "Leaving MainMenuState! " << std::endl;
}

const sf::Font& MainMenuState::getDefaultFont() const
{
	return _defaultFont;
}

void MainMenuState::handleInput(Inputs::InputAction inputAction)
{
	std::cout << "Handling event: Key: " << inputAction.key() << " Type: " << Inputs::stringInputType(inputAction.inputType()) << std::endl;
}

} /* namespace GameState */

