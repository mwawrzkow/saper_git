/*
 * Hard.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "Hard.h"

namespace SettingsButtons {

Hard::Hard(const Graphic::ObjectInterface& settings) :
						Graphic::ObjectInterface(settings) {
	// TODO Auto-generated constructor stub

}

Hard::~Hard() {
	// TODO Auto-generated destructor stub
}
void Hard::setPosition(float x ,float y)
{
	Sprite.setPosition(sf::Vector2f(x,y));
	}
void Hard::updateState(std::string state) {
	if(state == "click")
		click();
}
void Hard::update(){}
} /* namespace SettingsButtons */
