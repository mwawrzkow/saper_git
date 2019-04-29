/*
 * settings.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_MAINMENU_SETTINGS_H_
#define SRC_WINDOWSTATES_MAINMENU_SETTINGS_H_
#include "../../MinesweeperBoard/MinesweeperBoard.h"
#include "settingsbuttons/Easy.h"
#include "settingsbuttons/Normal.h"
#include "settingsbuttons/Hard.h"
namespace MainMenuRequests{
struct request
{
	GameLogic::GameMode newgamereq = GameLogic::GameMode::DEBUG;
	bool exit = false;
};
}
namespace MenuUnits {

class Settings final: public Graphic::ObjectInterface {
private:
	SettingsButtons::Easy *easy;
	SettingsButtons::Normal *normal;
	SettingsButtons::Hard *hard;
	MainMenuRequests::request *req;
public:
	Settings(const Graphic::ObjectInterface&, MainMenuRequests::request*);
	virtual void setPosition(float, float) override;
	virtual void updateState(std::string) override;
	virtual void toggleVisible() override;
	virtual void update() override;
	void SetEasy(const Graphic::ObjectInterface&);
	void SetNormal(const Graphic::ObjectInterface&);
	void setHard(const Graphic::ObjectInterface&);
	Graphic::ObjectInterface* getEasy();
	Graphic::ObjectInterface* getNormal();
	Graphic::ObjectInterface* getHard();
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_MAINMENU_SETTINGS_H_ */
