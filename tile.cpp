#include "tile.h"
#include <random>
Tile::Tile(float pX, float pY, unsigned int tType)
{
    posX = pX;
    posY = pY;
    tileType = (TileType)tType;
    sprite.setPosition(posX,posY);
    spriteRect = sf::IntRect(0,0,64,64);            
}

sf::Sprite* Tile::getSprite()
{
    return &sprite;
}
void Tile::setSpriteTexture(const sf::Texture& pTexture)
{
    sprite.setTexture(pTexture);
    sprite.setTextureRect(spriteRect);
}

int Tile::getTileType()
{
    return (int)tileType;
}

GrassTile::GrassTile(float pX, float pY, unsigned int tType) : Tile(pX,pY,tType)
{
    timeSinceGrowth = 0;
    growthLevel = 0;
}

void GrassTile::checkForGrowth()
{
    srand();
    //int canGrow = 
    if(timeSinceGrowth >= 200 && growthLevel < 3)
    {
        grow();
        timeSinceGrowth = 0;
        growthLevel++;
    }
    else
        timeSinceGrowth++;
}

void GrassTile::grow()
{
    spriteRect.left += 64;
    sprite.setTextureRect(spriteRect);
}