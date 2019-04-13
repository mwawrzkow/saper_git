/*
 * RenderClass.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: marcin
 */

#include "RenderClass.h"
#include "texturebackend/Cache.h"
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <Poco/NumberParser.h>
#include <Poco/String.h>
namespace WindowState {

RenderClass::RenderClass(std::string ConfigFile,
		std::vector<std::string>*allowedNames,
		std::shared_ptr<Texture::Cache> TextureCache) :
		ConfigFile(ConfigFile), allowedNames(allowedNames), Textures(
				TextureCache) {

}

void RenderClass::LoadTextureDirectories() {
	std::ifstream file(ConfigFile);
	std::cout << "starting reading the file" << std::endl << "from:"
			<< ConfigFile << std::endl;
	if (file.good()) {
		//	std::cout << "File has been opened!"<< std::endl;
	} else {
		std::cout << "File can't be open" << std::endl;
	}
	std::string line;
	ConfigFile.erase(ConfigFile.end() - 11, ConfigFile.end());
	while (std::getline(file, line)) {
		std::vector<std::string> tokens = values(line);
		if (isRepeated(ConfigFile + tokens[0])) {
			Graphic::Object tmp;
			int states = 0 ;
			for (int i = states; i > 0; --i) {
				std::getline(file, line);
				tokens = values(line);
				//tmp.addState(tokens[0], Poco::NumberParser::parse(tokens[3]),
				//		Poco::NumberParser::parse(tokens[4]));
				Graphic::Object ttmp;

			}
			toRender.push_back(tmp);
		} else {
			// Add Texture::Cache Implementation

			int states = Poco::NumberParser::parse(tokens[8]);
			Graphic::Object sprite;
			for (int i = states; i > 0; --i) {
				std::getline(file, line);
				//sprite.addState(tokens[0], Poco::NumberParser::parse(tokens[3]),
				//	Poco::NumberParser::parse(tokens[4]));

			}
			toRender.push_back(sprite);
		}
		TexturesLink.push_back(ConfigFile + line);
	}
	file.close();
	ClassState.isListLoaded = true;

}
bool RenderClass::isRepeated(std::string tmp) {
	if (Textures->getTexture(tmp) != NULL)
		return true;
	return false;

}

std::string RenderClass::findTextureLoc(std::string tmp) {
	for (std::string temp : TexturesLink)
		if (Poco::icompare(tmp, temp) == 0)
			return temp;
	return tmp;
}

std::vector<std::string> RenderClass::values(std::string line) {
	std::vector<std::string> tmp;
	std::regex world_regex("(\\S+)");
	auto words_begin = std::sregex_iterator(line.begin(), line.end(),
			world_regex);
	auto words_end = std::sregex_iterator();
	int c = 0;
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		tmp.push_back(match_str);
		c++;
	}
	return tmp;

}

void RenderClass::addTexture(std::string File, std::string textureloc,
		bool isRepeated, bool isSmooth) {
	sf::Texture myPoorTexture;
	myPoorTexture.loadFromFile(textureloc);
	myPoorTexture.setRepeated(isRepeated);
	myPoorTexture.setSmooth(isSmooth);
	Textures->addTexture(File, myPoorTexture);
}

const ClassStates::state RenderClass::getState() const {
	return ClassState;
}
std::vector<Graphic::Object>* RenderClass::getQueue() {
	return &toRender;
}
} /* namespace WindowState */
