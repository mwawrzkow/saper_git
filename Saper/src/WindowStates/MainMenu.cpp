/*
 * MainMenu.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "MainMenu.h"

#include "LoadSprite/texturebackend/Cache.h"

namespace WindowState {


MainMenu::MainMenu(std::string MenuFileList, std::shared_ptr<Texture::Cache>TextureCache) :
		state(State::NONE),Menu(MenuFileList + "config.conf",&availibeNames,TextureCache){

}

std::vector<sf::Sprite>MainMenu::queue()
{
	return render;
}
void MainMenu::start()
{
	LoadFiles();
	LoadSprites();
}
void MainMenu::LoadFiles()
{
	Menu.LoadTextureDirectories();
	FileList();
}

void MainMenu::LoadSprites(){
//if(Graphic.getState().areFilesLoaded != true)
	return;
}

void MainMenu::FileList()
{

}

} /* namespace WindowState */
