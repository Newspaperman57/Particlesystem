#include "DVector2.h"

DVector2::DVector2() {

}

DVector2::DVector2(double X, double Y) {
	this->X = X;
	this->Y = Y;
}

DVector2::~DVector2() {

}

Vector2 DVector2::ToVector2() {
	return Vector2((int)(X+0.5), (int)(Y+0.5));
}
