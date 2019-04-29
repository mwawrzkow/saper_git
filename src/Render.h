/*
 * Render.h
 *
 *  Created on: Apr 24, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_
#include <SFML/Graphics.hpp>
#include "Poco/Runnable.h"
#include "WindowStates/State.h"
namespace Graphic {

class Render : Poco::Runnable{
	sf::RenderWindow &window;
	std::vector<ObjectInterface*>*toRender;
	sf::Clock tmp;
public:
	Render(sf::RenderWindow&);
	void renderQueue(std::vector<ObjectInterface*>&);
	void run();
	void runThreadSafe();
	~Render();
	sf::RenderWindow &getWindow();
	friend class MS_SFML_View;
};

} /* namespace Objects */

#endif /* SRC_RENDER_H_ */
