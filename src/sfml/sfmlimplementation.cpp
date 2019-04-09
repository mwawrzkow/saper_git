/*
 * sfmlimplementation.cpp
 *
 *  Created on: 9 kwi 2019
 *      Author: marcin
 */

#include "sfmlimplementation.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include "../MinesweeperBoard/MinesweeperBoard.h"
#include "../MinesweeperBoard/MSTextController.h"

//set set::itereaor
namespace SFML {
sfmlimplementation::sfmlimplementation(GameTextView::MSBoardTextView &view,
		Controler::MSTextController contr, GameLogic::MinesweeperBoard &temp, sf::RenderWindow &window) :
		window(window), view(view), contr(contr), game(temp) {
	loop();

}
void sfmlimplementation::loop() {
	while(window.isOpen()){
	event();
	update();
	render();
	}
}
void sfmlimplementation::render() {
	window.clear(sf::Color::White);
	for (sf::RectangleShape a : queue)
		window.draw(a);
	window.display();

}
void sfmlimplementation::event() {
	sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::MouseButtonPressed)
        	mouseclick(event);
    }

}
void sfmlimplementation::mouseclick(sf::Event MouseEvent){
	int y = (MouseEvent.mouseButton.x) /60;
	int x = MouseEvent.mouseButton.y / 60;
	game.revealField(y,x);
}
/*
 * 	ERROR,
 HIDDEN,
 REVEALED,
 NEARMINE,
 FLAG,
 MINE
 */
void sfmlimplementation::update() {
	for (int x = 0; x < game.getBoardWidth(); ++x)
		for (int y = 0; y < game.getBoardHeight(); ++y) {
			sf::RectangleShape a(sf::Vector2f(50, 50));
			switch (view.SingleField(x, y)) {
			case GameTextView::TypeOfField::FLAG:
				a.setFillColor(sf::Color(115, 0, 0));
				break;
			case GameTextView::TypeOfField::HIDDEN:
				a.setFillColor(sf::Color(115, 0, 115));
				break;
			case GameTextView::TypeOfField::MINE:
				a.setFillColor(sf::Color(0, 115, 115));
				break;
			case GameTextView::TypeOfField::NEARMINE:
				a.setFillColor(sf::Color(50, 50, 50));
				break;
			}
			a.setPosition(sf::Vector2f(60*x,60*y));
					queue.push_back(a);
				}

		}
		} /* namespace SpriteSettings */
