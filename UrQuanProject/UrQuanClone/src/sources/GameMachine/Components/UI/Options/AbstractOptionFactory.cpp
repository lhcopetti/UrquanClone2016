/*
 * OptionFactory.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/Options/AbstractOptionFactory.h>
#include <GameMachine/Components/UI/Options/LabelOption.h>

#include <GameMachine/Components/UI/ColorBoard.h>

namespace UI
{

AbstractOptionFactory::AbstractOptionFactory(sf::Vector2f boxSize, sf::Text textTemplate) :
		_boxSize(boxSize),
		_textTemplate(textTemplate)
{
}

AbstractOptionFactory::~AbstractOptionFactory()
{
	// TODO Auto-generated destructor stub
}

AbstractOption* AbstractOptionFactory::newOption(std::string text)
{
	sf::Text newText (_textTemplate);
	newText.setString(text);
	Components::ColorBoard* colorBoard = new Components::ColorBoard(newText, _foregroundColor, _boxSize.y, _boxSize.x);
	LabelOption* labelOption = new LabelOption(_boxSize, colorBoard);
	return labelOption;
}

} /* namespace UI */
