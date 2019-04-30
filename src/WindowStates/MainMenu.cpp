/*
 * MainMenu.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "MainMenu.h"

#include "LoadSprite/texturebackend/Cache.h"

namespace WindowState {

void MainMenu::CreateUnits() {
	std::cout << "Finding dependences." << std::endl;
	std::cout << "Availibe units: " << Render.getQueue().size() << std::endl;
	for (int i = 0; i < Render.getQueue().size(); i++) {
		if (Render.getQueue().at(i)->getName() == availibeNames[0]) {
			std::cout << "Found Background." << std::endl;
			background = new MenuUnits::backGround(*Render.getQueue().at(i));
			Units.push_back(background);
		} else if (Render.getQueue().at(i)->getName() == availibeNames[1]) {
			std::cout << "Found NewGame Button." << std::endl;
			newgame = new MenuUnits::NewGame(*Render.getQueue().at(i));
			Units.push_back(newgame);
		} else if (Render.getQueue().at(i)->getName() == availibeNames[2]) {
			std::cout << "Found Options Button." << std::endl;
			options = new MenuUnits::Options(*Render.getQueue().at(i));
			Units.push_back(options);
		} else if (Render.getQueue().at(i)->getName() == availibeNames[3]) {
			std::cout << "Found Exit Button." << std::endl;
			exit = new MenuUnits::Exit(*Render.getQueue().at(i),&PlayerRequest);
			Units.push_back(exit);
		} else if (Render.getQueue().at(i)->getName() == availibeNames[4]) {
			std::cout << "Found  Settings menu" << std::endl;
			settings = new MenuUnits::Settings(*Render.getQueue().at(i),&PlayerRequest);
			Units.push_back(settings);

		} else if (Render.getQueue().at(i)->getName() == availibeNames[5]) {
			std::cout << "Found  EASY-Settings menu" << std::endl;
			settings->SetEasy(*Render.getQueue().at(i));
			Units.push_back(settings->getEasy());

		} else if (Render.getQueue().at(i)->getName() == availibeNames[6]) {
			std::cout << "Found  NORMAL-Settings menu" << std::endl;
			settings->SetNormal(*Render.getQueue().at(i));
			Units.push_back(settings->getNormal());

		} else if (Render.getQueue().at(i)->getName() == availibeNames[7]) {
			std::cout << "Found  HARD-Settings menu" << std::endl;
			settings->setHard(*Render.getQueue().at(i));
			Units.push_back(settings->getHard());

		}
	}
	settings->toggleVisible();
	//std::reverse(std::begin(render),std::end(render));
}
MainMenu::MainMenu(std::string FileList, // @suppress("Class members should be properly initialized")
		std::shared_ptr<Texture::Cache> TextureCache,bool *sendRequest) :State(FileList,TextureCache,sendRequest),
		state(States::NONE) {
	StateAdd("BACKGROUND");
	StateAdd("START");
	StateAdd("OPTIONS");
	StateAdd("EXIT");
	StateAdd("SETTINGS");
	StateAdd("EASY");
	StateAdd("NORMAL");
	StateAdd("HARD");
	State::start();

}
void MainMenu::start(GameLogic::GameMode &){}

void MainMenu::setUnits() {
	background->setPosition(0, 0);
	newgame->setPosition(1000, 100);
	options->setPosition(1000, 250);
	exit->setPosition(1000, 400);
	background->createSprite();
	newgame->createSprite();
	options->createSprite();
	exit->createSprite();
}

void MainMenu::update() {
	State::update();
	settings->update();
	if (newgame->checkClick()) {
		settings->toggleVisible();
		newgame->resetClick();
		newgame->ToggleClicable();
		settings->setPosition(100,200);
	}
	if(PlayerRequest.exit)
	{
		*sendRequest = !*sendRequest;
		askState = GameState::Exit;
	}
	if(PlayerRequest.newgamereq != GameLogic::DEBUG)
	{
		*sendRequest = !*sendRequest;
		askState = GameState::Game;
	}
}
GameLogic::GameMode* MainMenu::askedGameMode(){
return &PlayerRequest.newgamereq;
}
/*
 * 	void start();
 std::vector<sf::Sprite>&queue();
 private:
 void FileList();
 void LoadFiles();
 void LoadSprites();
 void update();
 ~MainMenu();
 void start();
 */
MainMenu::~MainMenu() {
}
MainMenuRequests::request* MainMenu::getRequest()
{
	return &PlayerRequest;
}
} /* namespace WindowState */
