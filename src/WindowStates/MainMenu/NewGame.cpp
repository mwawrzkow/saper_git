/*
 * NewGame.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "NewGame.h"
#include <iostream>
namespace MenuUnits {
NewGame::NewGame(const Graphic::ObjectInterface& settings) :
		Buttons(settings) {
	ToggleClicable();
}

void NewGame::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
void NewGame::updateState(std::string state) {
	std::cout << "Click Event" << std::endl;
	if (state == "hover") {
		this->state = 1;
	} else if (state == "click") {
		this->state = 2;
		click();
	}

}
void NewGame::update() {
	spriteUpdate();
}
;
} /* namespace MainMenu */
