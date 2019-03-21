/*
 * MSBoardTextInput.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: marcin
 */

#include "MSBoardInput.h"

namespace GameInput {

MSBoardTextInput::MSBoardTextInput(GameLogic::MinesweeperBoard &temp):board(temp) {
	// TODO Auto-generated constructor stub

}
void MSBoardTextInput::revealField(unsigned int x, unsigned int y){
	board.revealField(x,y);
}
} /* namespace input */
