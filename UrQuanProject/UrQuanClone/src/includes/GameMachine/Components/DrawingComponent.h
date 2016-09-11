/*
 * DrawingComponent.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_

#include "SFML/Graphics.hpp"

namespace Components
{

class DrawingComponent
{
public:
	DrawingComponent();
	virtual ~DrawingComponent();

	virtual void draw(sf::RenderWindow& window) const;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_ */
