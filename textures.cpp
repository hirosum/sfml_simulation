
#include <iostream>
#include "textures.h"

const sf::Texture& TextureHandler::getTexture(const std::string& filename)
{
    for( std::map<std::string, sf::Texture>::const_iterator it = textures.begin();
    it != textures.end();
    ++it)
    {
        if(filename == it->first)
        {
            std::cout << "DEBUG_MESSAGE: using existing image.\n";
            return it->second;
        }
    }
    
    sf::Texture texture;
    if(texture.loadFromFile(filename))
    {
        textures[filename] = texture;
        std::cout << "DEBUG_MESSAGE: loading image.\n";
        return textures[filename];
    }
    
    std::cout << "GAME_ERROR: Image was not found. It is filled with an empty image.\n";
    textures[filename] = texture;
    return textures[filename];
}

void TextureHandler::deleteTexture(const sf::Texture& texture)
{
    for(std::map<std::string, sf::Texture>::const_iterator it = textures.begin();
            it != textures.end();
            ++it)
    {
        if(&texture == &it->second)
        {
            textures.erase(it);
            return;
        }
    }
}

void TextureHandler::deleteTexture(const std::string& filename)
{
    std::map<std::string, sf::Texture>::const_iterator it = textures.find(filename);
    if(it != textures.end())
        textures.erase(it);
}

    


