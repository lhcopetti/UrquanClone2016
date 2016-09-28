/*
 * ShipDrawing.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Ship/ShipDrawing.h>
#include <GameMachine/GameObjects/GameObject.h>

#include <SFML/Graphics.hpp>

#include <iostream>

namespace GameObjects
{

ShipDrawing::ShipDrawing(const std::string& resourcePath)
{
	if (!_texture.loadFromFile(resourcePath))
	{
		std::cout << "Erro ao carregar do arquivo: " << resourcePath << std::endl;
		return;
	}

	_sprite = sf::Sprite(_texture);
}

ShipDrawing::~ShipDrawing()
{
}

void GameObjects::ShipDrawing::update(const GameObjects::GameObject& gameObject)
{
	_sprite.setPosition(gameObject.getPosition());
}

void GameObjects::ShipDrawing::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	sf::CircleShape circle;
	circle.setRadius(10.f);
	circle.setFillColor(sf::Color::Black);
	circle.setPosition(gameObject.getPosition());
	window.draw(circle);

	window.draw(_sprite);
}

} /* namespace GameObjects */
