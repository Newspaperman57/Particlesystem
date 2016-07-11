#include "Particle.h"

Particle::Particle(DVector2 position) {
	this->position = position;
}

Particle::Particle(double X, double Y) {
	Particle(DVector2(X, Y));
}

void Particle::SetVelocity(DVector2 newVelocity) {// Should only be used for resets and intialization

}

void Particle::AddVelocity(DVector2 addedVelocity) {

}

DVector2 Particle::GetTotalVelocity() { // Add .Length() to get speed
	return velocity;
}

void Particle::SetPosition(DVector2 newPosition) {

}

void Particle::AddPosition(DVector2 addedPosition) { // To move the screen around f.eks.

}

Vector2 Particle::GetPosition() { // Rounded position
	return position.ToVector2();
}
