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

Weapon::Weapon(ProjectileFactory* factory, sf::Vector2f offset,
		float timeBetweenBullets) :
		_factory(factory), //
		_timeBetweenBullets(timeBetweenBullets), //
		_timeBetweenBulletsCounter(_timeBetweenBullets), //
		_offset(offset) //
{
}

Weapon::~Weapon()
{
	delete _factory;
	_factory = nullptr;
}

bool Weapon::canShoot()
{
	return _timeBetweenBulletsCounter <= 0;
}

const sf::Vector2f& Weapon::getOffset() const
{
	return _offset;
}

Projectile* Weapon::shoot()
{
	_timeBetweenBulletsCounter = _timeBetweenBullets;
	Armory::Projectile* projectile = _factory->createNew();
	return projectile;
}

void Armory::Weapon::update(const sf::Time& deltaTime)
{
	_timeBetweenBulletsCounter -= deltaTime.asSeconds();
	_timeBetweenBulletsCounter = std::max(0.f, _timeBetweenBulletsCounter);
}

} /* namespace Armory */
