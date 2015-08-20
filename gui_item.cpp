
#include <SFML/Graphics/Rect.hpp>

#include "gui_item.h"



GuiItem::GuiItem(float posX, float posY, std::string name)
{
    position.x  = posX;
    position.y  = posY;
    itemName    = name;
}

Button::Button(float posX, float posY, std::string name, int sizeX, int sizeY): GuiItem(posX,posY,name)
{
    spriteRect = sf::IntRect(0,0,sizeX,sizeY);
    size = sf::Vector2i(sizeX,sizeY);
}

sf::Sprite* GuiItem::getSprite()
{
    if(hasSprite)
        return &sprite;
    else
        return NULL;
}
std::string GuiItem::getName()
{
    return itemName;
}
void GuiItem::setSpriteTexture(const sf::Texture& pTexture)
{
    sprite.setTexture(pTexture);
    sprite.setTextureRect(spriteRect);
    sprite.setPosition(position.x,position.y);
    sprite.setScale(1.0f,1.0f);
}
