#ifndef UTILS_H
#define UTILS_H

void print(const char *message);
void println(const char *message);

/**
 * Waiting for user interaction \n
 * Returns the integer \n
 * Invalid input returns -1
 */
int read_int();
char read_digit_char(void);
int read_string(char *buffer, int size);

#endif
