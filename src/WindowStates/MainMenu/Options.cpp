/*
 * Options.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "Options.h"
#include <iostream>
namespace MenuUnits {

Options::Options(const Graphic::ObjectInterface& settings) :
		Buttons(settings) {
	ToggleClicable();
}
void Options::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
;
void Options::updateState(std::string state) {
	std::cout << "Click Event" << std::endl;
	if(state == "hover")
	{
		this->state = 1;
	}else if (state == "click")
	{
		this->state = 2;
	}
}
;
void Options::update() {
	spriteUpdate();

}
} /* namespace MainMenu */
