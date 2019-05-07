/*
 * MinesCount.cpp
 *
 *  Created on: 3 maj 2019
 *      Author: marcin
 */

#include "Counter.h"

namespace CountingObject {

Counter::Counter(const Graphic::ObjectInterface& tmp):Graphic::ObjectInterface(tmp) {
	// TODO Auto-generated constructor stub

}
void Counter::setGraphicForNumbers(const Graphic::ObjectInterface& tmp){
	houndred = new Digit::Number(tmp);
	dozen = new Digit::Number(tmp);
	unity = new Digit::Number(tmp);
}
Counter::~Counter(){
	delete houndred, dozen,unity;
}
void Counter::setPosition(float x,float y){
	Sprite.setPosition(sf::Vector2f(x,y));
	houndred->setPosition(x+35,y+40);
	dozen->setPosition(x+80,y+40);
	unity->setPosition(x+125,y+40);
}
std::vector<Graphic::ObjectInterface*> Counter::getGroupOfObjects(){
	std::vector<Graphic::ObjectInterface*>tmp;
	tmp.push_back(houndred);
	tmp.push_back(dozen);
	tmp.push_back(unity);
	return tmp;
}
void Counter::updateState(std::string){}
void Counter::update() {}
void Counter::howManyMines(int mines){
	int houndredint = mines /100,
			dozenint = (mines %100)/10,
			unityint = (mines%10);
	if(houndredint == 0)
	{
		houndred->toggleVisible();
		if(dozenint == 0)
			dozen->toggleVisible();
	}
	houndred->updateState(std::to_string(houndredint));
	dozen->updateState(std::to_string(dozenint));
	unity->updateState(std::to_string(unityint));


}
} /* namespace GameMines */
