/*
 * HealthStatusDrawing.cpp
 *
 *  Created on: 14 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/Components/UI/HealthStatusDrawing.h>

#include <GameMachine/ResourceManager.h>

#include <GameClone/Defs.h>

#include <string>

namespace UI
{

HealthStatusDrawing::HealthStatusDrawing(sf::Vector2f pos, sf::Color color)
{
	const float spacing = 75.f;
	const float widthOutline = GAME_SCREEN_HALF_WIDTH - spacing;
	const float heightOutline = 40.f;
	const float margin = 10.f;

	_lifeRectMaxSize = sf::Vector2f(widthOutline - margin * 2, 20.f);

	_outlineRect.setPosition(pos);
	_outlineRect.setSize(sf::Vector2f(widthOutline, heightOutline));
	_outlineRect.setFillColor(sf::Color::White);

	_lifeRect.setOrigin(sf::Vector2f(-margin, -margin));
	_lifeRect.setPosition(pos);
	_lifeRect.setSize(_lifeRectMaxSize);
	_lifeRect.setFillColor(color);

	_lifeText.setFont(Resources::ResourceManager::get().getDefaultFont());
	_lifeText.setFillColor(color);
	_lifeText.setCharacterSize(35);

	sf::Vector2f textPosition = sf::Vector2f(0.f, pos.y);

	if (pos.x == 0.f)
	{
		textPosition.x += widthOutline + 5.f;
		_lifeText.setPosition(textPosition);
		return;
	}

	textPosition.x += widthOutline + 15.f;
	_lifeText.setPosition(textPosition);
	addToOrigin(_outlineRect, -spacing, 0.f);
	addToOrigin(_lifeRect, -spacing, 0.f);
	addToOrigin(_lifeText, -spacing, 0.f);

}

HealthStatusDrawing::~HealthStatusDrawing()
{
}

void HealthStatusDrawing::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_lifeText.setString(std::to_string(gameObject.getHealth()));
	_lifeRect.setSize(sf::Vector2f(getSizeFromHealth(gameObject), _lifeRectMaxSize.y));
}

void HealthStatusDrawing::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(_outlineRect);
	window.draw(_lifeRect);
	window.draw(_lifeText);
}

float HealthStatusDrawing::getSizeFromHealth(
		const GameObjects::GameObject& gameObject)
{
	return gameObject.getHealth() * _lifeRectMaxSize.x / gameObject.getMaxHealth();
}

void HealthStatusDrawing::addToOrigin(sf::Transformable& t, float x, float y)
{
	const sf::Vector2f origin = t.getOrigin();
	t.setOrigin(origin.x + x, origin.y + y);
}

} /* namespace UI */
