#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

void print(const char *message);
void println(const char *message);
char read_digit_char(void);
bool read_string(char *buffer, int size);

#endif
