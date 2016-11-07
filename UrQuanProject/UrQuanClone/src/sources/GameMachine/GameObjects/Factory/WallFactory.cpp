/*
 * WallFactory.cpp
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Factory/WallFactory.h>
#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/Components/RectDrawingComponent.h>

#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/Components/Collision/ColliderCategory.h>
#include <GameMachine/Components/Collision/Shape/RectangleCollidingShape.h>

#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>

namespace Factory
{

WallFactory::WallFactory(sf::Color color) :
		_color(color)
{
}

WallFactory::~WallFactory()
{
	// TODO Auto-generated destructor stub
}

GameObjects::GameObject* WallFactory::createNew(sf::Vector2f position,
		sf::Vector2f size)
{
	Components::DrawingComponent* drawing =
			new Components::RectDrawingComponent(_color, position, size);

	Collision::CollidingShape* collShape =
			new Collision::RectangleCollidingShape(position, size);
	Collision::ColliderCategory category;
	category.add(Collision::CC_WALL);
	category.add(Collision::CC_PROJECTILE_PLAYERONE);
	category.add(Collision::CC_PROJECTILE_PLAYERTWO);
	Collision::ColliderComponent* collider = new Collision::ColliderComponent(
			collShape, nullptr, Collision::CC_WALL, category);

	GameObjects::GameObject* wall = new GameObjects::GameObject(drawing,
			position);
	wall->setColliderComponent(collider);
	return wall;
}

} /* namespace Geometry */
