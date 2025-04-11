#include <utils.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void print(char *message) {
    printf("%s", message);
}

void println(char *message) {
    printf("%s\n", message);
}

int read_int(void) {
    char buffer[64];
    if (!fgets(buffer, sizeof(buffer), stdin))
        return -1;

    const size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    char *endptr;
    errno = 0;
    const long value = strtol(buffer, &endptr, 10);

    if (errno != 0 || *endptr != '\0')
        return -1;

    if (value < INT_MIN || value > INT_MAX)
        return -1;

    return value;
}

bool read_string(char *buffer, int size) {
    if (buffer == NULL || size <= 0)
        return false;
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        return true;
    }
    return false;
}

bool safe_copy_string(char *dest, const char *src, int max_size) {
    if (!dest || !src || max_size <= 0)
        return false;
    strncpy(dest, src, max_size);
    dest[max_size - 1] = '\0';
    return true;
}

char *join_str(char *first_value, char *second_value) {
    if (!first_value || !second_value)
        return NULL;

    const size_t len1 = strlen(first_value);
    const size_t len2 = strlen(second_value);
    const size_t total_len = len1 + len2 + 1;

    char *result = malloc(total_len);
    if (result == NULL)
        return NULL;

    memcpy(result, first_value, len1);
    memcpy(result + len1, second_value, len2);
    result[total_len - 1] = '\0';

    return result;
}

float random_float(float min, float max) {
    if (min > max) {
        const float temp = min;
        min = max;
        max = temp;
    }
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

int random_int(int min, int max) {
    if (min > max) {
        const int temp = min;
        min = max;
        max = temp;
    }
    return min + rand() % (max - min + 1);
}

void seed_random(void) {
    const unsigned int seed = (clock() ^ time(NULL));
    srand(seed);
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
