#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "ports/def.h"
#include "snake.h"
#include "food.h"
#include "maze.h"

enum eRegionType{
    eEmpty,
    eFood,
    eBorder,
    eTail,
    eSnake1,
    eSnake2,
    eSnake3,
    eSnake4,
    eSnake5,
    eSnake6
};

class snake_game
{
private:
    snake snake_main;
    food food0;
    bool over = false;
    maze maze0;
public:
    snake_game();
    ~snake_game();
    bool shutdown();
    void draw();
    int step();
    void input();
};

#endif // SNAKE_GAME_H
