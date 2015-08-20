/* 
 * File:   game.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 14:13
 */

#ifndef GAME_H
#define	GAME_H
#include "map.h"
#include "game_object.h"
#include "gui_item.h"
#include "renderer.h"
#include <memory>

typedef std::unique_ptr<GuiItem>    GuiPtr;
typedef std::unique_ptr<GameObject> ObjectPtr;
typedef std::unique_ptr<Mob>        MobPtr;


enum GameMode {
    MAINMENU = 0,
    GAMERUNNING,
    PAUSED
};
class Game {
public:
    Game(){}
    ~Game();
    void                    initialize(sf::RenderWindow*);
    void                    loop();
    
private:
    sf::RenderWindow*       window;
    Map                     gameMap;
    TextureManager          textureManager;
    float                   delta;
    GameMode                currentMode;
    std::vector<ObjectPtr>  gameObjects;
    std::vector<MobPtr>     mobs;
    std::vector<GuiPtr>     gameInterface;
    std::vector<GuiPtr>     mainMenu;
    std::vector<Drawable>   drawable;
    Renderer                renderer;
    void                    render();
    void                    physicsAndLogic();
    void                    setUpMenus();
    void                    setUpTexturesAndSprites();
    void                    addMapToDrawable(int order);
    void                    addObjectsToDrawable(int order);
    void                    addGameObjectsToDrawable(int order);
    void                    addMainMenuToDrawable(int order);
    void                    addPauseMenuToDrawable(int order);
    void                    addGameInterfaceToDrawable(int order);
};

#endif	/* GAME_H */

