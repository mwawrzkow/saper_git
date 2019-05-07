/*
 * MinesweeperBoard.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: marcin
 */

#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>
namespace GameLogic {
MinesweeperBoard::MinesweeperBoard(int x, int y, GameMode mode) :
		width(x - 1), height(y - 1), state(GameState::RUNNING), mode(mode) {

}

void MinesweeperBoard::debug_display() const {
	for (int i = 0; i < width; i++) {
		for (int c = 0; c < height; c++) {
			std::cout << "[";
			if (board[i][c].hasMine) {
				std::cout << "M";
			} else {
				std::cout << ".";
			}
			if (board[i][c].isRevealed) {
				std::cout << "o";
			} else {
				std::cout << ".";
			}
			if (board[i][c].hasFlag) {
				std::cout << "f";
			} else {
				std::cout << ".";
			}
			std::cout << "]";
		}
		std::cout << std::endl;
	}

}

bool MinesweeperBoard::isRightField(int x, int y) const {
	if (x < 0 || y < 0 || x > width || y > height)
		return false;
	return true;
}
int MinesweeperBoard::getBoardWidth() const {
	return width;
}

int MinesweeperBoard::getBoardHeight() const {
	return height;
}

int MinesweeperBoard::getMineCount() const {
	return minescount;
}

int MinesweeperBoard::countMines(int x, int y) const {
	int count = 0;
	for (int i = (x - 1); i <= x + 1; i++)
		for (int c = (y - 1); c <= y + 1; c++) {
			if (isRightField(i, c))
				if (board[i][c].hasMine)
					count++;
		}
	return count;
}
GameState MinesweeperBoard::getGameState() const {
	return state;
}

bool MinesweeperBoard::hasFlag(int x, int y) const {
	if (!isRightField(x, y))
		return false;
	if (board[x][y].isRevealed)
		return false;
	return board[x][y].hasFlag;
}

void MinesweeperBoard::toggleFlag(int x, int y) {
	if (isRightField(x, y) && board[x][y].isRevealed // @suppress("Suggested parenthesis around expression")
			&& getGameState() != GameState::RUNNING) // @suppress("Suggested parenthesis around expression")
		return;
	board[x][y].hasFlag = !board[x][y].hasFlag;
}
bool MinesweeperBoard::hasMine(int x, int y) const {
	if (isRightField(x, y))
		if (board[x][y].hasMine)
			return true;
	return false;
}
bool MinesweeperBoard::isRevealed(int x, int y) const {
	if (isRightField(x, y))
		if (board[x][y].isRevealed)
			return true;
	return false;
}
void MinesweeperBoard::revealField(int x, int y) {
	if (firstMove == true) {
		repeat: fillFields();
		for (int z = x - 1; z <= x+1; z++)
			for (int c = y - 1; c <= y+1; c++)
				if (hasMine(z, c))
					goto repeat;
		firstMove = false;
	}

	if (!isRightField(x, y))
		return;

	if (isRevealed(x, y))
		return;
	if (hasFlag(x, y))
		return;

	if (getGameState() != GameState::RUNNING)
		endGame();
	if (!board[x][x].hasFlag)
		if (!hasMine(x, y)) {
			board[x][y].isRevealed = true;
			revealCount++;
		} else {
			board[x][y].isRevealed = true;
			state = GameState::FINISHED_LOSS;
		}
	if ((height + 1) * (width + 1) - minescount == revealCount)
		state = GameState::FINISHED_WIN;

	if (countMines(x, y) != 0)
		return;

	for (int a = x - 1; a <= x + 1; a++)
		for (int z = y - 1; z <= y + 1; z++)
			if (hasMine(a, z)) {
			} else {
				revealField(a, z);
			}
}
void MinesweeperBoard::endGame() {
	for (int x = 0; x <= width; x++)
		for (int y = 0; y <= height; y++)
			if (isRightField(x, y))
				board[x][y].isRevealed = true;
	std::cout << "Mines Amount:" << minescount << std::endl;
}
int MinesweeperBoard::getRevealCount() const {
	return revealCount;
}

void MinesweeperBoard::fillFields() {
	for (int x = 0; x < width+1; x++)
		for (int y = 0; y < height+1; y++)
			board[x][y].clear();
	minescount = 0;
	std::vector<int> minesXPlaces(width + 1);
	std::vector<int> minesYPlaces(height + 1);

	std::iota(minesYPlaces.begin(), minesYPlaces.end(), 0);
	std::iota(minesXPlaces.begin(), minesXPlaces.end(), 0);

	std::srand(unsigned(std::time(0)));
	std::random_shuffle(minesXPlaces.begin(), minesXPlaces.end());
	std::random_shuffle(minesYPlaces.begin(), minesYPlaces.end());
	int bomblist = (width + 1) * (height + 1);
	if (GameMode::EASY == mode) {
		bomblist *= 0.1;
	} else if (GameMode::NORMAL) {
		bomblist *= 0.2;
	} else if (GameMode::HARD) {
		bomblist *= 0.3;
	}
	if (mode != GameMode::DEBUG && mode != GameMode::TEST1) {
		do {
			int x = (std::rand() - 1) % width + 1;
			int y = (std::rand() - 1) % height + 1;
			board[minesXPlaces[x]][minesYPlaces[y]].hasMine = true;
			minescount++;
			bomblist--;
		} while (bomblist != 0);

	} else if (mode == GameMode::TEST1) {
		bool boardmines[10][10] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, { 0, 1, 0,
				0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, { 0, 0,
				0, 1, 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0,
				0, 0, 1, 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, {
				0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
		width = 10;
		height = 10;
		for (int x = 0; x < width; x++)
			for (int y = 0; y < height; y++)
				board[x][y].hasMine = boardmines[x][y];

		minescount++;
	}
}

}
void Field::clear() {
	hasMine = false;
	hasFlag = false;
	isRevealed = false;
}
