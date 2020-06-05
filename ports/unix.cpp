#include "def.h"
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ncurses.h>
#include "../snake_conf.h"
#include <iostream>
#include "../snake.h"

using namespace std;

void port_print(char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
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

void port_display(int width, int height, snake* s)
{
    system("clear");
    for(int i=0; i<width; i++) {
        cout << "#";
    }
    cout << "\r\n";
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(j==0 || j == width - 1)
                cout << "#";
            else if(s->params().x == j && s->params().y == i)
                cout << "0";
            else
                cout << " ";
        }
        cout << "\r\n";
    }
    for(int i=0; i<width; i++) {
        cout << "#";
    }
    cout << "\r\n";
}
