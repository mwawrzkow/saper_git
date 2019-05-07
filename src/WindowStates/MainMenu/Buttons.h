/*
 * buttons.h
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_BUTTONS_H_
#define SRC_WINDOWSTATES_MAINMENU_BUTTONS_H_
#include "../LoadSprite/ObjectInterface.h"

namespace MainMenuButtons {

class Buttons: public Graphic::ObjectInterface{
public:
	Buttons(const Graphic::ObjectInterface&);
	virtual void spriteUpdate();
};

} /* namespace MainMenuButtons */

#endif /* SRC_WINDOWSTATES_MAINMENU_BUTTONS_H_ */
