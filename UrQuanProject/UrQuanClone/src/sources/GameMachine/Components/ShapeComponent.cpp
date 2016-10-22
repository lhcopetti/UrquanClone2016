/*
 * ShapeComponent.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/ShapeComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

ShapeComponent::ShapeComponent(sf::Shape* shape) :
		_shape(shape)
{
	sf::FloatRect rect = _shape->getLocalBounds();
	sf::Vector2f newOrigin(rect.width / 2, rect.height / 2);
	shape->setOrigin(newOrigin);
}

ShapeComponent::~ShapeComponent()
{
	delete _shape;
	_shape = nullptr;
}

void ShapeComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_shape->setPosition(gameObject.getPosition());
	_shape->setRotation(gameObject.getOrientation());
}

void ShapeComponent::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(*_shape);
}

} /* namespace Components */
