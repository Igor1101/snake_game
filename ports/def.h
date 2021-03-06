#ifndef PORT_DEF_H
#define PORT_DEF_H
// def_h
#include "../snake.h"
#include <stddef.h>
void port_print(char* format, ...);
int port_getchar_immediate(void);
int port_display_init(void);
int port_display_deinit(void);
void port_putpixel();
void port_refresh();
void port_display(const char** maze, int width, int height, snake* snakes, int snakes_amount,
                  food* f, int food_amount);
void* port_malloc(size_t sz);
void* port_realloc(void*addr, size_t sz);
void port_free(void*addr);
int port_rand(int from, int to);
void port_exit(void);
void port_sleep_sec(int s);
#endif // PORT_DEF_H
