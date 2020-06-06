#ifndef SNAKE_H
#define SNAKE_H
#include <cstddef>
enum edirection {
    eSTOP, eLEFT, eRIGHT, eUP, eDOWN
};

struct snake_params {
    int x, y, tail;
};

struct s_tail_part {
    int x, y;
};

class snake
{
private:
    int x, y;
    int tail;
    enum edirection dir;
    struct s_tail_part* tail_arr = NULL;
    int tail_realloc(int tparts);
    int tail_malloc(int tparts);
    int tail_step();
public:
    static constexpr int tail_defsize = 10;
    snake(int x, int y, int tail);
    snake();
    ~snake();
    int step();
    struct snake_params params()
    {
        struct snake_params p;
        p.x = x;
        p.y = y;
        p.tail = tail;
        return p;
    }
    void input(int ch);
    bool coord_is_head(int x, int y);
    bool coord_is_tail(int x, int y);
    void tail_init();
};

#endif // SNAKE_H
