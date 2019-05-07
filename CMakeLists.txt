cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lpthread -lstdc++ -lX11")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
project (Saper)
find_package(Poco REQUIRED COMPONENTS Foundation Net Zip )
find_package(SFML  REQUIRED graphics window system)
add_executable(Saper Saper.cpp
 	 src/MinesweeperBoard/MinesweeperBoard.cpp
     src/MinesweeperBoard/MSBoardTextView.cpp
     src/MinesweeperBoard/BoardControler.cpp
     src/MinesweeperBoard/MSBoardInput.cpp
     
     src/MSSFMLView.cpp
     src/Render.cpp
     src/EventHandler.cpp
     
     
     src/WindowStates/FileIO/FileInformation/FileInformation.cpp
     src/WindowStates/FileIO/FileManager.cpp
     
     src/WindowStates/State.cpp
     src/WindowStates/Game.cpp
     src/WindowStates/InGameMenu.cpp
     src/WindowStates/LoadingScreen.cpp
     src/WindowStates/MainMenu.cpp
     
     src/WindowStates/MainMenu/Buttons.cpp
     src/WindowStates/MainMenu/Background.cpp
     src/WindowStates/MainMenu/Exit.cpp
     src/WindowStates/MainMenu/NewGame.cpp
     src/WindowStates/MainMenu/Options.cpp
     src/WindowStates/MainMenu/settingsbuttons/Easy.cpp
     src/WindowStates/MainMenu/settingsbuttons/Normal.cpp
     src/WindowStates/MainMenu/settingsbuttons/Hard.cpp
     src/WindowStates/MainMenu/Settings.cpp
     
     src/WindowStates/Game/Tile.cpp
     src/WindowStates/Game/Counter.cpp
     src/WindowStates/Game/Counter/Number.cpp
     src/WindowStates/Game/Background.cpp
     src/WindowStates/Game/BoardBG.cpp
     
     src/WindowStates/LoadSprite/texturebackend/Cache.cpp
     src/WindowStates/LoadSprite/texturebackend/SpriteOptions.cpp
     src/WindowStates/LoadSprite/Object.cpp
     src/WindowStates/LoadSprite/ObjectInterface.cpp
     src/WindowStates/LoadSprite/RenderClass.cpp
     src/WindowStates/LoadSprite/ClickEvent.cpp)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Saper ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(Saper sfml-system sfml-window sfml-graphics sfml-audio)
    
endif()
target_link_libraries(Saper Poco::Foundation Poco::Util Poco::Net)

