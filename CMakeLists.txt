cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lpthread")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
project (Saper)
find_package(SFML  REQUIRED graphics window system)
add_executable(Saper Saper.cpp
 	 src/MinesweeperBoard/MinesweeperBoard.cpp
     src/MinesweeperBoard/MSBoardTextView.cpp
     src/MinesweeperBoard/MSTextController.cpp
     src/sfml/sfmlimplementation.cpp)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Saper ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(Saper sfml-system sfml-window sfml-graphics sfml-audio)
endif()

