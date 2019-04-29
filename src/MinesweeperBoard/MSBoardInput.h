/*
 * MSBoardTextInput.h
 *
 *  Created on: Mar 12, 2019
 *      Author: Marcin Wawrzków
 *      mail: marcin.wawrzkow@outlook.com
 *
 *      Description: Frontend Class to change value of tiles in board
 */

#ifndef SRC_MSBOARDINPUT_H_
#define SRC_MSBOARDINPUT_H_
#include "MinesweeperBoard.h"
namespace GameInput {

class MSBoardTextInput {
	GameLogic::MinesweeperBoard *board;
public:
	/*
	 * Need GameLogic  MinesweeperBoard object to work correctly
	 * DO NOT CHANGE CONSTRUCTOR
	 */
	MSBoardTextInput(GameLogic::MinesweeperBoard *temp);
	/*
	 * Reveal field in selected position.
	 */
	void revealField(unsigned int x, unsigned int y);
	void setFlag(int,int);
};

} /* namespace input */

#endif /* SRC_MSBOARDINPUT_H_ */
