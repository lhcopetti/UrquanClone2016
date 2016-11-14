/*
 * SquareBulletFactory.cpp
 *
 *  Created on: 18 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/ProjectileFactory/SquareBulletFactory.h>

#include <GameMachine/GameObjects/Armory/Projectile.h>

#include <GameMachine/GameObjects/Armory/Bullet.h>

#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/ShapeComponent.h>

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/RectangleCollidingShape.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>

#include <GameMachine/GameObjects/Actions/SuicideAction.h>

namespace Armory
{

SquareBulletFactory::SquareBulletFactory(
		Collision::CCategories projectileCategory) :
		ProjectileFactory(projectileCategory)
{
	// TODO Auto-generated constructor stub

}

SquareBulletFactory::~SquareBulletFactory()
{
	// TODO Auto-generated destructor stub
}

Projectile* SquareBulletFactory::createNew()
{
	sf::Shape* shape = new sf::RectangleShape(
	{ 5.f, 5.f });
	shape->setFillColor(sf::Color::White);
	Components::ShapeComponent* shapeComponent = new Components::ShapeComponent(
			shape);
	Bullet* bullet = new Bullet(shapeComponent);
	bullet->setPhysicsComponent(
			new Components::PhysicsComponent(1.0f, 350.f, 0.0f));

	Collision::CollidingShape* collidingShape =
			new Collision::RectangleCollidingShape(
			{ 0.f, 0.f },
			{ 5.f, 5.f });
	Collision::CCategories myCategory = _projectileCategory;
	Collision::ColliderCategory category;
	category.add(Collision::CC_WALL);
	category.add(Collision::CC_PROJECTILE_PLAYERONE);
	category.add(Collision::CC_PROJECTILE_PLAYERTWO);
	category.add(Collision::CC_SHIP_PLAYERONE);
	category.add(Collision::CC_SHIP_PLAYERTWO);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(
			collidingShape, new Actions::SuicideAction, myCategory, category);
	bullet->setColliderComponent(collider);

	return bullet;
}

} /* namespace Armory */
