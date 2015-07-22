#include "game.h"
#include "textures.h"
#include "map.h"

void Game::initialize(sf::RenderWindow* wind){
    
    textures::setUpTextures();
    gameMap = Map(50,37,16,16);
    gameMap.generateMap();
    window = wind;
}

void Game::loop()
{
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
    
}
