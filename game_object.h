/* 
 * File:   game_object.h
 * Author: hirosum
 *
 * Created on 23 July 2015, 14:32
 */

#include <SFML/Graphics.hpp>

#ifndef GAME_OBJECT_H
#define	GAME_OBJECT_H

enum MobState {
    IDLE = 0,
    WALKING,
    HUNGRY,
    EATING
};

enum ActionResult {
    DIE = 0,
    EATGRASS,
    NOTHING
};


/*
 * Class to represent each object in the game e.g. mobs
 * Contains the object's position
 */
class GameObject {
public:
    GameObject(){}
    GameObject(float posX, float posY,int tileSizeX, int tileSizeY);
    void            setSpriteTexture(const sf::Texture& pTexture);
    sf::Sprite*     getSpritePtr();
protected:
    sf::Texture texture;
    sf::Vector2f    posPoint;
    sf::Vector2i    posTile;
    sf::IntRect     spriteRect;
    sf::Vector2i    tileSize;
    sf::Sprite      sprite;
    bool            hasSprite;
    void            centerOfTileFromPoint(sf::Vector2f& point);
};
class Mob : public GameObject
{
public:
    Mob(){}
    Mob(float posX, float posY, float pSpeed, int tileSizeX, int tileSizeY);
    int             getState();
    int             takeAction();
private:
    int             idleTimer;
    sf::Vector2i    destTile;
    MobState        state;
    float           speed;
    sf::Vector2f    destPoint;
    void            move();
    void            idle();
    void            findPath();
    bool            findFood();
    bool            eat();
};

#endif	/* GAME_OBJECT_H */

