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


#include "texturebackend/SpriteOptions.h"
#include "texturebackend/TextureLoad.h"

namespace Graphic {

class Object {
protected:
	sf::Sprite Sprite;
	const SpriteSettings::TextureLoad Texture;
	std::vector<SpriteSettings::SpriteOptions>states;
private:
	int state = 0;
	int frame = 0;
public:
	Object(const char* TextureLoc,const char* name, int width, int height,int startingPos, int frames, bool isSmooth, bool isRepetable);
	Object(const SpriteSettings::TextureLoad &ref,const char* name, int width, int height, int startingPos, int frames);
	void createSprite();
	void spriteUpdate();
	const sf::Sprite& returnSprite();
	const SpriteSettings::TextureLoad &getSharedTexture()const;
	void addState(std::string name, int startingpos, int frames);
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_ */
