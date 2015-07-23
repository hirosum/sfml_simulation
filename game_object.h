/* 
 * File:   game_object.h
 * Author: hirosum
 *
 * Created on 23 July 2015, 14:32
 */

#include <SFML/Graphics.hpp>

#ifndef GAME_OBJECT_H
#define	GAME_OBJECT_H
/*
 * Class to represent each object in the game e.g. mobs
 * Contains the object's position
 */
class GameObject {
public:
    GameObject(){}
    GameObject(float posX, float posY);
    sf::Sprite* getSpritePtr();
private:
    sf::Vector2i tilePosition;
    sf::Vector2f position;
    sf::Sprite sprite;
};

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

class Mob : public GameObject
{
public:
    Mob(){}
    Mob(float posX, float posY, float pSpeed);
    int getState();
    int takeAction();
private:
    int idleTimer;
    int idleTimer;
    MobState state;
    float speed;
    sf::Vector2f destination;
    void move();
    void eat();
    void idle();
    void findFood();
    void findPath();
};

#endif	/* GAME_OBJECT_H */

