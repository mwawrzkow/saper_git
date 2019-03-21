/*
 * TextureLoad.cpp
 *
 *  Created on: 20 mar 2019
 *      Author: marcin
 */

#include "TextureLoad.h"

namespace SpriteSettings {

TextureLoad::TextureLoad(std::string location,bool isSmooth, bool isRepetable) :
		location(location) {
	Texture.loadFromFile(location);
	Texture.setSmooth(isSmooth);
	Texture.setRepeated(isRepetable);

}
const sf::Texture &TextureLoad::ReturnTexture()const{
	return Texture;
}

const char* TextureLoad::getLocation()const{
	return location.c_str();
}

} /* namespace Graphic */
