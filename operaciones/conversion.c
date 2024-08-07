#include <stdio.h> // Para sprintf
#include <stdlib.h> // Para strtol
#include <math.h> // Para floor y log10


void float_to_string(float num, char *buffer) {
    sprintf(buffer, "%.6f", num); // Ajusta la precisión según necesites
}

char* int_to_str(int num, char *buffer, int base) {
    if (base < 2 || base > 36) {
        buffer[0] = '\0'; // base no soportada
        return buffer;
    }

    char *ptr = buffer, *ptr1 = buffer, tmp_char;
    int tmp_value;

    do {
        tmp_value = abs(num % base);
        num /= base;
        if (tmp_value > 9)
            *ptr++ = (tmp_value - 10) + 'a';
        else
            *ptr++ = tmp_value + '0';
    } while (num);

    if (base == 10 && num < 0) *ptr++ = '-';
    *ptr-- = '\0';

    // Invertir la cadena
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return buffer;
}

int str_to_int(const char *str, int base) {
    char *endptr;
    return strtol(str, &endptr, base);
}

int bin_to_int(const char *bin) {
    int num = 0;
    while (*bin) {
        num = num * 2 + (*bin++ - '0');
    }
    return num;
}

int hex_to_int(const char *hex) {
    int num = 0;
    while (*hex) {
        char c = *hex++;
        int val = (c >= '0' && c <= '9') ? c - '0' :
                  (c >= 'a' && c <= 'f') ? c - 'a' + 10 :
                  c - 'A' + 10;
        num = num * 16 + val;
    }
    return num;
}
