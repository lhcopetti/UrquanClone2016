/*
 * GameObject.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>
#include "SFML/Graphics.hpp"

namespace Components
{
class DrawingComponent;
}

namespace GameObjects
{

class GameObject: public UpdatableFromTime, public Inputs::InputHandler
{
public:
	GameObject(Components::DrawingComponent* drawingComponent = nullptr,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
	virtual ~GameObject();

	void update(const sf::Time& deltaTime);
	virtual void doUpdate(const sf::Time& deltaTime);

	void draw(sf::RenderWindow& window) const;

	void setPosition(const sf::Vector2f& newPos);
	const sf::Vector2f& getPosition() const;

	void setOrientation(float newOrientation);
	float getOrientation() const;

	void handleInput(int userData);

	bool isAlive() const;

protected:

	std::unique_ptr<Components::DrawingComponent> _drawingComponent;
	bool _alive;
	sf::Vector2f _pos;
	float _orientation;

private:
};

} /* namespace GameState */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_ */
