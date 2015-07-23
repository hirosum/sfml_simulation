#include "game_object.h"

GameObject::GameObject(float posX, float posY)
{
    position.x = posX;
    position.y = posY;
}

sf::Sprite* GameObject::getSpritePtr()
{
    return sprite;
}

Mob::Mob(float posX, float posY, float pSpeed) : GameObject(posX, posY)
{
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

void Mob::findFood()
{
    
}

void Mob::eat()
{
    
}


