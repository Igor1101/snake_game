#include "food.h"
#include "ports/def.h"

food::food(int x, int y)
{
    this->x = x;
    this->y = y;
    this->capacity = 1;
}

food::food()
{
    this->x = 0;
    this->y = 0;
    this->capacity = 1;
}

bool food::eaten()
{
    if(capacity == 0)
        return true;
    return false;
}

bool food::coord_is(int x, int y)
{
    if((this->x == x) && (this->y == y)) {
        return true;
    }
    return false;
}

void food::coord_set(int x, int y)
{
    this->x = x;
    this->y = y;
    port_print((char*)"food coord x=%d y=%d\n", x, y);
    this->capacity = 1;
}

int food::eat()
{
    int ret = capacity;
    capacity = 0;
    return ret;
}

struct food_params food::params()
{
    struct food_params p;
    p.x = x;
    p.y = y;
    return p;
}
