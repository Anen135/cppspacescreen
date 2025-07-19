#include "stars.h"

void moveStarsRight() {
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].x -= 1;
        if (stars[i].x < 0) {
            stars[i].x = WIDTH - 1;
            stars[i].y = rand() % HEIGHT;
            stars[i].big = rand() % 10 == 0;
        }
    }
}

void moveStarsLeft() {
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].x += 1;
        if (stars[i].x >= WIDTH) {
            stars[i].x = 0;
            stars[i].y = rand() % HEIGHT;
            stars[i].big = rand() % 10 == 0;
        }
    }
}

void moveStarsUp() {
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].y -= 1;
        if (stars[i].y < 0) {
            stars[i].y = HEIGHT - 1;
            stars[i].x = rand() % WIDTH;
            stars[i].big = rand() % 10 == 0;
        }
    }
}

void moveStarsDown() {
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].y += 1;
        if (stars[i].y >= HEIGHT) {
            stars[i].y = 0;
            stars[i].x = rand() % WIDTH;
            stars[i].big = rand() % 10 == 0;
        }
    }
}