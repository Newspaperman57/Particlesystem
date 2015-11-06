#include "particle.h"

int Particle::particles = 0;
double Particle::wallHitVelLoss = 0.1;
double Particle::airResistance = 0.2;//0.2;
bool Particle::hardWalls = true;

Particle::Particle() {
    particles++;
    vel.x = 0;
    vel.y = 0;
    weight = 2;
}

Particle::~Particle() {
    particles--;
}

int Particle::GetTotalParticles() {
    return particles;
}

void Particle::Tick(int screenSizeX, int screenSizeY) {
    pos = pos + (vel*SPEED);
    if(pos.x >= screenSizeX){
        if(hardWalls) {
            pos.x -= 2*(pos.x-screenSizeX);
            vel.x *= -1+wallHitVelLoss;
        } else {
            pos.x -= screenSizeX;
        }
    }
    
    if(pos.y >= screenSizeY){
        if(hardWalls) {
            pos.y -= 2*(pos.y-screenSizeY);
            vel.y *= -1+wallHitVelLoss;
        } else {
            pos.y -= screenSizeY;
        }
    }

    if(pos.x < 0){
        if(hardWalls) {
            pos.x *= -1;
            vel.x *= -1+wallHitVelLoss;
        } else {
            pos.x += screenSizeX;
        }
    }
    
    if(pos.y < 0){
        if(hardWalls) {
            pos.y *= -1;
            vel.y *= -1+wallHitVelLoss;
        } else {
            pos.y += screenSizeY;
        }
    }

    color.TO_HSV(vel.GetLength()*16, 255, 255);

    vel *= 1-(pow(airResistance, 2)*SPEED/pow(weight, 2));
}

double Particle::GetDistanceTo(Vector pos2) {
    return Vector::GetDistance(pos, pos2);
}