/*
 * ShooterComponent.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/ShooterComponent.h>
#include <GameMachine/GameObjects/Armory/Weapon.h>

namespace Components
{

ShooterComponent::ShooterComponent(Armory::ProjectileFactory* mainFactory, Armory::ProjectileFactory* secondaryFactory) :
		_mainWeapon(mainFactory),
		_secondaryWeapon(secondaryFactory)
{
}

ShooterComponent::~ShooterComponent()
{
}

void ShooterComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_mainWeapon.update(deltaTime);
	_secondaryWeapon.update(deltaTime);
}

Armory::Weapon& ShooterComponent::getSecondaryWeapon()
{
	return _secondaryWeapon;
}

Armory::Weapon& ShooterComponent::getMainWeapon()
{
	return _mainWeapon;
}

} /* namespace Components */
