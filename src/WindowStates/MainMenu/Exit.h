/*
 * Exit.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_EXIT_H_
#define SRC_WINDOWSTATES_MAINMENU_EXIT_H_
#include "../LoadSprite/ObjectInterface.h"
#include "Settings.h"
#include "Buttons.h"
namespace MenuUnits {

class Exit final: public MainMenuButtons::Buttons{
	MainMenuRequests::request *req;
public:
	Exit(const Graphic::ObjectInterface&,MainMenuRequests::request* );
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace MainMenu */

#endif /* SRC_WINDOWSTATES_MAINMENU_EXIT_H_ */
