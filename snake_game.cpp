#include "snake_game.h"
#include "ports/def.h"
#include "snake.h"
#include "maze.h"
snake_game::snake_game()
{
    port_display_init();
    snake_main = snake(maze0.width/2, maze0.height/2, 10);
    int x = port_rand(3, maze0.width/2);
    int y = port_rand(3, maze0.height/2);
    port_print((char*)"food coord x=%d y=%d\n", x, y);

    food0 = food(x, y);
    //food0.coord_set(x, y);
}

snake_game::~snake_game()
{
    port_display_deinit();
    draw();
}

void snake_game::draw()
{
    port_display(maze0.get(0), maze0.width, maze0.height, &snake_main, 1, &food0, 1);
    port_refresh();
}

void snake_game::input()
{
    int ch = port_getchar_immediate();
    snake_main.input(ch);
    if(ch == 'q')
        over = true;
    if(ch == ' ')
        while (1) {
            int c = port_getchar_immediate();
            if(c == ' ')
                break;
        }
}

int snake_game::step()
{
    int stat = snake_main.step(&food0, &maze0, 1);
    if(food0.eaten()) {
        port_print((char*)"food eaten!");
        food0.coord_set(port_rand(1, maze0.width/2), port_rand(1, maze0.height/2));
    }
    if(stat < 0)
        over = true;
    return stat;
}


bool snake_game::shutdown()
{
    return over;
}

