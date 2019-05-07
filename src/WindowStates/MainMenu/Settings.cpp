/*
 * settings.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "Settings.h"

#include <iostream>
namespace MenuUnits {

Settings::Settings(const Graphic::ObjectInterface& settings, MainMenuRequests::request* req) : // @suppress("Class members should be properly initialized")
		Buttons(settings),req(req){
	// TODO Auto-generated constructor stub

}
void Settings::setPosition(float x, float y) {
	Graphic::ObjectInterface::createSprite();
	easy->createSprite();
	easy->setPosition(50+x,50+y);
	easy->ToggleClicable();
	normal->createSprite();
	normal->setPosition(300+x,50+y);
	normal->ToggleClicable();
	hard->createSprite();
	hard->setPosition(550+x,50+y);
	hard->ToggleClicable();
	Sprite.setPosition(sf::Vector2f(x, y));



}
void Settings::updateState(std::string state) {}
void Settings::update() {
	spriteUpdate();
	if(easy->checkClick())
		req->newgamereq = GameLogic::GameMode::EASY;
	if(normal->checkClick())
		req->newgamereq = GameLogic::GameMode::NORMAL;
	if(hard->checkClick())
		req->newgamereq = GameLogic::GameMode::HARD;

}

/*
 *
	void SetEasy(const Graphic::ObjectInterface&);
	void SetNormal(const Graphic::ObjectInterface&);
	void setHard(const Graphic::ObjectInterface&);
 */
void Settings::SetEasy(const Graphic::ObjectInterface& easy){
this->easy = new SettingsButtons::Easy(easy);
}
void Settings::SetNormal(const Graphic::ObjectInterface& normal){
	this->normal = new SettingsButtons::Normal(normal);

}
void Settings::setHard(const Graphic::ObjectInterface& hard){
	this->hard = new SettingsButtons::Hard(hard);

}
Graphic::ObjectInterface* Settings::getEasy(){return easy;}
Graphic::ObjectInterface* Settings::getNormal(){return normal;}
Graphic::ObjectInterface* Settings::getHard(){return hard;}
void Settings::toggleVisible(){
	ObjectInterface::toggleVisible();
	easy->toggleVisible();
	normal->toggleVisible();
	hard->toggleVisible();
	std::cout << "Checking Visibility status:" << std::endl
			<< "Menu:" << ObjectInterface::isVisible() << std::endl
			<< "Easy:" << easy->isVisible() << std::endl
			<< "Normal:" << normal->isVisible() << std::endl
			<< "Hard:" << hard->isVisible() << std::endl;
}
} /* namespace Graphic */
