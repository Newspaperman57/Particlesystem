#ifndef _PARTICLE_
#define _PARTICLE_

#include <cmath>
#include <iostream>
#include "vector.h"
#include "consts.h"
#include "color.h"

using namespace std;
/*
 * Particle. Contains position, size and velocity
 *
 */

class Particle 
{
private:
    static int particles;
    static double wallHitVelLoss;
    static double airResistance;
    static bool hardWalls;
public:
    Color color;
    Vector vel;
    Vector pos;
    double weight;
    Particle();
    ~Particle();
    static int GetTotalParticles();
    void Tick(int, int);
    double GetDistanceTo(Vector);
};

#endif