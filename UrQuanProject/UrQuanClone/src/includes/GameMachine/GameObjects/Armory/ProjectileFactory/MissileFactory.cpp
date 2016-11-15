/*
 * MissileFactory.cpp
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/ProjectileFactory/MissileFactory.h>

#include <GameMachine/GameObjects/Armory/Missile.h>

#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

#include <GameMachine/Components/PhysicsComponent.h>

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>

#include <GameMachine/GameObjects/Actions/SuicideAction.h>
#include <GameMachine/GameObjects/Actions/DamageAction.h>
#include <GameMachine/GameObjects/Actions/Decorations/ActionBundle.h>

namespace Armory
{

MissileFactory::MissileFactory(Collision::CCategories projectileCategory) :
		ProjectileFactory(projectileCategory)
{
	// TODO Auto-generated constructor stub

}

MissileFactory::~MissileFactory()
{
	// TODO Auto-generated destructor stub
}

Projectile* MissileFactory::createNew()
{
	GameObjects::SpriteDrawing* drawing = nullptr;

	if (_projectileCategory == Collision::CC_PROJECTILE_PLAYERONE)
		drawing = new GameObjects::SpriteDrawing("./resources/missile_red.png");
	else
		drawing = new GameObjects::SpriteDrawing("./resources/missile_green.png");


	Missile* missile = new Missile(drawing);
	missile->setPhysicsComponent(
				new Components::PhysicsComponent(1.0f, 350.f, 0.0f));

	Collision::CollidingShape* collidingShape = new Collision::CircleCollidingShape({0.f, 0.f}, 15.f);
	Collision::CCategories myCategory = _projectileCategory;
	Collision::ColliderCategory category;
	category.add(Collision::CC_WALL);
	category.add(Collision::CC_PROJECTILE_PLAYERONE);
	category.add(Collision::CC_PROJECTILE_PLAYERTWO);
	category.add(Collision::CC_SHIP_PLAYERONE);
	category.add(Collision::CC_SHIP_PLAYERTWO);

	Actions::ActionBundle* bundle = new Actions::ActionBundle;
	bundle->add(new Actions::DamageAction(150));
	bundle->add(new Actions::SuicideAction);

	Collision::ColliderComponent* collider = new Collision::ColliderComponent(collidingShape, bundle, myCategory, category);
	missile->setColliderComponent(collider);

	return missile;
}

} /* namespace Armory */
