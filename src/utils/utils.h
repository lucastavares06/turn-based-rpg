#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

void print(char *message);

void println(char *message);

int read_int(void);

bool read_string(char *buffer, int size);

bool safe_copy_string(char *dest, const char *src, int max_size);

char *join_str(char *first_value, char *second_value);

float random_float(float min, float max);

int random_int(int min, int max);

void seed_random(void);

void clear_input_buffer(void);

#endif
