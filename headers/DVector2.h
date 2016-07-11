#ifndef __DVECTOR2
#define __DVECTOR2

#include "Vector2.h"

class DVector2
{
public:
	DVector2();
	DVector2(double X, double Y);
	~DVector2();
	double X;
	double Y;
	Vector2 ToVector2();
	// TODO Get length
	// TODO Normalize
	// TODO Rotate
	// TODO Scale
	// TODO Add
	// TODO Subtract
};

#endif