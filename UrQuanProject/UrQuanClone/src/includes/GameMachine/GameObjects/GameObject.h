/*
 * GameObject.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include "GameMachine/Components/DrawingComponent.h"

namespace GameObjects
{

class GameObject : public UpdatableFromTime
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void update(const sf::Time& deltaTime);
	void draw(sf::RenderWindow& window) const;

	void setDrawing(Components::DrawingComponent* drawing);

private:
	std::unique_ptr<Components::DrawingComponent> _drawingComponent;
};

} /* namespace GameState */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_ */
