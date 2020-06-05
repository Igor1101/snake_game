#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "ports/def.h"
#include "snake.h"
#include "food.h"

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
    int width = 20;
    int height = 20;
    snake snake_main;
public:
    snake_game();
    ~snake_game();
    void draw();
    int step();
    void input();
};

#endif // SNAKE_GAME_H
