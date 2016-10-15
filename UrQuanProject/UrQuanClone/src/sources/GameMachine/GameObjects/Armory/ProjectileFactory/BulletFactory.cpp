/*
 * BulletFactory.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/ProjectileFactory/BulletFactory.h>
#include <GameMachine/GameObjects/Armory/Projectile.h>

#include <GameMachine/GameObjects/Armory/Bullet.h>

#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/ShapeComponent.h>

namespace Armory
{

BulletFactory::BulletFactory()
{
}

BulletFactory::~BulletFactory()
{
}

Projectile* BulletFactory::createNew()
{
	sf::Shape* shape = new sf::CircleShape(3);
	shape->setFillColor(sf::Color::White);
	Components::ShapeComponent* shapeComponent = new Components::ShapeComponent(
			shape);
	Bullet* bullet = new Bullet(shapeComponent);
	bullet->setPhysicsComponent(
			new Components::PhysicsComponent(1.0f, 350.f, 0.0f));
	return bullet;
}

} /* namespace Armory */
