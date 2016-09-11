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

	game.start();

	game.shutdown();

//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }

    return 0;
}
