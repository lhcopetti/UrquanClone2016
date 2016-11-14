/*
 * HealthStatusDrawing.h
 *
 *  Created on: 14 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_UI_HEALTHSTATUSDRAWING_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_UI_HEALTHSTATUSDRAWING_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace UI
{

class HealthStatusDrawing: public Components::DrawingComponent
{
public:
	HealthStatusDrawing(sf::Vector2f pos, sf::Color color);
	virtual ~HealthStatusDrawing();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const;

private:

	float getSizeFromHealth(const GameObjects::GameObject& gameObject);

	sf::Text _lifeText;
	sf::RectangleShape _lifeRect;
	sf::RectangleShape _outlineRect;

	sf::Vector2f _lifeRectMaxSize;
};

} /* namespace UI */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_UI_HEALTHSTATUSDRAWING_H_ */
