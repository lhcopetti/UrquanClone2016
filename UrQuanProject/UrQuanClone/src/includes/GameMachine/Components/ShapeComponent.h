/*
 * ShapeComponent.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_SHAPECOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_SHAPECOMPONENT_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace Components
{

class ShapeComponent: public DrawingComponent
{
public:
	ShapeComponent(sf::Shape* shape);
	virtual ~ShapeComponent();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const;

private:
	sf::Shape* _shape;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_SHAPECOMPONENT_H_ */
