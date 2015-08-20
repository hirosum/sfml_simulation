#include "game_object.h"

GameObject::GameObject(float posX, float posY,int tileSizeX, int tileSizeY)
{
    tileSize.x = tileSizeX;
    tileSize.y = tileSizeY;
    posPoint.x = posX;
    posPoint.y = posY;
    hasSprite = false;
}

sf::Sprite* GameObject::getSpritePtr()
{
    if(hasSprite)
        return &sprite;
    else
        return NULL;
}

void GameObject::centerOfTileFromPoint(sf::Vector2f& point)
{
    sf::Vector2i tile;
    tile.x      = (int)point.x / tileSize.x;
    tile.y      = (int)point.y / tileSize.y;
    point.x     = ((tile.x * tileSize.x) + (float)tileSize.x / 2);
    point.y     = ((tile.y * tileSize.y) + (float)tileSize.y / 2);
}


void GameObject::setSpriteTexture(const sf::Texture& pTexture)
{
    hasSprite = true;
    sprite.setPosition(posPoint);
    spriteRect  = sf::IntRect(0,0,64,64); 
    sprite.setTexture(pTexture);
    sprite.setTextureRect(spriteRect);
    sprite.setScale(0.5f,0.5f);
}

Mob::Mob(float posX, float posY, float pSpeed, int tileSizeX, int tileSizeY) : GameObject(posX, posY, tileSizeX,tileSizeY)
{
    centerOfTileFromPoint(posPoint);
    speed = pSpeed;
}

int Mob::getState()
{
    return (int)state;
}

int Mob::takeAction()
{
    switch((int)state)
    {
        case 0:
           idle();
           break;
        case 1:
            move();
            break;
        case 2:
            if(!findFood())
                return (int)DIE;
            break;
        case 3:
            if(eat())
                return (int)EATGRASS;
            break;
        default:
            idle();
            break;
    }
    return (int)NOTHING;
}

void Mob::idle()
{
    if(idleTimer >= 100)
    {
        state = WALKING;
    }
    idleTimer++;
}

bool Mob::findFood()
{
    
}

bool Mob::eat()
{
    
}

void Mob::move()
{
    
}


