#ifndef _CONSTS_
#define _CONSTS_

#define DISABLE_SDL

enum {
    PERPARTICLE,
    STATICGRID
};

const int SIZE = 2000;
const double SPEED = 0.5;
const int FPS = 60;
//const int GRAVITY = 0.98;
const double GRAVITY = 0;
const int PIXELSIZE = 2;
const double distanceImportance = 0.01;
const double reflectionPower = 1.3;
const double maxVel = 10;
const int gravityMode = PERPARTICLE;

#endif