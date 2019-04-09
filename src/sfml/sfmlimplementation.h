#include <SFML/Graphics.hpp>
#include <vector>

#include "../MinesweeperBoard/MSBoardTextView.h"

namespace GameLogic {
class MinesweeperBoard;
} /* namespace GameLogic */

namespace Controler {
class MSTextController;
} /* namespace Controler */

/*
 * sfmlimplementation.h
 *
 *  Created on: 9 kwi 2019
 *      Author: marcin
 */
namespace GameTextView {
class MSBoardTextView;
} /* namespace GameTextView */
namespace sf {
class RenderWindow;
} /* namespace sf */

#ifndef SRC_SFML_SFMLIMPLEMENTATION_H_
#define SRC_SFML_SFMLIMPLEMENTATION_H_

namespace SFML {

class sfmlimplementation {
	sf::RenderWindow &window;
	GameTextView::MSBoardTextView &view;
	Controler::MSTextController &contr;
	GameLogic::MinesweeperBoard &game;
	std::vector<sf::RectangleShape> queue;
public:
	sfmlimplementation(GameTextView::MSBoardTextView &view,
			Controler::MSTextController contr,
			GameLogic::MinesweeperBoard &temp, sf::RenderWindow &window);
	void loop();
	void render();
	void event();
	void update();
protected:
	void mouseclick(sf::Event MouseEvent);

};

} /* namespace SpriteSettings */

#endif /* SRC_SFML_SFMLIMPLEMENTATION_H_ */
