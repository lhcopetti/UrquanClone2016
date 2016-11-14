/*
 * Main.cpp
 *
 *  Created on: 4 de set de 2016
 *      Author: Pichau
 */

#include <iostream>
//#include "SFML/Graphics.hpp"

#include "GameClone/UrquanClone.h"

int main()
{
	std::cout << "This is the beginning! " << std::endl;

	GameClone::UrquanClone game;

	if (!game.init())
		goto end;

	game.execute();

	game.deinit();

	end: std::cout << "This is the end! " << std::endl;

	return 0;
}
