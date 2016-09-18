/*
 * GameObject.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include "SFML/Graphics.hpp"

namespace Components
{
	class DrawingComponent;
}

namespace GameObjects
{

class GameObject: public UpdatableFromTime
{
public:
	GameObject(Components::DrawingComponent* drawingComponent = nullptr,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
	virtual ~GameObject();

	virtual void update(const sf::Time& deltaTime);
	void draw(sf::RenderWindow& window) const;

	void setPosition(const sf::Vector2f& newPos);
	const sf::Vector2f getPosition() const { return _pos; }

private:
	std::unique_ptr<Components::DrawingComponent> _drawingComponent;
	sf::Vector2f _pos;
};

} /* namespace GameState */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_ */
