/*
 * DamageAction.cpp
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/DamageAction.h>

namespace Actions
{

DamageAction::DamageAction(int damage) :
		_damage(damage)
{
}

DamageAction::~DamageAction()
{
}

bool DamageAction::canExecute(GameObjects::GameObject& gameObject)
{
	return _context != nullptr && _context->isAlive();
}

bool DamageAction::execute(GameObjects::GameObject& gameObject)
{
	/* TODO We could add some sort of DefenseComponent so that the
	 * gameObject itself could mitigate some of the raw damage
	 */
	const int oldHealth = _context->getHealth();
	_context->setHealth(oldHealth - _damage);
	return true;
}

} /* namespace Actions */
