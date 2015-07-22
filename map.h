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

class Map {
public:
    Map(){}
    Map(int,int,int,int);
    void generateMap();
    sf::Vector2i getMapSize();
    Tile* getTilePtr(int,int);
private:
    int sizeX;
    int sizeY;
    int tileSizeX;
    int tileSizeY;
    vector< vector<Tile> > map;
    void generatePlains();
};

#endif	/* MAP_H */

