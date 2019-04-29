/*
 * MSSFMLView.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: marcin
 */

#include "MSSFMLView.h"
#include "WindowStates/LoadSprite/texturebackend/Cache.h"
namespace Graphic {
MS_SFML_View::MS_SFML_View(Graphic::Render &window, IO::FileManager &settings,
		std::string gamedir) :
		Cache(new Texture::Cache), TextureCache(Cache), window(window), gamedir(
				gamedir), settings(settings), WindowState(
				GameState::State::MainMenu) {
	createGameStates();
	Event.setWindow(window.getWindow());
	start();
}
void MS_SFML_View::createGameStates() {
	WindowState::MainMenu *GameMenu;
	GameMenu = new WindowState::MainMenu(
			gamedir
					+ settings.LoadFileInformation(
							IO::Information::MENU_FILE_LIST).value,
			TextureCache, &isAskingForChange);
	states.push_back(GameMenu);
	WindowState::Game *game;
	game = new WindowState::Game(
			gamedir
					+ settings.LoadFileInformation(
							IO::Information::GAME_FILE_LIST).value,
			TextureCache, &isAskingForChange);
	states.push_back(game);

}

void MS_SFML_View::start() {
	stateHasChanged = true;
	sf::Clock timer;
	while (window.window.isOpen()) {
		if (stateHasChanged)
			stateOfView();
		if (!doesRenderThreadWork) {
			try {
				//Display.start(window);
				doesRenderThreadWork = true;
			} catch (Poco::Exception &e) {
				std::cout << e.message() << std::endl;
			}
		}
		window.runThreadSafe();
		states[WindowState]->update();
		Event.EventChecker();
		if (isAskingForChange)
		{
			WindowState = states[WindowState]->AskedState();
			stateHasChanged = true;
			isAskingForChange = false;
		}
	}

}

void MS_SFML_View::stateOfView() {
	if(WindowState == 1)
	{
		states.at(WindowState)->start(*states.at(0)->askedGameMode());
	}
	window.renderQueue(*states.at(WindowState)->getUnits());
	Event.setObjects(states.at(WindowState));
	stateHasChanged = false;
}
MS_SFML_View::~MS_SFML_View() {
	Display.~Thread();
}
}
