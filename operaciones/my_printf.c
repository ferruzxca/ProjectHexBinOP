#include <unistd.h>
#include <stdarg.h>
#include "conversion.h"

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    char *str;
    int intValue;
    float floatValue;
    char floatStr[32];
    char *binStr;
    char *hexStr;

    int index = 0;
    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': // Decimal integer
                    intValue = va_arg(args, int);
                    index += int_to_str(intValue, &buffer[index], 10);
                    break;
                case 's': // String
                    str = va_arg(args, char *);
                    while (*str) {
                        buffer[index++] = *str++;
                    }
                    break;
                case 'f': // Floating-point number
                    floatValue = va_arg(args, double); // float is promoted to double in va_arg
                    float_to_string(floatValue, floatStr);
                    for (char *c = floatStr; *c != '\0'; c++) {
                        buffer[index++] = *c;
                    }
                    break;
                case 'b': // Binary
                    binStr = va_arg(args, char *);
                    while (*binStr) {
                        buffer[index++] = *binStr++;
                    }
                    break;
                case 'x': // Hexadecimal
                    hexStr = va_arg(args, char *);
                    while (*hexStr) {
                        buffer[index++] = *hexStr++;
                    }
                    break;
                default:
                    buffer[index++] = '%';
                    buffer[index++] = *p;
                    break;
            }
        } else {
            buffer[index++] = *p;
        }
    }
    buffer[index] = '\0';

    write(STDOUT_FILENO, buffer, index);

    va_end(args);
}
