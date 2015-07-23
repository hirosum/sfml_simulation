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

enum TileType {
    GRASS = 0
};
/*
 * Class which represents each tile in the game world
 * Contains the tile's position, tile type, and sprite.
 * Contains functions to return the tile's sprite, set the tile's texture,
 *  and get the tile's type
 */
class Tile {
public:
    Tile(){}
    Tile(float,float, unsigned int);
    sf::Sprite*     getSprite();
    void            setSpriteTexture(const sf::Texture& pTexture);
    int             getTileType();
protected:
    sf::Vector2f    position;
    std::string     imgPath;
    TileType        tileType;
    sf::Sprite      sprite;   
    sf::IntRect     spriteRect;
};

/*
 * Sub-class of tile which represents a tile which is of type grass
 * Contains the time since the tile last "grew" and it's current "growth" level
 * Contains functions to check if it is due to "grow, and to cause it to "grow"
 */
class GrassTile : public Tile{
public:    
    GrassTile(){}
    GrassTile(float,float,unsigned int);
    void            checkForGrowth();
private:
    int             growthChanceTime;
    int             timeSinceGrowthChance;
    int             growthLevel;
    void            grow();
};
#endif	/* TILE_H */

