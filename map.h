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
    ~Map();
    void generateMap();
    sf::Vector2i getMapSize();
    Tile* getTilePtr(int,int);
    std::vector< GrassTile* > getGrassTiles();
private:
    int sizeX;
    int sizeY;
    int tileSizeX;
    int tileSizeY;
    std::vector < std::vector < Tile* > > map;
    std::vector< GrassTile* > grassTiles;
    void generatePlains();
    void fillMapVector();
};

#endif	/* MAP_H */

