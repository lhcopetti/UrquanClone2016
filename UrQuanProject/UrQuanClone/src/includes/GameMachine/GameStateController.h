/*
 * GameStateController.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_
#define INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <memory>

namespace sf
{
class Time;
class RenderWindow;
}

namespace GameState
{
class GameState;
}

namespace GameMachine
{

class GameStateController : public UpdatableFromTime
{
public:
	GameStateController();
	virtual ~GameStateController();

	bool init(GameState::GameState* initialState);
	void deinit();

	virtual void update(const sf::Time& time);
	void draw(sf::RenderWindow& window);

private:

	std::unique_ptr<GameState::GameState> _currentState;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_ */
