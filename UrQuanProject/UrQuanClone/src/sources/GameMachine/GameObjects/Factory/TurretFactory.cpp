/*
 * TurretFactory.cpp
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Factory/TurretFactory.h>

#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/GameObjects/Armory/ProjectileFactory/BulletFactory.h>

#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

#include <GameMachine/Components/ShapeComponent.h>
#include <GameMachine/Components/CompositeDrawingComponent.h>

#include <GameMachine/Components/ShooterComponent.h>

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/ShapeCollider.h>

#include <GameMachine/GameObjects/Actions/AimAction.h>

namespace Factory
{

TurretFactory::TurretFactory()
{
	// TODO Auto-generated constructor stub

}

TurretFactory::~TurretFactory()
{
	// TODO Auto-generated destructor stub
}

GameObjects::GameObject* TurretFactory::createNew(sf::Vector2f position)
{
	Components::DrawingComponent* drawing = new GameObjects::SpriteDrawing("./resources/tank_turret.png", +90.f);
	sf::CircleShape* circle = new sf::CircleShape(250.f);
	circle->setFillColor(sf::Color::Transparent);
	circle->setOutlineThickness(-2.f);
	circle->setOutlineColor(sf::Color::White);

	Components::DrawingComponent* circleRadius = new Components::ShapeComponent(circle);

	Components::CompositeDrawingComponent* composite = new Components::CompositeDrawingComponent;
	composite->push(drawing);
	composite->push(circleRadius);

	GameObjects::GameObject* turret = new GameObjects::GameObject(composite, position);

	Armory::ProjectileFactory* factory = new Armory::BulletFactory(Collision::CC_TURRET);

	turret->setShooterComponent(new Components::ShooterComponent(factory));

	Collision::CollidingShape* collidingShape = new Collision::CircleCollidingShape({0.f, 0.f}, 250.f);
	Collision::CCategories myCategory = Collision::CC_TURRET;
	Collision::ColliderCategory category;
	category.add(Collision::CC_SHIP_PLAYERONE);
	category.add(Collision::CC_SHIP_PLAYERTWO);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(collidingShape, new Actions::AimAction, myCategory, category);
	turret->setColliderComponent(collider);

	return turret;
}

} /* namespace Factory */
