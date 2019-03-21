/*
 * MainMenu.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_H_
#define SRC_WINDOWSTATES_MAINMENU_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <regex>

#include "FileIO/FileManager.h"
#include "LoadSprite/LoadSprite.h"
#include "LoadSprite/RenderClass.h"
#include "MainMenu/Background.h"
#include "MainMenu/Exit.h"
#include "MainMenu/NewGame.h"
#include "MainMenu/Options.h"
#include "LoadSprite/StateOfClass.h"
namespace WindowState {



class MainMenu{
public:

	std::vector<std::string>availibeNames = {"START","OPTIONS","EXIT"};

private:
	RenderClass Graphic;
	enum State { NONE,NEWGAME, OPTIONS,EXIT } state;
	std::vector<std::thread>threadqueue;
	std::vector<sf::Sprite>render;
public:
	MainMenu(std::string MenuFileList);
	void start();
	std::vector<sf::Sprite>queue();
private:
	void FileList();
	void LoadFiles();
	void LoadSprites();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_MAINMENU_H_ */
