/*
 * Weapon.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>

namespace Armory
{
class Projectile;
class ProjectileFactory;

class Weapon : public UpdatableFromTime
{
public:
	Weapon(ProjectileFactory* factory, float timeBetweenBullets = 0.5f);
	virtual ~Weapon();

	virtual void update(const sf::Time& deltaTime);

	bool canShoot();
	Projectile* shoot();

protected:

private:
	ProjectileFactory* _factory;

	const float _timeBetweenBullets;
	float _timeBetweenBulletsCounter;

};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_WEAPON_H_ */
