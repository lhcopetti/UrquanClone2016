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
#include <GameMachine/Components/BlueDotComponent.h>

namespace Armory
{

BulletFactory::BulletFactory()
{
	// TODO Auto-generated constructor stub

}

BulletFactory::~BulletFactory()
{
	// TODO Auto-generated destructor stub
}

Projectile* BulletFactory::createNew()
{
	Bullet* bullet = new Bullet(new Components::BlueDotComponent);
	bullet->setPhysicsComponent(new Components::PhysicsComponent(1.0f, 350.f, 0.0f));
	return bullet;
}

} /* namespace Armory */
