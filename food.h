#ifndef FOOD_H
#define FOOD_H

struct food_params {
    int x;
    int y;
};

class food
{
private:
    volatile int x,y;
    volatile int capacity = 0;
public:
    food(int x, int y);
    food();
    bool coord_is(int x, int y);
    bool eaten();
    void coord_set(int x, int y);
    int eat();
    struct food_params params();
};

#endif // FOOD_H
