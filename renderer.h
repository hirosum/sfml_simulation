/* 
 * File:   renderer.h
 * Author: hirosum
 *
 * Created on 14 August 2015, 14:13
 */
#ifndef SMFL
#define SMFL

#include <SFML/Graphics.hpp>

#endif
#ifndef RENDERER_H
#define	RENDERER_H
struct Drawable
{
    sf::Sprite*     sprite;
    int             z;
};
class Renderer
{
public:
    Renderer();
    Renderer(sf::RenderWindow* wind);
    void drawScene(std::vector<Drawable> toDraw);
private:
    sf::RenderWindow*  window;
    void sortByZ(std::vector<Drawable>& toSort);
};


#endif	/* RENDERER_H */

