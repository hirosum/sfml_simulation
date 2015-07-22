/* 
 * File:   textures.h
 * Author: hirosum
 *
 * Created on 22 July 2015, 13:51
 */

#ifndef TEXTURES_H
#define	TEXTURES_H
#include <SFML/Graphics.hpp>
class TextureManager {
public:
    TextureManager();
    ~TextureManager();
    const sf::Texture& getTexture(const std::string& filename);
    void deleteTexture(const sf::Texture& texture);
    void deleteTexture(const std::string& filename);
    void addResourceDirectory(const std::string& directory);
    void removeResourceDirectory(const std::string& directory);
private:
    TextureManager(TextureManager const&);
    void operator=(TextureManager const&);
    void setUpTextures();
    std::map< std::string, sf::Texture > textures;
    std::vector< std::string > resourceDirectories;
};


#endif	/* TEXTURES_H */

