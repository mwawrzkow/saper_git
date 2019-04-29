/*
 * Tile.h
 *
 *  Created on: Apr 28, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_GAME_TILE_H_
#define SRC_WINDOWSTATES_GAME_TILE_H_
#include "../LoadSprite/ObjectInterface.h"

namespace GameUnits {

class Tile : public Graphic::ObjectInterface{
	const int x, y;
public:
	Tile(const Graphic::ObjectInterface&,int,int);
	virtual ~Tile();
	virtual void setPosition(float,float) override;
	virtual void updateState(std::string) override;
	virtual void update() override;
	void scale(float);
	const int getX()const;
	const int getY()const;
};

} /* namespace GameUnits */

#endif /* SRC_WINDOWSTATES_GAME_TILE_H_ */
