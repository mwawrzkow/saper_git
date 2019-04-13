/*
 * LoadSprite.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcin Wawrzków
 *
 *
 * Description: LoadSprite Class:
 *                         * Holds sf::SpriteObject.
 *              Functionality:
 *                         * Update Sprite frame by frame.
 *                         * Allows to return sprite by reference to render.
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_
#define SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include "ClickEvent.h"
#include "texturebackend/SpriteOptions.h"


namespace Graphic {

class Object {
protected:
	sf::Sprite Sprite;
	sf::Texture *Texture;
	std::vector<SpriteSettings::SpriteOptions>states;
	ObjectSettings::Click clicable;
private:
	int state = 0;
	int frame = 0;
public:
	Object(sf::Texture *ref,const char* name, int width, int height, int startingPos, int frames);
	Object();
	void createSprite();
	void spriteUpdate();
	const ObjectSettings::Click* getClicable();
	const sf::Sprite& returnSprite();
	void addState(std::string name, int startingpos, int frames);
	void updateState(std::string name);
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_ */
