/*
 * CompositeDrawingComponent.cpp
 *
 *  Created on: 21 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/CompositeDrawingComponent.h>

namespace Components
{

CompositeDrawingComponent::CompositeDrawingComponent()
{
}

CompositeDrawingComponent::~CompositeDrawingComponent()
{
	for (unsigned int i = 0; i < _drawings.size(); i++)
		delete _drawings[i];
}

void CompositeDrawingComponent::push(DrawingComponent* drawing)
{
	_drawings.push_back(drawing);
}

void CompositeDrawingComponent::sendMessage(const std::string& msg)
{
	std::for_each(_drawings.begin(), _drawings.end(), [&] (DrawingComponent* d)
	{
		d->sendMessage(msg);
	});
}

void CompositeDrawingComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	std::for_each(_drawings.begin(), _drawings.end(), [&] (DrawingComponent* d)
	{
		d->update(deltaTime, gameObject);
	});
}

void CompositeDrawingComponent::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	std::for_each(_drawings.begin(), _drawings.end(), [&](DrawingComponent* d)
	{
		d->draw(gameObject, window);
	});
}

} /* namespace Components */
