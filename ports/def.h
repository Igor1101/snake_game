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
void port_display(int width, int height, snake* s);
void* port_malloc(size_t sz);
void* port_realloc(void*addr, size_t sz);
void port_free(void*addr);
#endif // PORT_DEF_H
