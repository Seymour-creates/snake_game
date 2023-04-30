cmake_minimum_required(VERSION 3.24)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1_2/lib/cmake")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snake_game main.cpp)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
