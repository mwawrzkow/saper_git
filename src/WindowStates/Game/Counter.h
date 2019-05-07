/*
 * MinesCount.h
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_GAME_COUNTER_H_
#define SRC_WINDOWSTATES_GAME_COUNTER_H_
#include "Counter/Number.h"
#include "../LoadSprite/ObjectInterface.h"

namespace CountingObject {

class Counter: public Graphic::ObjectInterface {
	Digit::Number *houndred;
	Digit::Number *dozen;
	Digit::Number *unity;
public:
	Counter(const Graphic::ObjectInterface&);
	void setGraphicForNumbers(const Graphic::ObjectInterface&);
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
	std::vector<Graphic::ObjectInterface*> getGroupOfObjects();
	virtual ~Counter();
	void howManyMines(int);
};

} /* namespace GameMines */

#endif /* SRC_WINDOWSTATES_GAME_COUNTER_H_ */
