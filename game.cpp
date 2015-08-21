#include "game.h"
#include "texture_manager.h"
#include "map.h"

void Game::initialize(sf::RenderWindow* wind){
    
    gameMap = Map(50,37,16,16);
    gameMap.generateMap();
    window = wind;
    renderer = Renderer(wind);
    setUpMenus();
//    auto mob = std::unique_ptr<Mob>(new Mob(43.11f, 145.0f, 1.0f, 64,64));
//    mobs.push_back(std::move(mob));
    setUpTexturesAndSprites();
    currentMode = MAINMENU;
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
            keyboardInput(event);
            mouseInput(event);
        }
        
        drawable.clear();
        switch (currentMode)
        {
                case MAINMENU:
                    addMainMenuToDrawable(1);                    
                    break;
                case GAMERUNNING:
                    physicsAndLogic();
                    addMapToDrawable(0);
                    addGameObjectsToDrawable(1);
                    addGameInterfaceToDrawable(2);
                    break;
                case PAUSED:
                    addMapToDrawable(0);
                    addGameObjectsToDrawable(1);
                    addGameInterfaceToDrawable(2);
                    addPauseMenuToDrawable(3);
                    break;
        }         
        renderer.drawScene(drawable);
    }
}
void Game::render(){
}

void Game::addMapToDrawable(int  order)
{
    int sizeX = gameMap.getMapSize().x;
    int sizeY = gameMap.getMapSize().y;
    for(int i=0;i<sizeX;i++)
    {
        for(int j=0;j<sizeY;j++)
        {
            Drawable draw;
            draw.sprite = gameMap.getTilePtr(i,j)->getSprite();
            draw.z      = order;
            if(draw.sprite != NULL)
                    drawable.push_back(draw); 
        }
    }
}

void Game::physicsAndLogic()
{
    gameMap.checkMapForGrowth();
}

void Game::setUpTexturesAndSprites()
{   
    gameMap.setUpTextures(textureManager);
    
    for(std::vector<MobPtr>::iterator it = mobs.begin();
            it != mobs.end();
            ++it)
    {
        
        (*it)->setSpriteTexture(textureManager.getTexture("images/char.png"));
        
    }
    for(std::vector<GuiPtr>::iterator it = mainMenu.begin();
            it != mainMenu.end();
            ++it)
    {
        (*it)->setSpriteTexture(textureManager.getTexture("images/" + (*it)->getName() + ".png"));
        
    }
}

void Game::setUpMenus()
{
    typedef std::unique_ptr<Button> ButtonPtr;
    mainMenu.push_back(ButtonPtr(new Button(1344.0f,300.0f,"new_game_button",256,64)));
}

void Game::addGameObjectsToDrawable(int order)
{
    
    for(std::vector<std::unique_ptr<Mob>> ::iterator it = mobs.begin();
            it != mobs.end();
            ++it)
    {
        Drawable draw;
        draw.sprite = (*it)->getSpritePtr();
        draw.z      = order;
        if(draw.sprite != NULL)
                drawable.push_back(draw); 
    }
}

void Game::addMainMenuToDrawable(int order)
{
    for(std::vector<std::unique_ptr<GuiItem>>::iterator it = mainMenu.begin();
            it != mainMenu.end();
            ++it)
    {
        Drawable draw;
//        draw.sprite = (*it)->getSprite();
        draw.sprite = (*it)->getSprite();
        draw.z      = order;
        if(draw.sprite != NULL)
                drawable.push_back(draw);      
    }
    
}

void Game::addPauseMenuToDrawable(int order)
{
    
}

void Game::addGameInterfaceToDrawable(int order)
{
    for(std::vector<std::unique_ptr<GuiItem>>::iterator it = gameInterface.begin();
            it != gameInterface.end();
            ++it)
    {
        Drawable draw;
//        draw.sprite = (*it)->getSprite();
        draw.sprite = (*it)->getSprite();
        draw.z      = order;
        if(draw.sprite != NULL)
                drawable.push_back(draw);      
    }    
}

void Game::keyboardInput(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Return && currentMode == MAINMENU)
            currentMode = GAMERUNNING;
        if (event.key.code == sf::Keyboard::P)
        {
            if(currentMode == GAMERUNNING)
                currentMode = PAUSED;
            else if(currentMode == PAUSED)
                currentMode = GAMERUNNING;
        }
    }
}

void Game::mouseInput(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            switch (currentMode)
            {
                case MAINMENU:
                    for(std::vector<GuiPtr>::iterator it = mainMenu.begin();
                            it != mainMenu.end();
                            ++it)
                    {
                        if((*it)->getClassName() == "Button")
                        {
                            if(isMouseInsideBox((*it)->getBoxFloat()))
                                std::cout << "Click!\n";
                        }
                    }
                    
                    break;
                    
            }
        }
    }
}

bool Game::isMouseInsideBox(sf::FloatRect box)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    if(mousePos.x >= box.left && mousePos.x <= box.left + box.width 
            && mousePos.y >= box.top && mousePos.y <= box.top + box.height)
        return true;
    else
        return false;
}
Game::~Game()
{
//    for(std::vector<GameObject*>::iterator it = gameObjects.begin();
//            it != gameObjects.end();
//            ++it)
//    {
//        delete &it;
//    }
//    
//    for(std::vector<GuiItem*>::iterator it = mainMenu.begin();
//            it != mainMenu.end();
//            ++it)
//    {
//        delete &it;
//    }
//    for(std::vector<Drawable*>::iterator it = drawable.begin();
//            it != drawable.begin();
//            ++it)
//    {
//        delete &it;
//    }
}
