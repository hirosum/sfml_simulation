/* 
 * File:   tile.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 09:29
 */
#ifndef TILE_H
#define	TILE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum TileType {
    GRASS = 0
};

class Tile {
public:
    Tile(){}
    Tile(float,float, unsigned int);
    sf::Sprite* getSprite();
private:
    float       posX;
    float       posY;
    string      imgPath;
    TileType    tileType;
    sf::Sprite  sprite;
};
#endif	/* TILE_H */

