/* 
 * File:   gui_item.h
 * Author: hirosum
 *
 * Created on 14 August 2015, 11:41
 */
#ifndef SMFL
#define SMFL

#include <SFML/Graphics.hpp>

#endif
#ifndef GUI_ITEM_H
#define	GUI_ITEM_H

class GuiItem
{
public:
    GuiItem(float posX, float posY, std::string name);
    sf::Sprite*         getSprite();
    sf::Vector2f        getPosition();
    sf::FloatRect       getBoxFloat();
    std::string         getName();
    std::string         getClassName();
    void                setSpriteTexture(const sf::Texture& pTexture);
    void                setPosition(float x, float y);
    void                setPosition(sf::Vector2f pos);
    
protected:
    sf::Vector2f        position;
    std::string         itemName;
    sf::Sprite          sprite;
    sf::IntRect         spriteRect;
    sf::Vector2i        size;
    std::string         className;
    bool                hasSprite;
    
};

class Button : public GuiItem
{
public:
    Button(float posX, float posY, std::string name, int sizeX, int sizeY);
private:
    
};

#endif	/* GUI_ITEM_H */

