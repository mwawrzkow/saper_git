/*
 * Render.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: mwawrzkow
 */

#include "Render.h"

namespace Graphic {

Render::Render(sf::RenderWindow &window) :
		window(window), toRender(new std::vector<ObjectInterface*>) {
	// TODO Auto-generated constructor stub
}

void Render::renderQueue(std::vector<ObjectInterface*>& toRender) {

	this->toRender = &toRender;

}
sf::RenderWindow& Render::getWindow() {
	return window;
}
void Render::run() {
	sf::Time jumpValue = sf::seconds(1);
	while (window.isOpen()) {
		window.clear();
		for (ObjectInterface *e : *toRender) {
			if(e->isVisible())
			window.draw(*e->returnSprite());
		}
		//		states[0]->resetStates();
		window.display();
		sf::Time time  = tmp.getElapsedTime();
		for (ObjectInterface *e : *toRender)
			if (time > jumpValue)
			{
				e->resetState();
				tmp.restart();
			}
	}
}
void Render::runThreadSafe() {
	sf::Time jumpValue = sf::seconds(1);
		window.clear();
		for (ObjectInterface *e : *toRender) {
			if(e->isVisible())
			window.draw(*e->returnSprite());
		}
		//		states[0]->resetStates();
		window.display();
		sf::Time time  = tmp.getElapsedTime();
		for (ObjectInterface *e : *toRender)
			if (time > jumpValue)
			{
				e->resetState();
				tmp.restart();
			}
}
Render::~Render() {
	// TODO Auto-generated destructor stub
}

} /* namespace Objects */
