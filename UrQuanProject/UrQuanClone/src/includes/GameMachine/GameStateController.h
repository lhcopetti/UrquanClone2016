/*
 * GameStateController.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_
#define INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <stack>
#include <vector>

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
class StackControlCommand;

class GameStateController : public UpdatableFromTime
{
public:
	GameStateController();
	virtual ~GameStateController();

	bool init(GameState::GameState* initialState);
	void deinit();

	virtual void update(const sf::Time& time);
	void draw(sf::RenderWindow& window);

	void addCommand(StackControlCommand* command);

private:
	std::stack<GameState::GameState*> _states;
	std::vector<StackControlCommand*> _stackCommands;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_ */
