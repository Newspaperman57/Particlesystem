#ifndef __PARTICLE
#define __PARTICLE

#include "DVector2.h"
#include "Vector2.h"
#include "Color.h"


class Particle
{
private:
	Color color;
	double weight;
	double size;
	DVector2 position;
	DVector2 velocity;
public:
	Particle(DVector2 position);
	Particle(double X, double Y);
	
	void SetVelocity(DVector2 newVelocity); // Should only be used for resets and intialization
	void AddVelocity(DVector2 addedVelocity);
	DVector2 GetTotalVelocity(); // Add .Length() to get speed

	void SetPosition(DVector2 newPosition);
	void AddPosition(DVector2 addedPosition); // To move the screen around f.eks.
	Vector2 GetPosition(); // Rounded position

};

#endif

// Should contain a position, velocity and optionally a weight, size and color. If not specified, these should be 1 and white