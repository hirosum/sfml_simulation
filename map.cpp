#include "map.h"

Map::Map(int sX, int sY,int tSizeX, int tSizeY)
{
    mapSize.x       = sX;
    mapSize.y       = sY;
    tileSize.x   = tSizeX;
    tileSize.y  = tSizeY;
}
Map::~Map()
{
    for(std::vector< std::vector< Tile* > >::iterator it1 = map.begin();
            it1 != map.end();
            ++it1)
    {
       for(std::vector< Tile* >::iterator it2 = it1.base()->begin();
               it2 != it1.base()->end();
               ++it2)
       {
           delete (*it2);
       }
       it1->clear();
    }
}

void Map::generatePlains()
{
    std::vector<Tile*> tempVector;
    for(int i=0; i<mapSize.x; i++)
    {
        for(int j=0; j<mapSize.y; j++)
        {
            GrassTile* grassTile = new GrassTile(i*tileSize.x,j*tileSize.y,0);
            tempVector.push_back(grassTile);
            grassTiles.push_back(grassTile);
        }
        map.push_back(tempVector);
        tempVector.clear();
    }
}

void Map::generateMap()
{
    generatePlains();
}

sf::Vector2i Map::getMapSize()
{
    return mapSize;
}

Tile* Map::getTilePtr(int x, int y)
{
    return map[x][y];
}

std::vector< GrassTile* > Map::getGrassTiles()
{
    return grassTiles;
}
