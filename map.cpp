#include "map.h"

Map::Map(int sizeX, int sizeY,int tSizeX, int tSizeY)
{
    mapSize.x       = sizeX;
    mapSize.y       = sizeY;
    tileSize.x   = tSizeX;
    tileSize.y  = tSizeY;
}
Map::~Map()
{
//    for(std::vector< std::vector< Tile* > >::iterator it1 = map.begin();
//            it1 != map.end();
//            ++it1)
//    {
//       for(std::vector< Tile* >::iterator it2 = it1.base()->begin();
//               it2 != it1.base()->end();
//               ++it2)
//       {
//           delete (*it2);
//       }
//       it1->clear();
//    }
}

void Map::generatePlains()
{
    std::vector<TilePtr> tempVector;
    for(int i=0; i<mapSize.x; i++)
    {
        for(int j=0; j<mapSize.y; j++)
        {
            GrassPtr grassTile = GrassPtr(new GrassTile(i*tileSize.x,j*tileSize.y,0));
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

void Map::checkMapForGrowth()
{
    for(std::vector<GrassPtr>::iterator it = grassTiles.begin();
            it != grassTiles.end();
            ++it)
    {
        (*it)->checkForGrowth();
    }
}

TilePtr Map::getTilePtr(int x, int y)
{
    return map[x][y];
}

void Map::setUpTextures(TextureManager& textMan)
{
    for(int i=0; i< mapSize.x; i++)
    {
        for(int j=0; j< mapSize.y;j++)
        {
            TilePtr tile = map[i][j];
            switch(tile->getTileType())
            {
                case 0:
                    tile->setSpriteTexture(textMan.getTexture("images/grass_01.png"));
                    break;
                default:
                    std::cout << "Error: Tile has invalid type.\n";
                    break;
            }
                
        }
    }
}
