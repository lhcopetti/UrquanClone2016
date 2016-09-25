/*
 * OptionFactory.h
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_ABSTRACTOPTIONFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_ABSTRACTOPTIONFACTORY_H_

#include <SFML/Graphics.hpp>

namespace UI
{

class AbstractOption;

class AbstractOptionFactory
{
public:
	AbstractOptionFactory(sf::Vector2f boxSize, sf::Text textTemplate);
	virtual ~AbstractOptionFactory();

	AbstractOption* newOption(std::string text);

private:
	const sf::Vector2f _boxSize;
	const sf::Text _textTemplate;

	const sf::Color _foregroundColor = sf::Color::Blue;
	const sf::Color _backgroundColor = sf::Color::Red;
};

} /* namespace UI */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_ABSTRACTOPTIONFACTORY_H_ */
