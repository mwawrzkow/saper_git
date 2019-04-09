#include "src/MinesweeperBoard/MinesweeperBoard.h"
#include "src/MinesweeperBoard/MSBoardTextView.h"
#include "src/MinesweeperBoard/MSTextController.h"
#include "src/sfml/sfmlimplementation.h"

namespace GameLogic {
class MinesweeperBoard;
} /* namespace GameLogic */


int main(int argc, char **argv) {
	GameLogic::MinesweeperBoard game(10,10,GameLogic::GameMode::EASY);
	GameTextView::MSBoardTextView view(game);
	Controler::MSTextController controler(game,view);
	sf::RenderWindow wind(sf::VideoMode(800,800), "pls work");
	SFML::sfmlimplementation start(view,controler,game, wind);
	return 0;

}
