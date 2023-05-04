cmake_minimum_required(VERSION 3.24)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1_2/lib/cmake")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snake_game src/main.cpp include/State.hpp include/StateMan.hpp src/StateMan.cpp src/assetMan.cpp include/assetMan.hpp src/game.cpp include/game.hpp src/mainMenu.cpp include/mainMenu.hpp)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
