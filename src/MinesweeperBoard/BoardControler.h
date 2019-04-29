/*
 * BoardControler.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_MINESWEEPERBOARD_BOARDCONTROLER_H_
#define SRC_MINESWEEPERBOARD_BOARDCONTROLER_H_
#include "MinesweeperBoard.h"
#include "MSBoardInput.h"
#include "MSBoardTextView.h"
namespace GameControler {

class BoardControler {
	GameLogic::MinesweeperBoard *board;
protected:
	GameInput::MSBoardTextInput *input;
	GameTextView::MSBoardTextView *view;
	GameLogic::GameMode mode;
public:
	BoardControler();
	virtual ~BoardControler();
	void createBoard(int x, int y, GameLogic::GameMode mode);
	GameLogic::MinesweeperBoard* getBoard();
	bool boardStatus();
	void deleteBoard();
	GameInput::MSBoardTextInput* getInput();
	GameTextView::MSBoardTextView *getView();
	GameLogic::GameMode getGameMode();
	GameLogic::GameState getGameState();
};

} /* namespace GameControler */

#endif /* SRC_MINESWEEPERBOARD_BOARDCONTROLER_H_ */
