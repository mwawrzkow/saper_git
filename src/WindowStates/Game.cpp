/*
 * Game.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "Game.h"
#include <iostream>
#include "Poco/NumberFormatter.h"
namespace WindowState {

Game::Game(std::string ConfigFile, std::shared_ptr<Texture::Cache> TextureCache,
		bool* askForChange) :
		State(ConfigFile, TextureCache, askForChange) {
	LoadFiles();
	StateAdd("BOARD");
	StateAdd("TILE");
	// TODO Auto-generated constructor stub
}
void Game::start(GameLogic::GameMode &mode) {
	switch (mode) {
	case GameLogic::GameMode::EASY:
		GameControler.createBoard(10, 10, mode);
		break;
	case GameLogic::GameMode::NORMAL:
		GameControler.createBoard(20, 20, mode);
		break;
	case GameLogic::GameMode::HARD:
		GameControler.createBoard(25, 25, mode);
		break;
	}
	GameControler.getView()->debug();
	CreateUnits();
}
void Game::CreateUnits() {
	int boardWidth = GameControler.getView()->getBoardWidth();
	int boardHeight = GameControler.getView()->getBoardHeight();
	int offsetx = 25, offsety = 25;
	for (int i = 0; i < Render.getQueue().size(); i++) {
		if (Render.getQueue().at(i)->getName() == availibeNames[0]) {
			for (int x = 0; x <= 9 + 1; x++) {
				for (int y = 0; y <= 9 + 1; y++) {
					float scale = 1.2;
					float xpos = offsetx + (50 * scale * x);
					float ypos = offsety + (50 * scale * y);
					GameUnits::BoardBG *bg = new GameUnits::BoardBG(
							*Render.getQueue().at(i));
					bg->setPosition(xpos, ypos);
					bg->returnSprite()->scale(sf::Vector2f(scale, scale));
					//std::cout << "Created Board Tile at x:"<< xpos << " y:" <<ypos<< std::endl;
					BoardBG.push_back(bg);

				}
			}
		} else if (Render.getQueue().at(i)->getName() == availibeNames[1]) {
			for (int x = 0; x <= boardWidth; x++) {
				for (int y = 0; y <= boardHeight; y++) {
					float TileScale;
					switch (GameControler.getGameMode()) {
					case GameLogic::GameMode::EASY:
						TileScale = 0.625;
						break;
					case GameLogic::GameMode::NORMAL:
						TileScale = 0.3125;
						break;
					case GameLogic::GameMode::HARD:
						TileScale = 0.25;
						break;
					}
					float xpos = offsetx
							+ (((float) 100 * TileScale + (float) 5 * TileScale)
									* x) + (float) 5 * TileScale;
					float ypos = offsety
							+ (((float) 100 * TileScale + (float) 5 * TileScale)
									* y) + (float) 5 * TileScale;
					GameUnits::Tile *tile = new GameUnits::Tile(
							*Render.getQueue().at(i), x, y);
					tile->scale(TileScale);
					tile->setPosition(xpos, ypos);
					tile->ToggleClicable();
					tile->ToggleRClicable();
					//std::cout << "Created Tile at x:"<< xpos << " y:" <<ypos<< std::endl;
					Tiles.push_back(tile);
				}
			}
		}
	}
	for (GameUnits::BoardBG *e : BoardBG)
		Units.push_back(e);
	for (GameUnits::Tile *e : Tiles)
		Units.push_back(e);
	setUnits();
}
GameLogic::GameMode* Game::askedGameMode() {
	return nullptr;
}
void Game::update() {
	for (GameUnits::Tile *e : Tiles) {
		if (e->checkClick() && e->getSpriteOptions().isChanged()) {
			std::cout << "Reveal field at x:" << e->getX() << " y:" << e->getY()
					<< std::endl;
			GameControler.getInput()->revealField(e->getX(), e->getY());
			e->getSpriteOptions().changed();
			e->resetClick();
		} else if (e->checkrClick() && e->getSpriteOptions().isChanged()) {
			std::cout << "Setting flag at x:" << e->getX() << " y:" << e->getY()
					<< std::endl;
			GameControler.getInput()->setFlag(e->getX(), e->getY());
			e->getSpriteOptions().changed();
			e->resetClick();
		}
	}
	if (GameControler.getGameState() == GameLogic::GameState::RUNNING) {
		updateBoard();
	} else if(isGameEnded && !isBoardUpdated){
		isBoardUpdated = !isBoardUpdated;
		GameControler.getBoard()->endGame();
		for (GameUnits::Tile *e : Tiles) {
			e->setNClicable();
			e->setNRClicable();
		}
	}else{
		updateBoard();
		isGameEnded = true;
	}
}
void Game::updateBoard() {
	for (GameUnits::Tile *e : Tiles) {
		e->spriteUpdate();
		int x = e->getX();
		int y = e->getY();
		GameTextView::TypeOfField update = GameControler.getView()->SingleField(
				x, y);
		switch (update) {
		case GameTextView::TypeOfField::HIDDEN:
			e->updateState("default");
			break;
		case GameTextView::TypeOfField::REVEALED:
			e->updateState("revealed");
			break;
		case GameTextView::TypeOfField::FLAG:
			e->updateState("flag");
			break;
		case GameTextView::TypeOfField::MINE:
			e->updateState("mine");
			break;
		case GameTextView::TypeOfField::NEARMINE:
			int mines = GameControler.getView()->countMines(x, y);
			e->updateState("nearmines" + Poco::NumberFormatter::format(mines));
			break;
		}
	}
}
void Game::setUnits() {
	for (Graphic::ObjectInterface* e : Units) {
		e->createSprite();
	}

}

} /* namespace WindowState */
