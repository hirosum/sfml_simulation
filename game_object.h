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
private:
    sf::Vector2f position; 
};

enum MobState {
    IDLE = 0,
    HUNGRY,
    EATING
};

class Mob : public GameObject
{
public:
    Mob(){}
    Mob(float posX, float posY);
private:
    float speed;
};

#endif	/* GAME_OBJECT_H */

