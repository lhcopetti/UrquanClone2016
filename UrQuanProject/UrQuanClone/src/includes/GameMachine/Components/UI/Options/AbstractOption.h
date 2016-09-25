/*
 * AbstractOption.h
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_ABSTRACTOPTION_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_ABSTRACTOPTION_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace UI
{

class AbstractOption : public GameObjects::GameObject
{
public:

	enum
	{
		HIGHTLIGHT,
		UNHIGHLIGHT,
		SELECT,
		DESELECT
	};

	AbstractOption(sf::Vector2f size, Components::DrawingComponent* drawingComponent);
	virtual ~AbstractOption();

	bool isSelected() const;
	bool isHighlighted() const;

	void select() const;
	void deselect() const;

	void hightlight() const;
	void unhighlight() const;

	const sf::Vector2f getSize() const;

private:
	sf::Vector2f _size;

	bool _selected;
	bool _highlighted;
};

} /* namespace UI */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_ABSTRACTOPTION_H_ */
