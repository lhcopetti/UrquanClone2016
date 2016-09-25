/*
 * ColorBoard.h
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_UI_COLORBOARD_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_UI_COLORBOARD_H_

#include "GameMachine/Components/DrawingComponent.h"
#include <SFML/Graphics.hpp>

namespace Components
{

class ColorBoard: public Components::DrawingComponent
{
public:
	ColorBoard(sf::Text text, sf::Color color = sf::Color::Blue, int heigth = 50, int width = 200);
	virtual ~ColorBoard();

	virtual void update(const GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const;

	virtual void sendMessage(const std::string& msg);

private:
	sf::RectangleShape _board;
	sf::RectangleShape _outlineHighlight;
	sf::RectangleShape _outlineSelect;
	sf::Text _text;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_UI_COLORBOARD_H_ */
