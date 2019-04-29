/*
 * BackGround.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "Background.h"

namespace MenuUnits {
backGround::backGround(const Graphic::ObjectInterface& settings):Graphic::ObjectInterface(settings){}
void backGround::setPosition(float x, float y){
Sprite.setPosition(sf::Vector2f(x,y));
}
void backGround::updateState(std::string State){

}
void backGround::update(){

}

} /* namespace MainMenu */
