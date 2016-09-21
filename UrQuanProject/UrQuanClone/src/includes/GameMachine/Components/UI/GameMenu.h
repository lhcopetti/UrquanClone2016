/*
 * GameMenu.h
 *
 *  Created on: 18 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef SOURCES_GAMEMACHINE_COMPONENTS_UI_GAMEMENU_H_
#define SOURCES_GAMEMACHINE_COMPONENTS_UI_GAMEMENU_H_

#include <type_traits>

namespace Components
{

template<typename T, typename std::enable_if<std::is_enum<T>::value>::type* =
		nullptr>
class GameMenu
{
public:
	GameMenu() :
		_anySelected(false)
	{
	}
	virtual ~GameMenu()
	{
	}

	void init()
	{

	}

	bool anySelected()
	{
		return _anySelected;
	}

private:
	bool _anySelected;
};

} /* namespace Components */

#endif /* SOURCES_GAMEMACHINE_COMPONENTS_UI_GAMEMENU_H_ */
