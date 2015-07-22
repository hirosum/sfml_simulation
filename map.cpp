#include "map.h"

Map::Map(int sX, int sY,int tSizeX, int tSizeY)
{
    sizeX       = sX;
    sizeY       = sY;
    tileSizeX   = tSizeX;
    tileSizeY   = tSizeY;
}

void Map::generatePlains()
{
    for(int i=0; i<sizeX; i++)
    {
        for(int j=0; j<sizeY; j++)
        {
            map[i][j] = Tile(i*tileSizeX,j*tileSizeY,0);
        }
    }
}

void Map::generateMap()
{
    generatePlains();
}

sf::Vector2i Map::getMapSize()
{
    return sf::Vector2i(sizeX,sizeY);
}

Tile* Map::getTilePtr(int x, int y)
{
    return &map[x][y];
}
