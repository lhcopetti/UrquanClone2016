/*
 * Weapon.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/Weapon.h>
#include <GameMachine/GameObjects/Armory/ProjectileFactory/ProjectileFactory.h>

#include <algorithm>

namespace Armory
{

Weapon::Weapon(ProjectileFactory* factory, float timeBetweenBullets) :
		_factory(factory), //
		_timeBetweenBullets(timeBetweenBullets), //
		_timeBetweenBulletsCounter(_timeBetweenBullets) //
{
}

Weapon::~Weapon()
{
}

bool Weapon::canShoot()
{
	return _timeBetweenBulletsCounter <= 0;
}

Projectile* Weapon::shoot()
{
	_timeBetweenBulletsCounter = _timeBetweenBullets;
	return _factory->createNew();
}

void Armory::Weapon::update(const sf::Time& deltaTime)
{
	_timeBetweenBulletsCounter -= deltaTime.asSeconds();
	_timeBetweenBulletsCounter = std::max(0.f, _timeBetweenBulletsCounter);
}

} /* namespace Armory */
