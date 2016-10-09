/*
 * ShipFactory.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Factory/ShipFactory.h>

#include <GameMachine/Components/DrawingComponent.h>
#include <GameMachine/Components/PhysicsComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>
#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

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
		drawing = new GameObjects::SpriteDrawing("./resources/playerShip1_orange.png", +90.f);
	else if (GameObjects::ShipType::SHIP_GAIJIN == shipType)
		drawing = new GameObjects::SpriteDrawing("./resources/playerShip2_blue.png", +90.f);

	GameObjects::GameObject* ship = new GameObjects::Ship(drawing);
	ship->setPhysicsComponent(new Components::PhysicsComponent);
	return ship;
}

} /* namespace GameObjects */
