/*
 * Easy.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_EASY_H_
#define SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_EASY_H_
#include "../../LoadSprite/ObjectInterface.h"

namespace SettingsButtons {

class Easy final: public Graphic::ObjectInterface{
public:
	Easy();
	Easy(const Graphic::ObjectInterface&);
	virtual ~Easy();
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace SettingsButtons */

#endif /* SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_EASY_H_ */
