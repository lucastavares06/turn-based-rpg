#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

#define INPUT_SIZE 100

void println(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void print(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

char read_digit_char() {
    char input[INPUT_SIZE];

    if (fgets(input, INPUT_SIZE, stdin)) {
        const size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strlen(input) == 1 && isdigit(input[0])) {
            return input[0];
        }
    }

    return '\0';
}
