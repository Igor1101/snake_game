#include <iostream>
#include "snake_game.h"
using namespace std;

int main()
{
    cout << "snake!" << endl;
    snake_game game;
    for(int i=0; i<1000; i++) {
        game.input();
        game.step();
        game.draw();
        if(game.shutdown()) {
            game.~snake_game();
            return 0;
        }
    }
    game.draw();
    return 0;
}
