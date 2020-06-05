#include "snake.h"

snake::snake(int x, int y, int tail)
{
    dir = eSTOP;
    this->x = x;
    this->y = y;
    this->tail = tail;
}

snake::snake()
{
    this->x = 0;
    this->y = 0;
    dir = eSTOP;
}

snake::~snake()
{

}

int snake::step()
{
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
        }
        break;

    }
}
