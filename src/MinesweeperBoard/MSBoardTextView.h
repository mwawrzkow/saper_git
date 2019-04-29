/*
 * MSBoardTextView.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Marcin Wawrzków
 *      mail: marcin.wawrzkow@outlook.com
 *
 *      Description: FrontEnd Class to show userend version to render by Graphic engine
 */

#ifndef SRC_MSBOARDTEXTVIEW_H_
#define SRC_MSBOARDTEXTVIEW_H_
#include "MinesweeperBoard.h"
#include <string>
namespace GameTextView {

enum TypeOfField{
	ERROR,
	HIDDEN,
	REVEALED,
	NEARMINE,
	FLAG,
	MINE
};
class MSBoardTextView {
	/*
	 * Constant reference to MinesweeperBoard object.
	 * Gives ability to show board as for user
	 */
	const GameLogic::MinesweeperBoard *game;
public:
	/*
	 * Constructor NEEDS MinesweeperBoard object From GameLogic to class work correctly
	 */
	MSBoardTextView(GameLogic::MinesweeperBoard*);
	/*
	 * Returns Type of Field to render.
	 * If TypeOfField is equal NEARMINE function near will return value of nearest mines
	 */
	TypeOfField SingleField(unsigned int x,unsigned int y) const;
	/*
	 * Displays debug mode of user board in terminal
	 */
	int countMines(int,int);
	int getBoardHeight();
	int getBoardWidth();
	void debug() const;
};
}
#endif /* SRC_MSBOARDTEXTVIEW_H_ */
