/*
 * ShootAction.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/ShootAction.h>
#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>

#include <GameMachine/Components/ShooterComponent.h>
#include <GameMachine/GameObjects/Armory/Weapon.h>
#include <GameMachine/GameObjects/Armory/Projectile.h>

namespace Actions
{

ShootAction::ShootAction()
{
}

ShootAction::~ShootAction()
{
}

bool ShootAction::canExecute(GameObjects::GameObject& gameObject)
{
	Components::ShooterComponent* shooter = gameObject.getShooterComponent();

	if (nullptr == shooter)
		return false;

	return shooter->getWeapon().canShoot();
}

bool ShootAction::execute(GameObjects::GameObject& gameObject)
{
	Armory::Weapon& weapon = gameObject.getShooterComponent()->getWeapon();

	Armory::Projectile* projectile = weapon.shoot();

	if (nullptr == projectile)
		return false;

	projectile->setPosition(gameObject.getPosition());
	projectile->pushAction(
			new Actions::SetVelocityAction(sf::Vector2f(300.f, 0.f)));

	gameObject.reproduce(projectile);
	return true;
}

} /* namespace Actions */
