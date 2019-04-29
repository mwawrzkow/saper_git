/*
 * Hard.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_HARD_H_
#define SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_HARD_H_
#include "../../LoadSprite/ObjectInterface.h"
namespace SettingsButtons {

class Hard final: public Graphic::ObjectInterface{
public:
	Hard();
	Hard(const Graphic::ObjectInterface&);
	virtual ~Hard();
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace SettingsButtons */

#endif /* SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_HARD_H_ */
