#include "snake_game.h"
#include "ports/def.h"
#include "snake.h"
snake_game::snake_game()
{
    port_display_init();
    snake_main = snake(width/2, height/2, 2);
}

snake_game::~snake_game()
{
    port_display_deinit();
}

void snake_game::draw()
{
    port_display(width, height, &snake_main);
    port_refresh();
}

void snake_game::input()
{
    int ch = port_getchar_immediate();
    snake_main.input(ch);
}

int snake_game::step()
{
    return snake_main.step();
}
