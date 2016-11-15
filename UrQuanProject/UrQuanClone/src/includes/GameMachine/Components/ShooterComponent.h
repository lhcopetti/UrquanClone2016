/*
 * ShooterComponent.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_SHOOTERCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_SHOOTERCOMPONENT_H_

#include <GameMachine/Components/Component.h>
#include <GameMachine/GameObjects/Armory/Weapon.h>
namespace Armory
{
class Bullet;
class ProjectileFactory;
}

namespace Components
{

class ShooterComponent: public Component
{
public:
	ShooterComponent(Armory::ProjectileFactory* main, Armory::ProjectileFactory* secondary);
	virtual ~ShooterComponent();

	virtual void update(const sf::Time& deltaTime,
			GameObjects::GameObject& gameObject);

	Armory::Weapon& getSecondaryWeapon();
	Armory::Weapon& getMainWeapon();

private:
	Armory::Weapon _mainWeapon;
	Armory::Weapon _secondaryWeapon;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_SHOOTERCOMPONENT_H_ */
