/*
 * BoardBG.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_GAME_BOARDBG_H_
#define SRC_WINDOWSTATES_GAME_BOARDBG_H_
#include "../LoadSprite/ObjectInterface.h"

namespace GameUnits {

class BoardBG : public Graphic::ObjectInterface{
public:
	BoardBG(const Graphic::ObjectInterface&);
	virtual ~BoardBG();
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
};

} /* namespace GameUnits */

#endif /* SRC_WINDOWSTATES_GAME_BOARDBG_H_ */
