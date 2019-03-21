/*
 * loadlist.h
 *
 *  Created on: Mar 14, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_
#define SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_

#include <string>
#include <vector>

#include "LoadSprite.h"
#include "StateOfClass.h"

namespace WindowState {

class RenderClass {
	std::string ConfigFile;
	ClassStates::state ClassState;
	std::vector<std::string> TexturesLink;
	std::vector<Graphic::LoadSprite> toRender;
	const std::vector<std::string>&allowedNames;
public:
	RenderClass(std::string ConfigFile, std::vector<std::string>&allowedNames);
	const ClassStates::state getState() const;
	void LoadTextureDirectories();
protected:
	std::vector<std::string> values(std::string values);
	bool isRepeated(std::string tmp);

	void createSprite(char* TextureLoc, char* name, int width, int height,
			int startingPos, int frames, bool isSmooth, bool isRepetable);
	void createSprite(sf::Texture &ref, char* name, int width, int height,
			int startingPos, int frames);
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_ */
