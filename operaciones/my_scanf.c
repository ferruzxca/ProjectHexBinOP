#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "conversion.h"

void my_scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    int index = 0;
    read(STDIN_FILENO, buffer, sizeof(buffer));

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': // Decimal integer
                    {
                        int *intPtr = va_arg(args, int *);
                        *intPtr = str_to_int(buffer + index, 10);
                        while (buffer[index] != ' ' && buffer[index] != '\n') {
                            index++;
                        }
                    }
                    break;
                case 's': // String
                    {
                        char *str = va_arg(args, char *);
                        int strIndex = 0;
                        while (buffer[index] != '\n' && buffer[index] != ' ') {
                            str[strIndex++] = buffer[index++];
                        }
                        str[strIndex] = '\0';
                    }
                    break;
                case 'f': // Floating-point number
                    {
                        float *floatPtr = va_arg(args, float *);
                        char floatStr[32];
                        int floatIndex = 0;
                        while (buffer[index] != ' ' && buffer[index] != '\n') {
                            floatStr[floatIndex++] = buffer[index++];
                        }
                        floatStr[floatIndex] = '\0';
                        *floatPtr = atof(floatStr); // Using standard atof for simplicity
                    }
                    break;
                default:
                    break;
            }
            index++;
        }
    }

    va_end(args);
}
