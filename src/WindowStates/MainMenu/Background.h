/*
 * BackGround.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_BACKGROUND_H_
#define SRC_WINDOWSTATES_MAINMENU_BACKGROUND_H_
#include "../LoadSprite/ObjectInterface.h"

namespace MenuUnits {

class backGround final: public Graphic::ObjectInterface  {
private:
	bool isreverse = false;
public:
	backGround(const Graphic::ObjectInterface&);
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;

};

} /* namespace MainMenu */

#endif /* SRC_WINDOWSTATES_MAINMENU_BACKGROUND_H_ */
