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


int random_number(int min, int max);

/**
 * Clear remaining buffer
 */
void clear_input_buffer();

/**
 * Concatenate two chars \n
 * Max size of return is [100]
 */
char join_str(char first_value[], char second_value[]);

#endif
