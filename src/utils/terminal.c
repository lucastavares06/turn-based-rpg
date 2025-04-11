#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>

    void clear_screen(void)
    {
        system("cls");
    }

void flush_stdin(void)
    {
        HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
        FlushConsoleInputBuffer(h);
    }

void wait_any_key(void)
    {
        flush_stdin();
        printf("\nPress any key to continue...");
        fflush(stdout);
        _getch();
    }

#else
#include <termios.h>
#include <unistd.h>

void clear_screen(void)
    {
        printf("\033[2J\033[H");
        fflush(stdout);
    }

void flush_stdin(void)
    {
        tcflush(STDIN_FILENO, TCIFLUSH);
    }

void wait_any_key(void)
    {
        flush_stdin();
        printf("\nPress ENTER to continue...");
        fflush(stdout);
        getchar();
    }
#endif
