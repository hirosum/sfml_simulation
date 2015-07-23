#include "game_object.h"

GameObject::GameObject(float posX, float posY)
{
    position.x = posX;
    position.y = posY;
}

Mob::Mob(float posX, float posY) : GameObject(posX, posY)
{
    
}
