/*
 * ShipFactory.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Factory/ShipFactory.h>

#include <GameMachine/Components/CompositeDrawingComponent.h>

#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/ShooterComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>
#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

#include <GameMachine/GameObjects/Armory/ProjectileFactory/BulletFactory.h>
#include <GameMachine/GameObjects/Armory/ProjectileFactory/SquareBulletFactory.h>

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>

#include <GameMachine/Components/UI/HealthStatusDrawing.h>

#include <GameClone/Defs.h>

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
	CompositeDrawingComponent* drawing = new Components::CompositeDrawingComponent;
	Armory::ProjectileFactory* secondaryFactory = nullptr;
	Armory::ProjectileFactory* mainFactory = nullptr;

	drawing->push(getHealthUI(playerType));

	const Collision::CCategories projectileCategory =
			playerType == PLAYER_ONE ?
					Collision::CC_PROJECTILE_PLAYERONE :
					Collision::CC_PROJECTILE_PLAYERTWO;

	if (GameObjects::ShipType::SHIP_Soldier74 == shipType)
	{
		drawing->push(new GameObjects::SpriteDrawing(
				"./resources/playerShip1_orange.png", +90.f));
	}
	else if (GameObjects::ShipType::SHIP_GAIJIN == shipType)
	{
		drawing->push(new GameObjects::SpriteDrawing(
				"./resources/playerShip2_blue.png", +90.f));
	}

	secondaryFactory = new Armory::BulletFactory(projectileCategory);
	mainFactory = new Armory::SquareBulletFactory(projectileCategory);

	GameObjects::GameObject* ship = new GameObjects::Ship(drawing);
	ship->setPhysicsComponent(
			new Components::PhysicsComponent(1.0f, 250.f, 0.01f));

	ship->setShooterComponent(new Components::ShooterComponent(mainFactory, secondaryFactory));

	Collision::CollidingShape* collidingShape =
			new Collision::CircleCollidingShape(
			{ 0.f, 0.f }, 30.f);

	Collision::CCategories myCategory;
	Collision::ColliderCategory category;

	if (playerType == PLAYER_ONE) {
		myCategory = Collision::CC_SHIP_PLAYERONE;
		category.add(Collision::CC_PROJECTILE_PLAYERTWO);
	}
	else if (playerType == PLAYER_TWO)
	{
		myCategory = Collision::CC_SHIP_PLAYERTWO;
		category.add(Collision::CC_PROJECTILE_PLAYERONE);
	}

	category.add(Collision::CC_TURRET);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(
			collidingShape, nullptr, myCategory, category);
	ship->setColliderComponent(collider);

	ship->setMaxHealth(350);
	ship->setHealth(350);

	return ship;
}

Components::DrawingComponent* ShipFactory::getHealthUI(PlayerType playerType)
{
	const float y = 15.f;

	if (playerType == PlayerType::PLAYER_ONE)
		return new UI::HealthStatusDrawing(sf::Vector2f(0.f, y), sf::Color::Red);
	else
		return new UI::HealthStatusDrawing(sf::Vector2f(GAME_SCREEN_HALF_WIDTH, y), sf::Color::Green);
}

} /* namespace GameObjects */
