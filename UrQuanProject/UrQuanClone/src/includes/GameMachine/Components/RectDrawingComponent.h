/*
 * RectDrawingComponent.h
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_RECTDRAWINGCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_RECTDRAWINGCOMPONENT_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace Components
{

class RectDrawingComponent: public DrawingComponent
{
public:
	RectDrawingComponent(sf::Color color, sf::Vector2f pos, sf::Vector2f size);
	virtual ~RectDrawingComponent();

	virtual void update(const sf::Time& deltaTime,
			GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject,
			sf::RenderWindow& window) const;

private:
	sf::RectangleShape _shape;
};

} /* namespace Geometry */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_RECTDRAWINGCOMPONENT_H_ */
