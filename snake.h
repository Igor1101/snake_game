#ifndef SNAKE_H
#define SNAKE_H

enum edirection {
    eSTOP, eLEFT, eRIGHT, eUP, eDOWN
};

struct snake_params {
    int x, y, tail;
};

class snake
{
private:
    int x, y;
    int tail;
    enum edirection dir;
public:
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
};

#endif // SNAKE_H
