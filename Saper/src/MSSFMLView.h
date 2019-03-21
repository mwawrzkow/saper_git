/*
 * MSSFMLView.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Frontend Class for Minesweeper
 */

#ifndef SRC_MSSFMLVIEW_H_
#define SRC_MSSFMLVIEW_H_


//Including SFML Libraries
#include <SFML/Graphics.hpp>

//GameEngine
#include "MinesweeperBoard/MSBoardTextView.h"

//Input Module
#include "MSBoardInput.h"

//GameStates Modules
#include "WindowStates/WindowStates.h"
#include "WindowStates/Game.h"
#include "WindowStates/InGameMenu.h"
#include "WindowStates/LoadingScreen.h"
#include "WindowStates/MainMenu.h"



namespace Graphic{
class MS_SFML_View{
	/*
	 * Main Game Window
	 */
	IO::FileManager &settings;
	sf::RenderWindow &GameWindow;
	//Game Graphic objects
	GameState::State WindowState;
	WindowState::Game Playing;
	WindowState::InGameMenu MenuWhilePlaying;
	WindowState::LoadingScreen Loading;
	WindowState::MainMenu Menu;


	/*
	 * Important Const
	 */
	const std::string gamedir;
public:
	MS_SFML_View(sf::RenderWindow &ptr,IO::FileManager &settings,std::string gamedir);
	void start();
private:
	void stateOfView();
	void event();
	void update();

};
}
#endif /* SRC_MSSFMLVIEW_H_ */
