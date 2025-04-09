#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print(const char *message) {
    printf("%s", message);
}

void println(const char *message) {
    printf("%s\n", message);
}

char read_digit_char(void) {
    char input[10];
    if (fgets(input, sizeof(input), stdin)) {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        if (len == 1) {
            const unsigned char ch = input[0];
            if (isdigit(ch)) {
                return input[0];
            }
        }
    }
    return '\0';
}

int read_string(char *buffer, const int size) {
    if (buffer == NULL || size <= 0)
        return 0;
    if (fgets(buffer, size, stdin)) {
        const size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        return 1;
    }
    return 0;
}
