#ifndef MY_IO_H
#define MY_IO_H

#include <stdarg.h>

void my_printf(const char *format, ...);
void my_scanf(const char *format, ...);

char* int_to_str(int num, char *str, int base);

#endif
