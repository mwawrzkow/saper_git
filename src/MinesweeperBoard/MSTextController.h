/*
 * MSTextController.h
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#ifndef SRC_MINESWEEPERBOARD_MSTEXTCONTROLLER_H_
#define SRC_MINESWEEPERBOARD_MSTEXTCONTROLLER_H_
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

namespace Controler {

class MSTextController {
	GameLogic::MinesweeperBoard &board;
	const GameTextView::MSBoardTextView &view;
public:
	MSTextController(GameLogic::MinesweeperBoard &board, GameTextView::MSBoardTextView &view);
public:
	void display();
	void move();
	void start();
};

} /* namespace SpriteSettings */

#endif /* SRC_MINESWEEPERBOARD_MSTEXTCONTROLLER_H_ */
