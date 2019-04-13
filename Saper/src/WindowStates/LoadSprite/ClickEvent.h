/*
 * ClickEvent.h
 *
 *  Created on: 13 kwi 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_
#define SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_
namespace Graphic {
class Object;
} /* namespace Graphic */
namespace sf {
class Event;
} /* namespace sf */


namespace ObjectSettings {

class Click {
	bool click;
	bool hold;
	bool rclick;
public:
	void ToggleClicable();
	void ToggleHoldable();
	void ToggleRClicable();
	Click();
	bool isClicable(Graphic::Object &obj);
	void ClickEvent(Graphic::Object &obj, sf::Event event);
protected:
	bool isClicable() const ;
	bool isHoldable() const ;
	bool isRClicable() const ;

};

} /* namespace ObjectSettings */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_ */
