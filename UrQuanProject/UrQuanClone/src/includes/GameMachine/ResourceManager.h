/*
 * ResourceManager.h
 *
 *  Created on: 14 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_RESOURCEMANAGER_H_
#define INCLUDES_GAMEMACHINE_RESOURCEMANAGER_H_

#include <SFML/Graphics/Font.hpp>

namespace Resources
{

class ResourceManager
{
public:
	virtual ~ResourceManager();

	static ResourceManager& get();

	const sf::Font& getDefaultFont() const;

private:
	ResourceManager();

	sf::Font _defaultFont;
};

} /* namespace UI */

#endif /* INCLUDES_GAMEMACHINE_RESOURCEMANAGER_H_ */
