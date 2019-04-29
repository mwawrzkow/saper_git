/*
 * Normal.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_NORMAL_H_
#define SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_NORMAL_H_
#include "../../LoadSprite/ObjectInterface.h"
namespace SettingsButtons {

class Normal final: public Graphic::ObjectInterface{
public:
	Normal();
	Normal(const Graphic::ObjectInterface&);
	virtual ~Normal();
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace SettingsButtons */

#endif /* SRC_WINDOWSTATES_MAINMENU_SETTINGSBUTTONS_NORMAL_H_ */
