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

#include <GameMachine/GameObjects/Actions/SuicideAction.h>
#include <GameMachine/GameObjects/Actions/DamageAction.h>
#include <GameMachine/GameObjects/Actions/Decorations/ActionBundle.h>

namespace Armory
{

BulletFactory::BulletFactory(Collision::CCategories projectileCategory) :
		ProjectileFactory(projectileCategory)
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
	Collision::CCategories myCategory = _projectileCategory;
	Collision::ColliderCategory category;
	category.add(Collision::CC_WALL);
	category.add(Collision::CC_PROJECTILE_PLAYERONE);
	category.add(Collision::CC_PROJECTILE_PLAYERTWO);
	category.add(Collision::CC_SHIP_PLAYERONE);
	category.add(Collision::CC_SHIP_PLAYERTWO);

	Actions::ActionBundle* bundle = new Actions::ActionBundle;
	bundle->add(new Actions::DamageAction(150));
	bundle->add(new Actions::SuicideAction);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(collidingShape, bundle, myCategory, category);
	bullet->setColliderComponent(collider);

	return bullet;
}

} /* namespace Armory */
