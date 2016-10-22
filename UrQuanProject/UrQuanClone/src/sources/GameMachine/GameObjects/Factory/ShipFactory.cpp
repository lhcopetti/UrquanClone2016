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

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>

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

	Collision::CollidingShape* collidingShape =
			new Collision::CircleCollidingShape(
			{ 0.f, 0.f }, 3.f);
	Collision::CCategories myCategory =
			playerType == PLAYER_ONE ?
					Collision::CC_SHIP_PLAYERONE : Collision::CC_SHIP_PLAYERTWO;
	Collision::ColliderCategory category;
	category.add(Collision::CC_WALL);
	category.add(Collision::CC_TURRET);
	category.add(Collision::CC_PROJECTILE_PLAYERONE);
	category.add(Collision::CC_PROJECTILE_PLAYERTWO);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(
			collidingShape, nullptr, myCategory, category);
	ship->setColliderComponent(collider);

	return ship;
}

} /* namespace GameObjects */
