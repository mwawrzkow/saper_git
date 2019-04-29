/*
 * BoardControler.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#include "BoardControler.h"

namespace GameControler {
/*
 * 	BoardControler();
 virtual ~BoardControler();
 void createBoard(int x, int y, GameLogic::GameMode mode);
 GameLogic::MinesweeperBoard getBoard();
 bool boardStatus();
 void deleteBoadr();
 GameInput::MSBoardTextInput* getInput();
 GameTextView::MSBoardTextView *getView();

 GameLogic::MinesweeperBoard *board;
 protected:
 GameInput::MSBoardTextInput *input;
 GameTextView::MSBoardTextView *view;
 */
GameLogic::MinesweeperBoard* BoardControler::getBoard() {
	return board;
}
GameInput::MSBoardTextInput* BoardControler::getInput() {
	return input;
}
GameTextView::MSBoardTextView* BoardControler::getView() {
	return view;
}
bool BoardControler::boardStatus() {
	if (board == nullptr)
		return false;
	if (view == nullptr)
		return false;
	if (input == nullptr)
		return false;
	return true;
}
void BoardControler::deleteBoard() {
	delete board, view, input;
}

BoardControler::BoardControler() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}
void BoardControler::createBoard(int x, int y, GameLogic::GameMode mode) {
	board = new GameLogic::MinesweeperBoard(x, y, mode);
	input = new GameInput::MSBoardTextInput(board);
	view = new GameTextView::MSBoardTextView(board);
	this->mode = mode;
}
GameLogic::GameMode BoardControler::getGameMode() {
	return mode;
}
BoardControler::~BoardControler() {
	// TODO Auto-generated destructor stub
}
GameLogic::GameState BoardControler::getGameState(){
	return board->getGameState();
}

} /* namespace GameControler */
