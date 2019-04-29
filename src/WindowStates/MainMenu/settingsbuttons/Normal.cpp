/*
 * Normal.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "Normal.h"

namespace SettingsButtons {

Normal::Normal(const Graphic::ObjectInterface& settings) :
				Graphic::ObjectInterface(settings) {
	// TODO Auto-generated constructor stub

}

Normal::~Normal() {
	// TODO Auto-generated destructor stub
}
void Normal::setPosition(float x ,float y)
{
	Sprite.setPosition(sf::Vector2f(x,y));
	}
void Normal::updateState(std::string state) {
	if(state == "hover")
	{
	}else if(state == "click")
	{
		click();
	}
}
void Normal::update(){}
} /* namespace SettingsButtons */
