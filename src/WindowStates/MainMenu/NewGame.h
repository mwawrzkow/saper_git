/*
 * NewGame.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_NEWGAME_H_
#define SRC_WINDOWSTATES_MAINMENU_NEWGAME_H_
#include "../LoadSprite/ObjectInterface.h"
namespace MenuUnits {

class NewGame final: public Graphic::ObjectInterface {
public:
	NewGame(const Graphic::ObjectInterface&);
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace MainMenu */

#endif /* SRC_WINDOWSTATES_MAINMENU_NEWGAME_H_ */
