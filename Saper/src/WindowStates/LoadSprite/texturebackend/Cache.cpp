/*
 * Cache.cpp
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#include "Cache.h"

namespace Texture {

Cache::Cache() {
	// TODO Auto-generated constructor stub

}
void Cache::addTexture(std::string name, sf::Texture temp) {
	TextureCache.insert(std::pair<std::string, sf::Texture>(name, temp));
}
sf::Texture* Cache::getTexture(std::string name) {
	return &TextureCache[name];
}

} /* namespace Texture */
