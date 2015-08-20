#include "renderer.h"
#include <iostream>
#include <algorithm>
Renderer::Renderer()
{
    window = NULL;
}
Renderer::Renderer(sf::RenderWindow* wind)
{
    window = wind;
}

void Renderer::drawScene(std::vector<Drawable> toDraw)
{
    if(window != NULL)
    {
        window->clear();
        sortByZ(toDraw);
        for(std::vector<Drawable>::iterator it = toDraw.begin();
                it != toDraw.end();
                ++it)
        {
            window->draw(*(it->sprite));
        }
        window->display();
        toDraw.clear();
    }
    else
    {
        std::cout << "ERROR: Window pointer not initialized in renderer;\n";
    }
}

void Renderer::sortByZ(std::vector<Drawable>& toSort)
{
    int size = toSort.size();
    int i,j;
    for(i = 0; i < size; i++)
    {
        for(j=0; j< size - i - 1; j++)
        {
            if(toSort[j].z > toSort[j+1].z)
            {
                Drawable temp = toSort[j];
                toSort[j] = toSort[j+1];
                toSort[j+1] = temp;
            }
        }
    }
}