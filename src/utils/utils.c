#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void print(const char *message) {
    printf("%s", message);
}

void println(const char *message) {
    printf("%s\n", message);
}

int read_int() {
    int value;
    char trash;

    if (scanf("%d%c", &value, &trash) != 2 || trash != '\n') {
        value = -1;
    }
    clear_input_buffer();
    return value;
}
int random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

char *join_str(const char *first_value, const char *second_value) {
    if (!first_value || !second_value) return NULL;

    const size_t len1 = strlen(first_value);
    const size_t len2 = strlen(second_value);
    const size_t total_len = len1 + len2 + 1;

    char *result = malloc(total_len);
    if (result == NULL) return NULL;

    memcpy(result, first_value, len1);
    memcpy(result + len1, second_value, len2);
    result[total_len - 1] = '\0';

    return result;
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

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
