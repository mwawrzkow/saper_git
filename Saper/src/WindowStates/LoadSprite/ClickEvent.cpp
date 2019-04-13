/*
 * ClickEvent.cpp
 *
 *  Created on: 13 kwi 2019
 *      Author: marcin
 */

#include "ClickEvent.h"
#include "Object.h"
#include <SFML/Graphics.hpp>

namespace ObjectSettings {

/*
 * class ClickEvent {
 bool click;
 bool hold;
 bool rclick;
 public:
 void setClicable();
 void setHoldable();
 void setRClicable();
 ClickEvent();
 bool isClicable(Graphic::Object &obj);
 void ClickEvent(Graphic::Object &obj, sf::Event event);
 protected:
 bool isClicable(Graphic::Object &obj) const ;
 bool isHoldable(Graphic::Object &obj) const ;
 bool isrclick(Graphic::Object &obj) const ;

 };
 */

Click::Click()
:click(false),hold(false),rclick(false)
{
}
void Click::ToggleClicable() {
	click = true;
}

void Click::ToggleHoldable() {
	hold = true;
}

void Click::ToggleRClicable() {
	rclick = true;
}

bool Click::isClicable(Graphic::Object &obj) {
	const Click* ObjectHandler = obj.getClicable();
	if(!ObjectHandler->isClicable())
		return false;
	if(!ObjectHandler->isRClicable())
		return false;
	if(!ObjectHandler->isHoldable())
		return false;
	return true;
}
void ClickEve(Graphic::Object &obj, sf::Event &event) {
	switch (event.type) {
	case sf::Mouse::Button::Left:
		obj.updateState("LeftClick");
		break;
	case sf::Mouse::Button::Right:
		obj.updateState("RightCLick");

		break;
	}
}
bool Click::isClicable() const{
	return click;
}
bool Click::isHoldable() const{return hold;}
bool Click::isRClicable()const{return rclick;}

} /* namespace ObjectSettings */
