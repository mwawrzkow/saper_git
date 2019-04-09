/*
 * MSSFMLView.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: marcin
 */

#include "MSSFMLView.h"
namespace Graphic {
MS_SFML_View::MS_SFML_View(sf::RenderWindow &ptr, IO::FileManager &settings, std::string gamedir)
:		gamedir(gamedir),
		settings(settings),
		GameWindow(ptr),
		WindowState(GameState::State::MainMenu),
		GameMenu(gamedir+settings.LoadFileInformation(IO::Information::MENU_FILE_LIST).value,TextureCache)
{
	start();
}

void MS_SFML_View::start() {
	GameMenu.start();
	while (GameWindow.isOpen()) {
		stateOfView();
	}

}

void MS_SFML_View::stateOfView(){
	switch(WindowState){
	case GameState::State::MainMenu:

		break;
	case GameState::State::LoadingScreen:

		break;
	case GameState::State::InGameMenu:

		break;
	case GameState::State::Game:

		break;
	}
}
}
