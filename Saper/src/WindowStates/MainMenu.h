/*
 * MainMenu.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcin Wawrzków
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
	// List of Nessesary objectes
	std::vector<std::string>availibeNames = {"START","OPTIONS","EXIT"};

private:
	//Clas that contains all Sprites
	RenderClass Graphic;
	//values for Mainmenu Substates
	enum State { NONE,NEWGAME, OPTIONS,EXIT } state;
	//Thread queue
	std::vector<std::thread>threadqueue;
	//Render queue
	std::vector<sf::Sprite>render;
public:
	/*MenuConstructor.
	 *Requies directory where it tries to open config.conf file
	 */
	MainMenu(std::string MenuFileList);
	/*
	 * Base function that will load all Graphic into GPU
	 */
	void start();
	/*
	 * Render queue for MSSFML
	 */
	std::vector<sf::Sprite>queue();
private:
	void FileList();
	void LoadFiles();
	void LoadSprites();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_MAINMENU_H_ */
