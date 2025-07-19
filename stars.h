#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int x, y;
    int big; // 0 — маленькая, 1 — большая
} Star;

typedef struct {
    char ***frames;        // Кадры анимации
    int totalFrames;       // Сколько кадров
    int currentFrame;      // Текущий кадр
    int frameDelay;        // Сколько тиков между кадрами
    int tickCounter;       // Счётчик тиков
    int height;
    int active;         // 0 = неактивен, не отрисовывается
    int spawnCooldown;  // Время ожидания перед появлением
    int x, y;
    int vx, vy;            // Скорость
} SpaceObject;



int WIDTH = 80;
int HEIGHT = 24;
#define NUM_STARS 50
#define NUM_OBJECTS 7

SpaceObject objects[NUM_OBJECTS];
Star stars[NUM_STARS];