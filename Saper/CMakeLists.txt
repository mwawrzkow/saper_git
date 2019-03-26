cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lpthread")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
project (Saper)
find_package(Poco REQUIRED COMPONENTS Foundation Net Zip )
find_package(SFML  REQUIRED graphics window system)
add_executable(Saper Saper.cpp
 	 src/MinesweeperBoard/MinesweeperBoard.cpp
     src/MinesweeperBoard/MSBoardTextView.cpp
     
     
     src/MSBoardInput.cpp
     src/MSSFMLView.cpp
     
     
     src/WindowStates/FileIO/FileInformation/FileInformation.cpp
     src/WindowStates/FileIO/FileManager.cpp
     
     
     src/WindowStates/Game.cpp
     src/WindowStates/InGameMenu.cpp
     src/WindowStates/LoadingScreen.cpp
     src/WindowStates/MainMenu.cpp
     
     
     src/WindowStates/MainMenu/Background.cpp
     src/WindowStates/MainMenu/Exit.cpp
     src/WindowStates/MainMenu/NewGame.cpp
     src/WindowStates/MainMenu/Options.cpp
     
     src/WindowStates/LoadSprite/texturebackend/SpriteOptions.cpp
     src/WindowStates/LoadSprite/texturebackend/TextureLoad.cpp
     src/WindowStates/LoadSprite/Object.cpp
     src/WindowStates/LoadSprite/RenderClass.cpp)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Saper ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(Saper sfml-system sfml-window sfml-graphics sfml-audio)
endif()
target_link_libraries(Saper Poco::Foundation Poco::Util Poco::Net)

