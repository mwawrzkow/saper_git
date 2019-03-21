/*
 * Game.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_GAME_H_
#define SRC_WINDOWSTATES_GAME_H_
#include <SFML/Graphics.hpp>
#include <vector>
namespace WindowState {

class Game {
	std::vector<sf::Sprite>render;
public:
	Game();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_GAME_H_ */
