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
#include "State.h"
#include "../MinesweeperBoard/BoardControler.h"
#include "Game/Tile.h"
#include "Game/BoardBG.h"
namespace WindowState {

class Game: public Controller::State {
	std::vector<GameUnits::Tile*>Tiles;
	std::vector<GameUnits::BoardBG*>BoardBG;
	GameControler::BoardControler GameControler;
	bool isGameEnded = false;
	bool isBoardUpdated = false;
private:
	virtual GameLogic::GameMode* askedGameMode();
	virtual void CreateUnits() override;
	virtual void setUnits() override;
	virtual void update() override;
	virtual void updateBoard();
public:
	Game(std::string, std::shared_ptr<Texture::Cache> TextureCache, bool*);
	virtual void start(GameLogic::GameMode &) override;
};

} /* namespace WindowState */

#endif /* SRC_WINDOWSTATES_GAME_H_ */
