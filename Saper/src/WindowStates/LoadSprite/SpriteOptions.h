/*
 * SpriteOptions.h
 *
 *  Created on: 21 mar 2019
 *      Author: Marcin Wawrzków
 *
 * Description: All settings of LoadSprite object
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_
#define SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_
namespace SpriteSettings {

class SpriteOptions {
	const int width;
	const int height;
	const char *name;
	const int frames;
	const int startingPos;
public:
	SpriteOptions(char* name, int width,int height,int startingPos,int frames);
	const int getWidth()const;
	const int getHeight()const;
	const char* getName()const;
	const int getFrameRate()const;
	void frameCheckOut(int &requestedFrame)const;
	const int getStartingPos()const;
};

} /* namespace SpriteSettings */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_ */
