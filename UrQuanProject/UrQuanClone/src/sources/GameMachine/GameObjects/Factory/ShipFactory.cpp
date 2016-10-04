/*
 * ShipFactory.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Factory/ShipFactory.h>

#include <GameMachine/Components/DrawingComponent.h>
#include <GameMachine/GameObjects/Ship/ShipDrawing.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

ShipFactory::ShipFactory()
{
	// TODO Auto-generated constructor stub

}

ShipFactory::~ShipFactory()
{
	// TODO Auto-generated destructor stub
}

GameObjects::GameObject* ShipFactory::createNew(const GameObjects::ShipType shipType)
{
	DrawingComponent* drawing = nullptr;

	if (GameObjects::ShipType::SHIP_Soldier74 == shipType)
		drawing = new GameObjects::ShipDrawing("./resources/playerShip1_orange.png");
	else if (GameObjects::ShipType::SHIP_GAIJIN == shipType)
		drawing = new GameObjects::ShipDrawing("./resources/playerShip2_blue.png");

	GameObjects::GameObject* ship = new GameObjects::Ship(drawing);
	return ship;
}

} /* namespace GameObjects */
