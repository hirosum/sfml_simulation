#include "game.h"
#include "texture_manager.h"
#include "map.h"

void Game::initialize(sf::RenderWindow* wind){
    
    gameMap = Map(50,37,16,16);
    gameMap.generateMap();
    window = wind;
    setUpTextures();
}

void Game::loop()
{
    delta = 0;
    while(window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        physicsAndLogic();
        render();
    }
}
void Game::render(){
    window->clear();
    renderMap();
    window->display();
}

void Game::renderMap()
{
    int sizeX = gameMap.getMapSize().x;
    int sizeY = gameMap.getMapSize().y;
    for(int i=0;i<sizeX;i++)
    {
        for(int j=0;j<sizeY;j++)
        {
            window->draw(*gameMap.getTilePtr(i,j)->getSprite());
        }
    }
}

void Game::physicsAndLogic()
{
    std::vector<GrassTile*> grassTiles = gameMap.getGrassTiles();
    for(std::vector<GrassTile*>::iterator it = grassTiles.begin();
            it != grassTiles.end();
            ++it)
    {
        (*it)->checkForGrowth();
    }
}

void Game::setUpTextures()
{
    for(int i=0; i<gameMap.getMapSize().x; i++)
    {
        for(int j=0; j<gameMap.getMapSize().y;j++)
        {
            Tile* tilePtr = gameMap.getTilePtr(i,j); 
            switch(tilePtr->getTileType())
            {
                case 0:
                    tilePtr->setSpriteTexture(textureManager.getTexture("images/grass_01.png"));
                    break;
                default:
                    std::cout << "Error: Tile has invalid type.\n";
                    break;
            }
                
        }
    }
}
Game::~Game()
{
    
}
