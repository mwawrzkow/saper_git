/*
 * loadlist.h
 *
 *  Created on: Mar 14, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_
#define SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_

#include <memory>
#include <string>
#include <vector>

#include "Object.h"
#include "texturebackend/StateOfClass.h"

namespace Texture {
class Cache;
} /* namespace Texture */

namespace WindowState {

class RenderClass {
	std::shared_ptr<Texture::Cache>Textures;
	std::string ConfigFile;
	ClassStates::state ClassState;
	std::vector<std::string> TexturesLink;
	std::vector<Graphic::Object> toRender;
	const std::vector<std::string>*allowedNames;
public:
	RenderClass(std::string ConfigFile, std::vector<std::string>*allowedNames, std::shared_ptr<Texture::Cache>TextureCache);
	const ClassStates::state getState() const;
	void LoadTextureDirectories();
protected:
	void addTexture(std::string File, std::string textureloc, bool isRepetable,bool isSmooth);
	std::vector<std::string> values(std::string values);
	bool isRepeated(std::string tmp);
	std::string findTextureLoc(std::string tmp);
	std::vector<Graphic::Object>* getQueue();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_LOADLIST_H_ */
