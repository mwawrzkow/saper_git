/*
 * Easy.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "Easy.h"

namespace SettingsButtons {

Easy::Easy(const Graphic::ObjectInterface& settings) :
		Graphic::ObjectInterface(settings) {
	// TODO Auto-generated constructor stub

}

Easy::~Easy() {
	// TODO Auto-generated destructor stub
}
void Easy::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
void Easy::updateState(std::string state) {
	if (state == "click")
		click();
}
void Easy::update() {
}
} /* namespace SettingsButtons */
