/*
 * number.h
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_GAME_COUNTER_NUMBER_H_
#define SRC_WINDOWSTATES_GAME_COUNTER_NUMBER_H_
#include "../../LoadSprite/ObjectInterface.h"

namespace Digit {

class Number: public Graphic::ObjectInterface {
public:
	Number(const Graphic::ObjectInterface&);
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
	virtual ~Number();
};

} /* namespace MinesCount */

#endif /* SRC_WINDOWSTATES_GAME_COUNTER_NUMBER_H_ */
