/*
 * ShipDrawing.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/GameObjects/Ship/SpriteDrawing.h>

#include <SFML/Graphics.hpp>

#include <iostream>

namespace GameObjects
{

SpriteDrawing::SpriteDrawing(const std::string& resourcePath, float angleOffset) :
		_angleOffset(angleOffset)
{
	if (!_texture.loadFromFile(resourcePath))
	{
		std::cout << "Erro ao carregar do arquivo: " << resourcePath << std::endl;
		return;
	}

	_sprite = sf::Sprite(_texture);

	sf::IntRect rect = _sprite.getTextureRect();
	sf::Vector2f newOrigin(rect.width / 2, rect.height / 2);
	_sprite.setOrigin(newOrigin);
}

SpriteDrawing::~SpriteDrawing()
{
}

void GameObjects::SpriteDrawing::update(const GameObjects::GameObject& gameObject)
{
	_sprite.setPosition(gameObject.getPosition());
	_sprite.setRotation(gameObject.getOrientation() + 90.f);
}

void GameObjects::SpriteDrawing::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(_sprite);
}

} /* namespace GameObjects */
