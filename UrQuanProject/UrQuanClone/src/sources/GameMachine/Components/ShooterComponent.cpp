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

ShooterComponent::ShooterComponent(Armory::ProjectileFactory* factory) :
		Component(SHOOTER_COMPONENT),
		_weapon(factory)
{
}

ShooterComponent::~ShooterComponent()
{
}

void ShooterComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_weapon.update(deltaTime);
}

Armory::Weapon& ShooterComponent::getWeapon()
{
	return _weapon;
}

} /* namespace Components */
