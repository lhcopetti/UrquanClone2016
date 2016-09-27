/*
 * MainMenuState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_

#include <GameMachine/GameState/GameState.h>
#include <GameMachine/Components/UI/GameMenu.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>

#include <GameMachine/Components/UI/MenuComponent.h>

namespace UI
{
	class AbstractOption;
}

namespace GameState
{

class MainMenuState: public GameState, public Inputs::InputHandler
{
public:
	MainMenuState(GameMachine::GameStateController& controller, const sf::Font& font);
	virtual ~MainMenuState();

	virtual void onEnter();
	virtual void onExit();

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doDraw(sf::RenderWindow& window);

	sf::Text getDefaultSfText(const std::string& text);
	const sf::Font& getDefaultFont() const;

	virtual void handleInput(Inputs::InputAction inputAction);

private:
	enum GameOptions { START_GAME, SHOW_CREDITS, QUIT_GAME };
	Components::GameMenu<GameOptions> t;

	const sf::Font& _defaultFont;
	GameObjects::GameObject* _startMenu;

	int _testCounter;
	bool _registered;

	UI::AbstractOption* _optionStart;
	UI::AbstractOption* _optionCredits;
	UI::AbstractOption* _optionQuitGame;

	UI::MenuComponent* _menuComponent;
};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_MAINMENUSTATE_H_ */
