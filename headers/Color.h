#ifndef __COLOR
#define __COLOR

#include <cstdint>
#include <stdio.h>

class Color
{
public:
	Color();
	Color(uint8_t R, uint8_t G, uint8_t B);
	Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
	~Color();
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t A; // Gennemsigtighed
	bool operator==(Color other);
	bool operator!=(Color other);
	void operator=(Color other);

};

#endif