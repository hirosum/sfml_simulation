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

class Tile {
public:
    Tile(){}
    Tile(float,float, unsigned int);
    sf::Sprite*     getSprite();
    void            setSpriteTexture(const sf::Texture& pTexture);
    int             getTileType();
protected:
    float           posX;
    float           posY;
    std::string     imgPath;
    TileType        tileType;
    sf::Sprite      sprite;    
    sf::Texture     texture;
    sf::IntRect     spriteRect;
};
#endif	/* TILE_H */

class GrassTile : public Tile{
public:    
    GrassTile(){}
    GrassTile(float,float,unsigned int);
    void            checkForGrowth();
private:
    int             timeSinceGrowth;
    int             growthLevel;
    void            grow();
};

