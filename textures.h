/* 
 * File:   textures.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 13:51
 */

#ifndef TEXTURES_H
#define	TEXTURES_H
#include <SFML/Graphics.hpp>
class TextureHandler {
public:
    TextureHandler();
    ~TextureHandler();
    const sf::Texture& getTexture(const std::string& filename);
    void deleteTexture(const sf::Texture& texture);
    void deleteTexture(const std::string& filename);
private:
    TextureHandler(TextureHandler const&);
    void operator=(TextureHandler const&);
    void setUpTextures();
    std::map< std::string, sd::Texture > textures;
}


#endif	/* TEXTURES_H */

