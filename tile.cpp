#include "tile.h"
#include "textures.h"
Tile::Tile(float pX, float pY, unsigned int tType)
{
    posX = pX;
    posY = pY;
    tileType = (TileType)tType;
    TextureHandler txHandler = TextureHandler.getInstance();
    switch((int)tileType)
    {
        case 0:
        {
            sprite.setTexture(txHandler.grass_01);
            break;
        }
        default:
        {
            sprite.setTexture(txHandler.grass_01);
            break;
        }
    }
    sprite.setPosition(posX,posY);
                
}

sf::Sprite* Tile::getSprite()
{
    return &sprite;
}