#include <stdio.h>
#include <windows.h>

int get_console_size(int* columns, int* rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        *columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        return 1;
    } else {
        return 0;
    }
}