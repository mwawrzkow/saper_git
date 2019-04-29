/*
 * Tile.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "Tile.h"
#include <iostream>
#include <math.h>
namespace GameUnits {

Tile::Tile(const Graphic::ObjectInterface& settings, int x, int y) :
		Graphic::ObjectInterface(settings), x(x), y(y) {
	// TODO Auto-generated constructor stub

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}
void Tile::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
;
void Tile::updateState(std::string state) {
	if (state == "default") {
		this->state = 0;
	} else if (state == "click") {
		this->states.at(this->state).changed();
		click();
	} else if (state == "rclick") {
		this->states.at(this->state).changed();
		rclick();
	} else if (state == "mine") {
		this->state = 11;
	} else if (state == "flag") {
		this->state = 2;
	} else if (state == "revealed") {
		this->state = 1;
	} else if (state == "nearmines1") {
		this->state = 3;
	} else if (state == "nearmines2") {
		this->state = 4;
	} else if (state == "nearmines3") {
		this->state = 5;
	} else if (state == "nearmines4") {
		this->state = 6;
	} else if (state == "nearmines5") {
		this->state = 7;
	} else if (state == "nearmines6") {
		this->state = 8;
	} else if (state == "nearmines7") {
		this->state = 9;
	} else if (state == "nearmines8") {
		this->state = 10;
	}
}
void Tile::scale(float scaleamount) {
	for (SpriteSettings::SpriteOptions &e : states) {
		e.scale(scaleamount);
	}
	Sprite.setScale(sf::Vector2f(scaleamount, scaleamount));
}
void Tile::update() {
}
const int Tile::getX() const {
	return x;
}
const int Tile::getY() const {
	return y;
}
} /* namespace GameUnits */
