#include "snake.h"
#include "ports/def.h"

snake::snake(int x, int y, int tail)
{
    dir = eSTOP;
    this->x = x;
    this->y = y;
    if(tail <= tail_defsize) {
        this->tail = tail_defsize;
    }
    else {
        this->tail = tail;
    }
    tail_malloc(this->tail);
    tail_init();
}

snake::snake()
{
    this->x = 0;
    this->y = 0;
    this->tail = tail_defsize;
    dir = eSTOP;
    tail_malloc(tail);
    if(tail_arr == NULL) {
        port_print((char*)"err malloc snake tail");
    }
    tail_init();
}

snake::~snake()
{
    port_free(tail_arr);
}

int snake::step()
{
    tail_step();
    switch (dir) {
    case eSTOP:
        return 0;
    case eUP:
        y--;
        break;
    case eDOWN:
        y++;
        break;
    case eRIGHT:
        x++;
        break;
    case eLEFT:
        x--;
        break;
    }
    return 0;
}

int snake::tail_step()
{
    if(dir == eSTOP)
        return -1;
    for(int i=tail-1; i>0; i--) {
        if(tail_arr[i].x == tail_arr[i-1].x
                && tail_arr[i].y == tail_arr[i-1].y ) {
        } else
            tail_arr[i] = tail_arr[i-1];
    }
    tail_arr[0].x = x;
    tail_arr[0].y = y;
    return 0;
}

void snake::input(int ch)
{
    switch(ch) {
    case 'w':
        switch (dir) {
        case eUP:
        case eLEFT:
        case eRIGHT:
        case eSTOP:
            dir = eUP;
            break;
        default:
            break;
        }
        break;
    case 's':
        switch (dir) {
        case eUP:
        case eRIGHT:
        case eDOWN:
        case eSTOP:
            dir = eRIGHT;
            break;
        default:
            break;
        }
        break;
    case 'z':
        switch (dir) {
        case eDOWN:
        case eRIGHT:
        case eLEFT:
        case eSTOP:
            dir = eDOWN;
            break;
        default:
            break;
        }
        break;
    case 'a':
        switch (dir) {
        case eUP:
        case eLEFT:
        case eDOWN:
        case eSTOP:
            dir = eLEFT;
            break;
        default:
            break;
        }
        break;

    }
}


int snake::tail_realloc(int tparts)
{
    tail_arr = static_cast<struct s_tail_part*> (port_realloc(tail_arr,tparts*sizeof(struct s_tail_part) ));
    if(tail_arr == NULL) {
        port_print((char*)"cant realloc memory");
        return -1;
    }
    return 0;
}

int snake::tail_malloc(int tparts)
{
    if(tail_arr == NULL)
        tail_arr = static_cast<struct s_tail_part*>(port_malloc(tparts*sizeof(struct s_tail_part)));
    else
        tail_realloc(tparts);
    if(tail_arr == NULL) {
        port_print((char*)"cant allocate tail");
        return -1;
    }
    return 0;
}

bool snake::coord_is_me(int x, int y)
{
    if((x == this->x) && (y == this->y)) {
        return true;
    }
    for(int i=0; i<tail; i++) {
        if(tail_arr[i].x == x && tail_arr[i].y == y) {
            return true;
        }
    }
    return false;
}

void snake::tail_init()
{
    tail_arr[0].x = x-1;
    tail_arr[0].y = y;
    for(int i=0; i<tail-1; i++) {
        tail_arr[i+1].x = tail_arr[i].x-1;
        tail_arr[i+1].y = tail_arr[i].y;
    }
}
