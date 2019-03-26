/*
 * Cache.h
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_
#define SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_

#include <SFML/Graphics/Texture.hpp>
#include <map>

namespace Texture {

class Cache {
	std::map<sf::Texture>TexturesCache;
public:
	Cache();
};

} /* namespace Texture */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_ */
