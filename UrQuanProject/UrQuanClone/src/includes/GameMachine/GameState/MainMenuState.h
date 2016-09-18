/*
 * MainMenuState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_

#include <GameMachine/GameState/GameState.h>

namespace GameState
{

class MainMenuState: public GameState
{
public:
	MainMenuState(const sf::Font& font);
	virtual ~MainMenuState();

	virtual void onEnter();
	virtual void onExit();

	virtual void update(const sf::Time& deltaTime);
	virtual void draw(sf::RenderWindow& window);

	sf::Text getDefaultSfText(const std::string& text);
	const sf::Font& getDefaultFont() const;
private:
	const sf::Font& _defaultFont;

};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_ */
