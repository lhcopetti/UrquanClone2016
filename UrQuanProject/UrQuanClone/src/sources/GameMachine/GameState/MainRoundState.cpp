/*
 * MainRoundState.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/MainRoundState.h>

#include <GameMachine/GameState/WinnerState.h>

#include <GameMachine/GameObjects/Factory/BlueCircle.h>

#include <GameMachine/GameObjects/Factory/ShipFactory.h>
#include <GameMachine/GameObjects/Factory/WallFactory.h>
#include <GameMachine/GameObjects/Factory/TurretFactory.h>

#include <GameClone/Defs.h>

#include <GameMachine/GameObjects/Blocks/Wall.h>
#include <GameMachine/GameObjects/Ship/Ship.h>
#include <GameMachine/GameObjects/Ship/ShipInput.h>

#include <GameMachine/InputControl/InputBuilder.h>

#include <GameMachine/StackControl/PopStackCommand.h>
#include <GameMachine/StackControl/PushStackCommand.h>

#include <iostream>

namespace GameState
{

enum MAINROUNDSTATE_INPUT
{
	EXIT_GAME
};

MainRoundState::MainRoundState(GameMachine::GameStateController& controller) :
		GameState(controller), _shipPlayerOne(nullptr), _shipPlayerTwo(nullptr)
{
	Components::ShipFactory shipFactory;
	_shipPlayerOne = shipFactory.createNew(PLAYER_ONE,
			GameObjects::ShipType::SHIP_Soldier74);
	_shipTypeOne = GameObjects::SHIP_Soldier74;

	_shipPlayerTwo = shipFactory.createNew(PLAYER_TWO,
			GameObjects::ShipType::SHIP_GAIJIN);
	_shipTypeTwo = GameObjects::SHIP_GAIJIN;

	sf::Vector2f center = GAME_SCREEN_CENTER_VECTOR;
	sf::Vector2f halfCenter(center.x / 2, center.y);
	_shipPlayerOne->setPosition(halfCenter);
	_shipPlayerTwo->setPosition(sf::Vector2f(halfCenter.x * 3, halfCenter.y));

	_goCollection.push(_shipPlayerOne);
	_goCollection.push(_shipPlayerTwo);

	using namespace Inputs;
	using namespace sf;
	using namespace GameObjects;

//	InputBuilder builder;
//	builder.bind(
//	{ Keyboard::W, INPUT_PRESSING }).andAlso(
//	{ Keyboard::Numpad8, INPUT_PRESSING }).to(ShipInput::SHIP_THRUST).bind(
//	{ Keyboard::A, INPUT_PRESSING }).andAlso(
//	{ Keyboard::Numpad4, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_LEFT).bind(
//	{ Keyboard::D, INPUT_PRESSING }).andAlso(
//	{ Keyboard::Numpad6, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_RIGHT).bind(
//	{ Keyboard::Space, INPUT_PRESS }).andAlso(
//	{ Keyboard::Numpad0, INPUT_PRESS }).to(ShipInput::SHIP_SHOOT).applyFor(
//			shipPlayer1).andAlso(shipPlayer2).on(_inputController).run();

	InputBuilder builder;
	builder.bind(
	{ Keyboard::W, INPUT_PRESSING }).andAlso(
	{ Keyboard::I, INPUT_PRESSING }).to(ShipInput::SHIP_THRUST).bind(
	{ Keyboard::A, INPUT_PRESSING }).andAlso(
	{ Keyboard::J, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_LEFT).bind(
	{ Keyboard::D, INPUT_PRESSING }).andAlso(
	{ Keyboard::L, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_RIGHT).bind(
	{ Keyboard::Space, INPUT_PRESS }).andAlso(
	{ Keyboard::M, INPUT_PRESS }).to(ShipInput::SHIP_SECONDARY_SHOOT).bind(
	{ Keyboard::V, INPUT_PRESS }).andAlso(
	{ Keyboard::N, INPUT_PRESS }).to(ShipInput::SHIP_MAIN_SHOOT).applyFor(
			_shipPlayerOne).andAlso(_shipPlayerTwo).on(_inputController).run();

	InputBuilder exitShortcut;

	exitShortcut.bind(
	{ Keyboard::Escape, INPUT_PRESS }).to(EXIT_GAME).applyFor(this).on(
			_inputController).run();

	Factory::WallFactory wallFactory(sf::Color::Cyan);
	GameObjects::GameObject* wall = wallFactory.createNew(
			sf::Vector2f(0.f, 0.f), sf::Vector2f(5.f, 1376.f));
	GameObjects::GameObject* wall2 = wallFactory.createNew(
			sf::Vector2f(GAME_SCREEN_HALF_WIDTH, GAME_SCREEN_HALF_HEIGHT),
			sf::Vector2f(5.f, GAME_SCREEN_HALF_HEIGHT / 2.F));
	_goCollection.push(wall);
	_goCollection.push(wall2);

//	Factory::TurretFactory turretFactory;
//	_goCollection.push(turretFactory.createNew(
//	{ GAME_SCREEN_HALF_WIDTH, 50.f }));
}

MainRoundState::~MainRoundState()
{
}

void MainRoundState::onEnter()
{
	std::cout << "Entering MainRoundState" << std::endl;
//	_goCollection.push(Components::BlueCircle::newBlueCircle());
}

void MainRoundState::onExit()
{
	std::cout << "Leaving MainRoundState" << std::endl;
}

void MainRoundState::doUpdate(const sf::Time& deltaTime)
{
	if (_shipPlayerOne->isAlive() && _shipPlayerTwo->isAlive())
		return;

	if (!_shipPlayerOne->isAlive())
		transition(_shipTypeTwo, _shipTypeOne);
	else
		transition(_shipTypeOne, _shipTypeTwo);
}

void MainRoundState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Blue);
}

void MainRoundState::doDraw(sf::RenderWindow& window)
{
}

void MainRoundState::handleInput(int data)
{
	if (data != EXIT_GAME)
	{
		std::cout << "Não há tratamento para eventos do tipo: " << data
				<< std::endl;
		return;
	}

	_controller.addCommand(new GameMachine::PopStackCommand);
}

void MainRoundState::transition(GameObjects::ShipType winner,
		GameObjects::ShipType looser)
{
	_controller.addCommand(new GameMachine::PopStackCommand);
	_controller.addCommand(
			new GameMachine::PushStackCommand(
					new WinnerState(_controller, winner, looser)));
}

} /* namespace GameState */
