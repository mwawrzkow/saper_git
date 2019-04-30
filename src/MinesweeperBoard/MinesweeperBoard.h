/*
 * MinesweeperBoard.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Marcin Wawrzków
 *      mail: marcin.wawrzkow@outlook.com
 *
 *      Description: General Class for Logic of game.
 */

#ifndef SRC_MINESWEEPERBOARD_H_
#define SRC_MINESWEEPERBOARD_H_
#include "field.h"
namespace GameLogic {
/*
 *  Available game modes, Do not change if not consultated with author of class
 */
enum GameMode {
	DEBUG, EASY, NORMAL, HARD, TEST1
};
/*
 * All available states of game
 */
enum GameState {
	RUNNING, FINISHED_WIN, FINISHED_LOSS
};

class MinesweeperBoard {
	/*
	 * Amount of revealed tiles
	 */
	int revealCount = 0;
	bool firstMove = true;
	/*
	 * Private method to check if tile is in rage of board
	 */
	bool isRightField(int x, int y) const;
	/*
	 * Definition of board
	 */
	Field board[100][100];
	/*
	 *  Variables that define Board Width and Height
	 */
	int width;
	GameMode mode;
	int height;
	/*
	 * Amount of mines on board
	 */
	int minescount = 0;
	/*
	 * Actual state of game
	 */
	GameState state;
	void fillFields();

public:
	/*Constructor for MinesweeperBoard. Width, height, and Game mode
	 * Game modes DEBUG, EASY, NORMAL, HARD, TEST1
	 * TEST1 has predefined pattern.
	 */
	void endGame();
	MinesweeperBoard(int x, int y, GameMode mode);
	/*
	 * Changes Value of Flag atribute in Board
	 */
	void toggleFlag(int x, int y);
	/*
	 * Reveals field in Board
	 */
	void revealField(int x, int y);

	/*
	 * Constant Functions to get information about object.
	 * WARNING: USE ONLY IN DISPLAY CLASSES AND/OR IN DEBUG MODE
	 */
public:
	/*
	 * Returns Actual Game State
	 */
	GameState getGameState() const;
	/*
	 * Returns Field of board
	 */
	int getBoardWidth() const;
	/*
	 * Shows Debug view of actual state of board in terminal
	 */
	void debug_display() const;
	/*
	 * Returns board Height
	 */
	int getBoardHeight() const;
	/*
	 * Returns amount of mines in board
	 */
	int getMineCount() const;
	/*
	 * Returns true if board is Revealed
	 */
	bool isRevealed(int x, int y) const;
	/*
	 * Count all near mines to board
	 */
	int countMines(int x, int y) const;
	/*
	 * Returns true if flag is on board
	 */
	bool hasFlag(int x, int y) const;
	/*
	 * Returns true if mine is on board
	 */
	bool hasMine(int x, int y) const;
};
}
#endif /* SRC_MINESWEEPERBOARD_H_ */
