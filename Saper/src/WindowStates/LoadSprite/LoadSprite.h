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

#ifndef SRC_WINDOWSTATES_LOADSPRITE_LOADSPRITE_H_
#define SRC_WINDOWSTATES_LOADSPRITE_LOADSPRITE_H_
#include "SpriteOptions.h"
#include "TextureLoad.h"
#include "StateOfClass.h"
namespace Graphic {

class LoadSprite {
protected:
	sf::Sprite Sprite;
	SpriteSettings::SpriteOptions Settings;
	SpriteSettings::TextureLoad Texture;
private:
	int frame = 0;
	const char* SpriteLoc;
public:
	LoadSprite(char* TextureLoc, char* name, int width, int height,int startingPos, int frames, bool isSmooth, bool isRepetable);
	LoadSprite(sf::Texture &ref,char* name, int width, int height, int startingPos, int frames);
	void createSprite();
	void spriteUpdate();
	const sf::Sprite& returnSprite();
protected:
	const sf::Texture &getSharedTexture()const;
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_LOADSPRITE_H_ */
