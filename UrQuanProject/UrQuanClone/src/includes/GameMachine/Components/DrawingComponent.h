/*
 * DrawingComponent.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_

#include "SFML/Graphics.hpp"

namespace GameObjects
{
	class GameObject;
}

namespace Components
{

class DrawingComponent
{
public:
	DrawingComponent();
	virtual ~DrawingComponent();

	virtual void sendMessage(const std::string& msg);
	virtual void update(const GameObjects::GameObject& gameObject) = 0;
	virtual void draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const = 0;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_DRAWINGCOMPONENT_H_ */
