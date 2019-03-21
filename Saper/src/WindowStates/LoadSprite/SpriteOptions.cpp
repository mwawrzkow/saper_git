/*
 * SpriteOptions.cpp
 *
 *  Created on: 21 mar 2019
 *      Author: marcin
 */

#include "SpriteOptions.h"

namespace SpriteSettings {

SpriteOptions::SpriteOptions(char* name, int width, int height,int startingPos, int frames) :
		name(name), width(width), height(height),startingPos(startingPos), frames(frames) {
}
const int SpriteOptions::getWidth() const {
	return width;
}
const int SpriteOptions::getHeight() const {
	return height;
}
const char* SpriteOptions::getName() const {
	return name;
}
const int SpriteOptions::getFrameRate() const {
	return frames;
}
void SpriteOptions::frameCheckOut(int &requestedFrame)const
{
if(requestedFrame > frames)
	requestedFrame = 0;
}
const int SpriteOptions::getStartingPos()const{
	return startingPos;
}
} /* namespace SpriteSettings */
