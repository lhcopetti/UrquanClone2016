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

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>

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

	Collision::CollidingShape* collidingShape = new Collision::CircleCollidingShape({0.f, 0.f}, 3.f);
	Collision::CCategories myCategory = Collision::CC_PROJECTILE_PLAYERONE;
	Collision::ColliderCategory category(0x02);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(collidingShape, myCategory, category);
	bullet->setColliderComponent(collider);

	return bullet;
}

} /* namespace Armory */
