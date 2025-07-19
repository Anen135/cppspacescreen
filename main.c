#include "screensaver.h"
#include "winapi.h"

int main() {
    int cols, rows;
    if (get_console_size(&cols, &rows)) {
        WIDTH = cols-5;
        HEIGHT = rows-5;
    } else {
        printf("Can't get console size\n");
        WIDTH = 25;
        HEIGHT = 25;
    }
    srand(time(NULL));
    initStars();
    initObjects();

    printf("\033[?25l");

    while (1) {
        drawScene();
        updateObjects();
        moveStarsRight();
        usleep(100000); // 0.1 сек
    }

    // Вернуть курсор при выходе (никогда не произойдет пока)
    printf("\033[?25h");

    return 0;
}
