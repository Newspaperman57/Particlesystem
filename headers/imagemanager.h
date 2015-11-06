#ifndef _IMAGEMANAGER_
#define _IMAGEMANAGER_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "color.h"

using namespace std;

void Imagemanager_WriteToFile(Color**, char*, int, int);
void Imagemanager_ClearImage(Color**, Color, int, int);
Color** Imagemanager_AllocatePicture(int, int);
void Imagemanager_FillRect(Color**, int, int, int, int, int, int, Color);
void Imagemanager_Putpixel(Color**, int, int, int, int, Color);

#endif