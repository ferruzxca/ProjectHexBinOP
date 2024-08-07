#ifndef CONVERSION_H
#define CONVERSION_H

int str_to_int(const char *str, int base);
char* int_to_str(int num, char *str, int base);
int bin_to_int(const char *bin);
int hex_to_int(const char *hex);

#endif
