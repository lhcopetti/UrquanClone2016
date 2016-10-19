/*
 * ShipFactory.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Factory/ShipFactory.h>

#include <GameMachine/Components/DrawingComponent.h>
#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/ShooterComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>
#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

#include <GameMachine/GameObjects/Armory/ProjectileFactory/BulletFactory.h>
#include <GameMachine/GameObjects/Armory/ProjectileFactory/SquareBulletFactory.h>

namespace Components
{

ShipFactory::ShipFactory()
{
}

ShipFactory::~ShipFactory()
{
}

GameObjects::GameObject* ShipFactory::createNew(PlayerType playerType,
		const GameObjects::ShipType shipType)
{
	DrawingComponent* drawing = nullptr;
	Armory::ProjectileFactory* factory = nullptr;

	const Collision::CCategories projectileCategory =
			playerType == PLAYER_ONE ?
					Collision::CC_PROJECTILE_PLAYERONE :
					Collision::CC_PROJECTILE_PLAYERTWO;

	if (GameObjects::ShipType::SHIP_Soldier74 == shipType)
	{
		drawing = new GameObjects::SpriteDrawing(
				"./resources/playerShip1_orange.png", +90.f);
		factory = new Armory::BulletFactory(projectileCategory);
	}
	else if (GameObjects::ShipType::SHIP_GAIJIN == shipType)
	{
		drawing = new GameObjects::SpriteDrawing(
				"./resources/playerShip2_blue.png", +90.f);
		factory = new Armory::SquareBulletFactory(projectileCategory);
	}

	GameObjects::GameObject* ship = new GameObjects::Ship(drawing);
	ship->setPhysicsComponent(
			new Components::PhysicsComponent(1.0f, 250.f, 0.01f));

	ship->setShooterComponent(new Components::ShooterComponent(factory));

	return ship;
}

} /* namespace GameObjects */
