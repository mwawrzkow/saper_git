/*
 * Exit.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "Exit.h"
#include <iostream>
namespace MenuUnits {
Exit::Exit(const Graphic::ObjectInterface& settings,MainMenuRequests::request* req) :
		Graphic::ObjectInterface(settings),req(req) {
	ToggleClicable();
}
void Exit::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
;
void Exit::updateState(std::string state) {
	std::cout << "Click Event" << std::endl;
	if(state == "hover")
	{
		this->state = 1;
	}else if (state == "click")
	{
		this->state = 2;
		req->exit = true;
	}
}
;
void Exit::update() {
}
;
} /* namespace MainMenu */
