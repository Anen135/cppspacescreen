#include "stars.h"

char *scoutShip[] = {
    "   __",
    "==|==>==",
    "  /__\\"
};

char **scoutShipFrames[] = { scoutShip };


char *gasPlanet[] = {
    "   _____  ",
    " _(     )_",
    "(_  @@@  _)",
    "  (__ __)"
};

char **gasPlanetFrames[] = { gasPlanet };

char *ship[] = {
    "   /\\  ",
    "==[==]==>",
    "   \\/  "
};

char **shipFrames[] = { ship };

char *satellite1[] = {
    "===[#]==="
};

char *satellite2[] = {
    "===[ ]==="
};

char **satelliteFrames[] = { satellite1 , satellite2};

char *planet1[] = {
    " (@@@) ",
    "( @@@ )",
    " (@@@) "
};
char **planetFrames[] = { planet1 };

char *asteroid1[] = {
    " (oO) ",
    "< oo >",
    " (oO) "
};
char *asteroid2[] = {
    " (Oo) ",
    "< oo >",
    " (Oo) "
};
char *asteroid3[] = {
    " (oo) ",
    "< Oo >",
    " (oo) "
};
char **asteroidFrames[] = { asteroid1, asteroid2, asteroid3 };

// Гарпф мигает!
char *garpf1[] = {
    " \\o_o/ ",
    "  /|\\  ",
    "  / \\  "
};
char *garpf2[] = {
    " \\^_^/ ",
    "  /|\\  ",
    "  / \\  "
};
char **garpfFrames[] = { garpf1, garpf2 };

// Конструктор
SpaceObject createObject(char ***frames, int totalFrames, int height, int frameDelay, int x, int y, int vx, int vy) {
    SpaceObject obj;
    obj.frames = frames;
    obj.totalFrames = totalFrames;
    obj.height = height;
    obj.frameDelay = frameDelay;
    obj.x = x;
    obj.y = y;
    obj.vx = vx;
    obj.vy = vy;
    obj.currentFrame = 0;
    obj.tickCounter = 0;
    obj.active = 0;
    obj.spawnCooldown = 100 + rand() % 300;
    return obj;
}

void initObjects() {
    objects[0] = createObject(satelliteFrames, 2, 1, 8,  rand() % WIDTH, rand() % (HEIGHT - 1), -1, 0);
    objects[1] = createObject(planetFrames,    1, 3, 10, rand() % WIDTH, rand() % (HEIGHT - 3), -1, 0);
    objects[2] = createObject(asteroidFrames,  3, 3, 5,  rand() % WIDTH, rand() % (HEIGHT - 3), -1, 0);
    objects[3] = createObject(garpfFrames,     2, 3, 15, rand() % WIDTH, rand() % (HEIGHT - 3), -1, 0);
    objects[4] = createObject(scoutShipFrames, 1, 3, 10, rand() % WIDTH, rand() % (HEIGHT - 3), -1, 0);
    objects[5] = createObject(gasPlanetFrames, 1, 4, 12, rand() % WIDTH, rand() % (HEIGHT - 4), -1, 0);
    objects[6] = createObject(shipFrames,      1, 3, 10, 5, HEIGHT / 2 - 1, 0, 0); // основной корабль
    objects[6].active = 1; // активируем основной корабль сразу
    objects[6].spawnCooldown = 0; // не ждать появления
}
