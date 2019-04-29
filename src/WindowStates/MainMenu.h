/*
 * MainMenu.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcin Wawrzk��w
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_H_
#define SRC_WINDOWSTATES_MAINMENU_H_

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "MainMenu/Background.h"
#include "MainMenu/Exit.h"
#include "MainMenu/NewGame.h"
#include "MainMenu/Options.h"
#include "MainMenu/Settings.h"
#include "State.h"
namespace WindowState{


class MainMenu: public Controller::State{
public:
	// List of Nessesary objectes

private:
	//Clas that contains all Sprites
	//values for Mainmenu Substates
	enum States { NONE,NEWGAME, OPTIONS,EXIT } state ;
	MenuUnits::backGround *background;
	MenuUnits::Options *options;
	MenuUnits::NewGame *newgame;
	MenuUnits::Exit *exit;
	MenuUnits::Settings *settings;
	MainMenuRequests::request PlayerRequest;
	void CreateUnits();
	public:
	/*MenuConstructor.
	 *Requies directory where it tries to open config.conf file
	 */
	MainMenu(std::string,std::shared_ptr<Texture::Cache>TextureCache, bool*);
	/*
	 * Base function that will load all Graphic into GPU
	 */
	/*
	 * Render queue for MSSFML
	 */
	virtual GameLogic::GameMode* askedGameMode() override;
	MainMenuRequests::request* getRequest();
private:
	void setUnits() override;
	virtual void update() override;
	virtual void start(GameLogic::GameMode &)override;
	~MainMenu();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_MAINMENU_H_ */
