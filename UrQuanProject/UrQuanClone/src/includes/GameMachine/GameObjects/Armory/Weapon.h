/*
 * Weapon.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <SFML/System.hpp>

namespace Armory
{
class Projectile;
class ProjectileFactory;

class Weapon: public UpdatableFromTime
{
public:
	Weapon(ProjectileFactory* factory,
			sf::Vector2f offset = sf::Vector2f(39.f, 0.f),
			float timeBetweenBullets = 0.5f);
	virtual ~Weapon();


	const sf::Vector2f& getOffset() const;

	virtual void update(const sf::Time& deltaTime);

	bool canShoot();
	Projectile* shoot();

protected:

private:
	ProjectileFactory* _factory;

	const float _timeBetweenBullets;
	float _timeBetweenBulletsCounter;

	sf::Vector2f _offset;

};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_ */
