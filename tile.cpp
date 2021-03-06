#include "tile.h"
#include <stdlib.h>
#include <time.h>




Tile::Tile(float pX, float pY, unsigned int tType)
{
    position.x = pX;
    position.y = pY;
    tileType = (TileType)tType;
    sprite.setPosition(position);
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
    growthChanceTime = 1000;
    timeSinceGrowthChance = rand() % growthChanceTime;
    growthLevel = 0;
}

void GrassTile::checkForGrowth()
{
    int willGrow = rand() % 1000;
    if(timeSinceGrowthChance >= growthChanceTime && growthLevel < 3)
    {
        if(willGrow >= 950)
            grow();
        timeSinceGrowthChance = 0;
    }
    else
        timeSinceGrowthChance++;
}

void GrassTile::grow()
{
    spriteRect.left += 64;
    sprite.setTextureRect(spriteRect);
    growthLevel++;
}