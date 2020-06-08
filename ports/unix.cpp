#include "def.h"
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ncurses.h>
#include "../snake_conf.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "../snake.h"

using namespace std;

void port_print(char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}
int port_getchar_immediate(void)
{
    return getch();
}

int port_display_init(void)
{
    system("clear");
    initscr();
    noecho();
    raw();
    timeout(SNAKE_DELAY_MS);
    srand(time(NULL));
    return 0;
}

int port_display_deinit(void)
{
    echo();
    endwin();
    return 0;
}
void port_putpixel()
{

}
void port_refresh()
{
    refresh();
}

static bool is_tail(snake* snakes, int snakes_amount, int x, int y)
{
    for(int i=0; i<snakes_amount; i++) {
        if(snakes[i].coord_is_tail(x, y)) {
            return true;
        }
    }
    return false;
}

static bool is_head(snake* snakes, int snakes_amount, int x, int y)
{
    for(int i=0; i<snakes_amount; i++) {
        if(snakes[i].coord_is_head(x, y)) {
            return true;
        }
    }
    return false;
}

static bool is_food(food* f, int food_amount, int x, int y)
{
    for(int i=0; i<food_amount; i++) {
        if(f[i].coord_is(x, y)) {
            return true;
        }
    }
    return false;
}

void port_display(const char** maze, int width, int height, snake* snakes, int snakes_amount,
                  food* f, int food_amount)
{
    system("clear");
    //for(int i=0; i<width; i++) {
    //    cout << "#";
    //}
    cout << "\r\n";
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            //if(x==0 || x == width - 1)
            //    cout << "#";
            if(maze[x][y] != ' ')
                cout << "#";
            else if(is_food(f, food_amount, x, y))
                cout << "F";
            else if(is_head(snakes, snakes_amount, x, y))
                cout << "0";
            else if(is_tail(snakes, snakes_amount, x, y))
                cout << "*";
            else
                cout << " ";
        }
        cout << "\r\n";
    }
    //for(int i=0; i<width; i++) {
    //    cout << "#";
    //}
    snake_params sp = snakes->params();
    cout << "snake: x=" << sp.x << "y=" << sp.y << "tail=" << sp.tail << "\n\r";
    cout << "food: x=" << f->params().x << "y=" << f->params().y << "\n\r";
    cout << "\r\n";
    fflush(stdout);
}

void* port_malloc(size_t sz)
{
    return malloc(sz);
}
void* port_realloc(void*addr, size_t sz)
{
    return realloc(addr, sz);
}
void port_free(void*addr)
{
    free(addr);
}

int port_rand(int from, int to)
{
    return (from+rand() / (RAND_MAX / (to - from + 1) + 1));
}

void port_exit(void)
{
    exit(0);
}

void port_sleep_sec(int s)
{
    sleep(s);
}
