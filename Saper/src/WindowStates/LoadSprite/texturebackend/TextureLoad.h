/*
 * TextureLoad.h
 *
 *  Created on: 20 mar 2019
 *      Author: Marcin Wawrzków
 *
 * Description: Base Class that holds single Texture, and it's location
 *              Used for loading multiple sprites from single Texture.
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_
#define SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_
#include <string>
#include <SFML/Graphics.hpp>
namespace SpriteSettings {

class TextureLoad {
	//Location of Texture
	const std::string location;
	//Texture
	sf::Texture Texture;
public:
	//TextureLoad needs basic information for sf::Texture constructor.
	TextureLoad(std::string location, bool isSmooth, bool isRepetable);
	const sf::Texture &getTexture() const;
	const char* getLocation() const;
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_TEXTURELOAD_H_ */
