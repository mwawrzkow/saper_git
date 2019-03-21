/*
 * TextureLoad.h
 *
 *  Created on: 20 mar 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_
#define SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_
#include <string>
#include <SFML/Graphics.hpp>
namespace SpriteSettings {

class TextureLoad {
	const std::string location;
	sf::Texture Texture;
public:
	TextureLoad(std::string location, bool isSmooth, bool isRepetable);
	const sf::Texture &ReturnTexture()const;
	const char* getLocation()const;
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_ */
