/*
 * LoadSprite.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "LoadSprite.h"

namespace Graphic {

LoadSprite::LoadSprite(char* TextureLoc, char* name, int width, int height,
		int startingPos, int frames, bool isSmooth,
		bool isRepetable) :
		Texture(TextureLoc, isSmooth, isRepetable), SpriteLoc(SpriteLoc), Settings(
				name, width, startingPos, height, frames) {}
LoadSprite::LoadSprite(sf::Texture &ref,char* name, int width, int height, int startingPos, int frames) :
		Texture(Texture), Settings(name, width, startingPos, height, frames) {}
void LoadSprite::createSprite() {
	Sprite.setTexture(Texture.ReturnTexture());
	Sprite.setTextureRect(
			sf::IntRect(0, 0, Settings.getWidth(), Settings.getHeight()));
}
void LoadSprite::spriteUpdate() {
	Settings.frameCheckOut(frame);
	int update = frame + 1;
	Settings.frameCheckOut(update);
	Sprite.setTextureRect(
			sf::IntRect(Settings.getWidth() * frame, Settings.getStartingPos(),
					Settings.getWidth() * update, Settings.getHeight()));

}
const sf::Sprite& LoadSprite::returnSprite() {
	return Sprite;
}

const sf::Texture& LoadSprite::getSharedTexture() const {
	return Texture.ReturnTexture();
}
} /* namespace Graphic */
