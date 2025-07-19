#include "stars.h"
#include "starmovemend.h"
#include "spaceObjects.h"

void initStars() {
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].x = rand() % WIDTH;
        stars[i].y = rand() % HEIGHT;
        stars[i].big = rand() % 10 == 0; // 10% шанса, что звезда большая
    }
}

void drawArt(char **art, int artHeight, int x, int y, char screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < artHeight; ++i) {
        const char *line = art[i];
        for (int j = 0; line[j]; ++j) {
            if (line[j] != ' ') {
                int drawX = x + j;
                int drawY = y + i;
                if (drawX >= 0 && drawX < WIDTH && drawY >= 0 && drawY < HEIGHT)
                    screen[drawY][drawX] = line[j];
            }
        }
    }
}

void updateObjects() {
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        if (!objects[i].active) {
            // Уменьшаем таймер появления
            if (--objects[i].spawnCooldown <= 0) {
                objects[i].active = 1;
                objects[i].x = WIDTH + rand() % 40;
                objects[i].y = rand() % (HEIGHT - objects[i].height);
            }
            continue;
        }

        // Обновление позиции
        objects[i].x += objects[i].vx;
        objects[i].y += objects[i].vy;

        // Анимация
        objects[i].tickCounter++;
        if (objects[i].tickCounter >= objects[i].frameDelay) {
            objects[i].tickCounter = 0;
            objects[i].currentFrame = (objects[i].currentFrame + 1) % objects[i].totalFrames;
        }

        // Ушёл за экран — отключить
        if (objects[i].x < -20) {
            objects[i].active = 0;
            objects[i].spawnCooldown = 100 + rand() % 300; // от 1 до 4.5 секунд (при 30 FPS)
        }
    }
}



void drawScene() {
    char screen[HEIGHT][WIDTH];
    char consoleBuffer[(WIDTH + 1) * HEIGHT + 1]; // +1 для \0

    // Заполнить пробелами
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            screen[y][x] = ' ';

    // Отрисовать звезды
    for (int i = 0; i < NUM_STARS; ++i) {
        char ch = stars[i].big ? '+' : '*';
        screen[stars[i].y][stars[i].x] = ch;
    }

    // Отрисовать объекты
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        if (!objects[i].active) continue;
        drawArt(
            objects[i].frames[objects[i].currentFrame],
            objects[i].height,
            objects[i].x,
            objects[i].y,
            screen
        );
    }


    // Переносим в consoleBuffer
    int idx = 0;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            consoleBuffer[idx++] = screen[y][x];
        }
        consoleBuffer[idx++] = '\n';
    }
    consoleBuffer[idx] = '\0';

    // Печатаем всё одной операцией
    printf("\033[H");           // Курсор в начало
    fwrite(consoleBuffer, 1, idx, stdout); // Быстро
}
