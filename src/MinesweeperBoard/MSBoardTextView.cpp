/*
 * MSBoardTextView.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: marcin
 */

#include "MSBoardTextView.h"
#include <iostream>
#include <string>
namespace GameTextView {
MSBoardTextView::MSBoardTextView(GameLogic::MinesweeperBoard &temp) :
		game(temp) {
}

void MSBoardTextView::debug() const {
	for (int x = 0; x < game.getBoardWidth(); x++) {
		for (int y = 0; y < game.getBoardHeight(); y++) {
			std::cout << "[";
			TypeOfField tile;
			tile = SingleField(x,y);
			switch(tile){
			case TypeOfField::MINE:
				std::cout << "M";
				break;
			case TypeOfField::NEARMINE:
				std::cout << game.countMines(x,y);
				break;
			case TypeOfField::REVEALED:
				std::cout << ".";
				break;
			case TypeOfField::FLAG:
				std::cout <<"F";
				break;
			case TypeOfField::HIDDEN:
				std::cout << "";
				break;
			case TypeOfField::ERROR:
				std::cout << "ERROR";
				break;
			}
			std::cout << "]";
		}
		std::cout << std::endl;
	}
}
TypeOfField MSBoardTextView::SingleField(unsigned int x, unsigned int y) const {
	if (game.isRevealed(x, y)) {
		if (game.hasMine(x, y))
			return TypeOfField::MINE;
		if (game.countMines(x, y))
			return TypeOfField::NEARMINE;
		return TypeOfField::REVEALED;
	} else {
		if (game.hasFlag(x, y))
			return TypeOfField::FLAG;
		return TypeOfField::HIDDEN;
	}
	return TypeOfField::ERROR;
}

}
