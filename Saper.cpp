#include "src/MinesweeperBoard/MSBoardTextView.h"

namespace GameLogic {
class MinesweeperBoard;
} /* namespace GameLogic */


int main(int argc, char **argv) {
	GameLogic::MinesweeperBoard game(10,10,GameLogic::GameMode::EASY);
	GameTextView::MSBoardTextView view(game);
	view.debug();
	return 0;

}
