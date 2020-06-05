cmake_minimum_required(VERSION 3.5)

project(snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake main.cpp snake_game.cpp snake.cpp food.cpp ports/unix.cpp)
target_link_libraries(snake ncurses)
