/*
 * RenderClass.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: marcin
 */

#include "RenderClass.h"

#include <Poco/String.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>

namespace WindowState {

RenderClass::RenderClass(std::string ConfigFile,
		std::vector<std::string>&allowedNames) :
		ConfigFile(ConfigFile), allowedNames(allowedNames) {

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
		std::vector<std::string> value = values(line);
		if (isRepeated(ConfigFile + value[3])) {

		} else {

		}
		TexturesLink.push_back(ConfigFile + line);
	}
	file.close();
	ClassState.isListLoaded = true;

}
bool RenderClass::isRepeated(std::string tmp) {
	for (std::string temp : TexturesLink)
		if (Poco::icompare(temp, tmp) == 0)
			return false;
	return true;

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
		if (c == 5)
			break;
		tmp.push_back(match_str);
		c++;
	}
	return tmp;

}

void RenderClass::createSprite(char* TextureLoc, char* name, int width, int height,
		int startingPos, int frames, bool isSmooth, bool isRepetable){
	Graphic::LoadSprite tmp(TextureLoc,name,width,height,startingPos,frames,isSmooth,isRepetable);
	toRender.push_back(tmp);
}
void RenderClass::createSprite(sf::Texture &ref, char* name, int width, int height,
		int startingPos, int frames){
	Graphic::LoadSprite tmp(ref,name,width,height,startingPos,frames);
}

const ClassStates::state RenderClass::getState() const {
	return ClassState;
}

} /* namespace WindowState */
