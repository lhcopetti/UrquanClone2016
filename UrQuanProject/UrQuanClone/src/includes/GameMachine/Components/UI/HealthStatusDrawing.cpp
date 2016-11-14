/*
 * HealthStatusDrawing.cpp
 *
 *  Created on: 14 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>

#include <GameMachine/Components/UI/HealthStatusDrawing.h>

#include <GameClone/Defs.h>

namespace UI
{

HealthStatusDrawing::HealthStatusDrawing(sf::Vector2f pos, sf::Color color)
{

	const float widthOutline = GAME_SCREEN_HALF_WIDTH - 50.f;
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

	_lifeText.setPosition(200.f, 200.f);
}

HealthStatusDrawing::~HealthStatusDrawing()
{
}

void HealthStatusDrawing::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_lifeText.setString("" + gameObject.getHealth());
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

} /* namespace UI */
