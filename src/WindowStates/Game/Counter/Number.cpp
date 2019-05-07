/*
 * number.cpp
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#include "Number.h"

namespace Digit {

Number::Number(const Graphic::ObjectInterface& tmp) :
		Graphic::ObjectInterface(tmp) {
	// TODO Auto-generated constructor stub

}
Number::~Number() {
}
void Number::setPosition(float x, float y) {
	Sprite.setPosition(sf::Vector2f(x, y));
}
void Number::updateState(std::string state) {
	if (state == "0")
		this->state = 0;
	if (state == "1")
		this->state = 1;
	if (state == "2")
		this->state = 2;
	if (state == "3")
		this->state = 3;
	if (state == "4")
		this->state = 4;
	if (state == "5")
		this->state = 5;
	if (state == "6")
		this->state = 6;
	if (state == "7")
		this->state = 7;
	if (state == "8")
		this->state = 8;
	if (state == "9")
		this->state = 9;
}
void Number::update() {
}
} /* namespace MinesCount */
