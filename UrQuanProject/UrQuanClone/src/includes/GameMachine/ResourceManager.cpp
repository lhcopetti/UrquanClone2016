/*
 * ResourceManager.cpp
 *
 *  Created on: 14 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/ResourceManager.h>

#include <iostream>

namespace Resources
{


ResourceManager::ResourceManager()
{
	const std::string fontName = "ARIAL.TTF";
	if (!_defaultFont.loadFromFile(fontName))
	{
		std::cout << "Failed to load font: " << fontName << std::endl;
	}
}

ResourceManager::~ResourceManager()
{

}

ResourceManager& ResourceManager::get()
{
	static ResourceManager INSTANCE;
	return INSTANCE;
}

const sf::Font& ResourceManager::getDefaultFont() const
{
	return _defaultFont;
}
} /* namespace UI */
