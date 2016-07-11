#include "imagemanager.h"

void Imagemanager_ClearImage(Color** image, Color fillColor, int resX, int resY) {
    for (int j = 0; j < resY; j++){
        for(int i = 0; i < resX; i++) {
            image[i][j] = fillColor;
        }
    }
}


void Imagemanager_FillRect(Color** image, int x, int y, int w, int h, int resX, int resY, Color color) {
    int i, j;
    for(i = 0; i < w; i++) {
        for(j = 0; j < h; j++) {
            Imagemanager_Putpixel(image, i+x, j+y, resX, resY, color);
        }
    }
}

/*
Puts pixel in array. 
If succesful: return 1
If out of bounds: return 0
*/

void Imagemanager_Putpixel(Color** image, int x, int y, int resX, int resY, Color color) {
    if(x > 0 && x < resX-1 && y > 0 && y < resY-1) {
        image[x][y] = color;
    }
}

/*
Writes image to .BNM file
*/
void Imagemanager_WriteToFile(Color** image, char* fileName, int resX, int resY) {
    int i, j;
    FILE *image_file;
    image_file = fopen(fileName,"wb");

    fputs("P6\n", image_file);
    char string[20] = "ERROR";
    sprintf(string, "%d %d\n", resX, resY);
    fputs(string, image_file);
    fputs("255\n", image_file);
    for (j = 0; j < resY; j++){
        for(i = 0; i < resX; i++) {
            fputc(image[i][j].r, image_file);
            fputc(image[i][j].g, image_file);
            fputc(image[i][j].b, image_file);
        }
    }
    fclose(image_file);
}

Color** Imagemanager_AllocatePicture(int x, int y) {
    int i;
    static Color** picture = (Color**)malloc(x*3*sizeof(int));
    for (i = 0; i < x; ++i) {
        picture[i] = (Color*)malloc(y*3*sizeof(int));
    }
    return picture;
}