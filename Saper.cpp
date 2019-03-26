#include "src/MinesweeperBoard/MinesweeperBoard.h"
#include "src/MinesweeperBoard/MSBoardTextView.h"
#include "src/MinesweeperBoard/MSTextController.h"

namespace GameLogic {
class MinesweeperBoard;
} /* namespace GameLogic */


int main(int argc, char **argv) {
	GameLogic::MinesweeperBoard game(10,10,GameLogic::GameMode::EASY);
	GameTextView::MSBoardTextView view(game);
	Controler::MSTextController start(game,view);
	return 0;

}
