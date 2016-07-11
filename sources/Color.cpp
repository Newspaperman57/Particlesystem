#include "Color.h"

Color::Color() {
	printf("Color instantiated\n");
}

Color::Color(uint8_t R, uint8_t G, uint8_t B) {
	Color(R, G, B, 255);
}

Color::Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A) {
	this->R = R;
	this->B = B;
	this->G = G;
	this->A = A;
}

Color::~Color() {

}

bool Color::operator!=(Color other) {
	return !(*this == other);
}

bool Color::operator==(Color other)
{
    if( this->R == other.R &&
    	this->G == other.G &&
    	this->B == other.B &&
    	this->A == other.A)
    	return true;
    else
    	return false;
}

void Color::operator=(Color other)
{
    this->R = other.R;
	this->B = other.B;
	this->G = other.G;
	this->A = other.A;
}