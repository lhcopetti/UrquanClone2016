/*
 * CompositeDrawingComponent.h
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COMPOSITEDRAWINGCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COMPOSITEDRAWINGCOMPONENT_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace Components
{

class CompositeDrawingComponent: public DrawingComponent
{
public:
	CompositeDrawingComponent();
	virtual ~CompositeDrawingComponent();

	void push(DrawingComponent* drawing);

	virtual void sendMessage(const std::string& msg);
	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const;

private:

	std::vector<DrawingComponent*> _drawings;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COMPOSITEDRAWINGCOMPONENT_H_ */
