#ifndef MAZE_H
#define MAZE_H
#include <cstddef>
#include <string>

using namespace std;
class maze
{
private:
    int curblk;
    const char *arr[20] = {
        "####################",
        "#   #         #    #",
        "#  #         #     #",
        "#                  #",
        "#      #           #",
        "#              #   #",
        "#     #            #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#     #            #",
        "#     #            #",
        "#     #            #",
        "#     #            #",
        "####################"
    };
public:
    const int width = 20;
    const int height = 20;
    const char** get(int num)
    {
        switch (num) {
        case 0:
            return arr;
        default:
            return NULL;
        }
    }
    maze();
};

#endif // MAZE_H
