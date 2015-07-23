/* 
 * File:   game.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 14:13
 */

#ifndef GAME_H
#define	GAME_H
#include "map.h"
#include "textures.h"

class Game {
public:
    Game(){}
    void initialize(sf::RenderWindow*);
    void loop();
    void render();
    void physicsAndLogic();
private:
    sf::RenderWindow* window;
    void renderMap();
    Map gameMap;
    TextureManager textureManager;
    void setUpTextures();
};

#endif	/* GAME_H */

