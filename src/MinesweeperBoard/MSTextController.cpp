/*
 * MSTextController.cpp
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#include "MSTextController.h"

#include <cctype>
#include <iostream>

namespace Controler {

MSTextController::MSTextController(GameLogic::MinesweeperBoard &board,
		GameTextView::MSBoardTextView &view) :
		board(board),
		view(view)
{
	start();

}

void MSTextController::start(){
	while(board.getGameState() == GameLogic::GameState::RUNNING)
	{
		display();
		move();
	}
}

void MSTextController::display(){
	view.debug();
}

void MSTextController::move()
{
	char a;
	int x, y;
	std::cin >> a >> x >>y ;
	if(tolower(a) == 'f')
		board.toggleFlag(x,y);
	else if(tolower(a) == 'r')
		board.revealField(x,y);

}
} /* namespace SpriteSettings */
