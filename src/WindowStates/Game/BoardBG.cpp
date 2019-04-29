/*
 * BoardBG.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "BoardBG.h"
#include <iostream>
namespace GameUnits {

BoardBG::BoardBG(const Graphic::ObjectInterface& settings):Graphic::ObjectInterface(settings) {
	// TODO Auto-generated constructor stub

}

BoardBG::~BoardBG() {
	// TODO Auto-generated destructor stub
}
void BoardBG::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
;
void BoardBG::updateState(std::string state) {
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
void BoardBG::update() {
}

} /* namespace GameUnits */
