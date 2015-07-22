/* 
 * File:   main.cpp
 * Author: hirosum
 *
 * Created on 21 July 2015, 14:50
 */

#include <cstdlib>
#include "game.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Game game;
    game.initialize(&window);
    game.loop();

    return 0;
}

