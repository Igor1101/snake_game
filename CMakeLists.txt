cmake_minimum_required(VERSION 3.5)
project(snake LANGUAGES CXX)
set(SNAKE_PORT_FILE unix)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake main.cpp snake_game.cpp snake.cpp food.cpp maze.cpp ports/${SNAKE_PORT_FILE}.cpp )
target_link_libraries(snake ncurses)
