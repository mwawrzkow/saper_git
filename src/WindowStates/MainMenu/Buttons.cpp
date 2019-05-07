/*
 * buttons.cpp
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#include "Buttons.h"

namespace MainMenuButtons {

Buttons::Buttons(const Graphic::ObjectInterface& tmp):Graphic::ObjectInterface(tmp) {
	// TODO Auto-generated constructor stub

}
void Buttons::spriteUpdate(){
	sf::Time timeTick = sf::seconds(0.5);
	if(elapsedTime.getElapsedTime()>=timeTick){
		this->resetState();
		elapsedTime.restart();
	}
	Graphic::ObjectInterface::spriteUpdate();
}

} /* namespace MainMenuButtons */
