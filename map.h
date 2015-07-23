/* 
 * File:   map.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 09:22
 */


#ifndef MAP_H
#define	MAP_H

#include <vector>
#include "tile.h"

/*
 * Class which represents the map of the game.
 * Contains the map's size, the size of each tile in the map and a vector 
 * of each type of tile on the map.
 * Contains functions to generate the map, get the size of the map,
 * get a specific tile on the map, and get all the tile of a specific type on
 * the map
 */
class Map {
public:
    Map(){}
    Map(int,int,int,int);
    ~Map();
    void generateMap();
    sf::Vector2i getMapSize();
    Tile* getTilePtr(int,int);
    std::vector< GrassTile* > getGrassTiles();
private:
    sf::Vector2i mapSize;
    sf::Vector2i tileSize;
    std::vector < std::vector < Tile* > > map;
    std::vector< GrassTile* > grassTiles;
    void generatePlains();
};

#endif	/* MAP_H */

