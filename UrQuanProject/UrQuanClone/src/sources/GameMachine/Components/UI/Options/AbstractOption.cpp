/*
 * AbstractOption.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/Options/AbstractOption.h>

#include <GameMachine/Components/DrawingComponent.h>

namespace UI
{

AbstractOption::AbstractOption(sf::Vector2f size, Components::DrawingComponent* drawingComponent) :
		GameObject(drawingComponent),
		_size(size),
		_selected(false),
		_highlighted(false)
{

}

AbstractOption::~AbstractOption()
{
}

bool AbstractOption::isSelected() const
{
	return _selected;
}

bool AbstractOption::isHighlighted() const
{
	return _highlighted;
}

void AbstractOption::select() const
{
	_drawingComponent->sendMessage("SELECT");
}

void AbstractOption::deselect() const
{
	_drawingComponent->sendMessage("DESELECT");
}

void AbstractOption::hightlight() const
{
	_drawingComponent->sendMessage("HIGHLIGHT");
}

void AbstractOption::unhighlight() const
{
	_drawingComponent->sendMessage("UNHIGHLIGHT");
}

const sf::Vector2f AbstractOption::getSize() const
{
	return _size;
}

} /* namespace UI */
