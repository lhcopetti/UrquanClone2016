/*
 * MainRoundState.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/MainRoundState.h>
#include <GameMachine/GameObjects/Factory/BlueCircle.h>

#include <GameMachine/GameObjects/Factory/ShipFactory.h>
#include <GameMachine/GameObjects/Factory/WallFactory.h>
#include <GameMachine/GameObjects/Factory/TurretFactory.h>

#include <GameClone/Defs.h>

#include <GameMachine/GameObjects/Blocks/Wall.h>
#include <GameMachine/GameObjects/Ship/Ship.h>
#include <GameMachine/GameObjects/Ship/ShipInput.h>

#include <GameMachine/InputControl/InputBuilder.h>

#include <iostream>

namespace GameState
{

MainRoundState::MainRoundState(GameMachine::GameStateController& controller) :
		GameState(controller)
{
	Components::ShipFactory shipFactory;
	GameObjects::GameObject* shipPlayer1 = shipFactory.createNew(PLAYER_ONE,
			GameObjects::ShipType::SHIP_Soldier74);

	GameObjects::GameObject* shipPlayer2 = shipFactory.createNew(PLAYER_TWO,
			GameObjects::ShipType::SHIP_GAIJIN);

	sf::Vector2f center = GAME_SCREEN_CENTER_VECTOR;
	sf::Vector2f halfCenter(center.x / 2, center.y);
	shipPlayer1->setPosition(halfCenter);
	shipPlayer2->setPosition(sf::Vector2f(halfCenter.x * 3, halfCenter.y));

	_goCollection.push(shipPlayer1);
	_goCollection.push(shipPlayer2);

	using namespace Inputs;
	using namespace sf;
	using namespace GameObjects;

	InputBuilder builder;
	builder.bind(
	{ Keyboard::W, INPUT_PRESSING }).andAlso(
	{ Keyboard::Numpad8, INPUT_PRESSING }).to(ShipInput::SHIP_THRUST).bind(
	{ Keyboard::A, INPUT_PRESSING }).andAlso(
	{ Keyboard::Numpad4, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_LEFT).bind(
	{ Keyboard::D, INPUT_PRESSING }).andAlso(
	{ Keyboard::Numpad6, INPUT_PRESSING }).to(ShipInput::SHIP_ROTATE_RIGHT).bind(
	{ Keyboard::Space, INPUT_PRESS }).andAlso(
	{ Keyboard::Numpad0, INPUT_PRESS }).to(ShipInput::SHIP_SHOOT).applyFor(
			shipPlayer1).andAlso(shipPlayer2).on(_inputController).run();

	Factory::WallFactory wallFactory(sf::Color::Cyan);
	GameObjects::GameObject* wall = wallFactory.createNew(
			sf::Vector2f(0.f, 0.f), sf::Vector2f(5.f, 1376.f));
	GameObjects::GameObject* wall2 = wallFactory.createNew(
			sf::Vector2f(GAME_SCREEN_HALF_WIDTH, GAME_SCREEN_HALF_HEIGHT),
			sf::Vector2f(5.f, GAME_SCREEN_HALF_HEIGHT / 2.F));
	_goCollection.push(wall);
	_goCollection.push(wall2);

	Factory::TurretFactory turretFactory;
	_goCollection.push(turretFactory.createNew(
	{ GAME_SCREEN_HALF_WIDTH, 50.f }));
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

}

void MainRoundState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Blue);
}

void MainRoundState::doDraw(sf::RenderWindow& window)
{
}

} /* namespace GameState */
