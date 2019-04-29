/*
 * LoadingScreen.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADINGSCREEN_H_
#define SRC_WINDOWSTATES_LOADINGSCREEN_H_
#include <SFML/Graphics.hpp>
#include <vector>
namespace WindowState {

class LoadingScreen {
	std::vector<sf::Sprite>render;
public:
	LoadingScreen();
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_LOADINGSCREEN_H_ */
