/* 
 * File:   map.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 09:22
 */


#ifndef MAP_H
#define	MAP_H

#include <memory>
#include <vector>
#include "tile.h"
#include "texture_manager.h"

typedef std::shared_ptr<Tile>       TilePtr;
typedef std::shared_ptr<GrassTile>  GrassPtr;

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
    void                                generateMap();
    sf::Vector2i                        getMapSize();
    TilePtr                             getTilePtr(int,int);
    void                                checkMapForGrowth();
    void                                setUpTextures(TextureManager& textMan);
private:
    sf::Vector2i                        mapSize;
    sf::Vector2i                        tileSize;
    std::vector<std::vector<TilePtr>>   map;
    std::vector<GrassPtr>               grassTiles;
    void                                generatePlains();
};

#endif	/* MAP_H */

