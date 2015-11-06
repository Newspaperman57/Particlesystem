#include <iostream>
#include <cmath>
#include <ctime>
#include <SDL2/SDL.h>

using namespace std;

int Pythagoras(double x, double y, double x1, double y1) {
    return sqrt(pow(x1-x, 2)+pow(y1-y, 2));
}

SDL_Window* Window;
SDL_Renderer* Renderer;

bool Init() { 
    bool success = true; 
    SDL_Init( SDL_INIT_VIDEO );
    SDL_CreateWindowAndRenderer(10, 10, SDL_WINDOW_SHOWN, &Window, &Renderer );
    return success;
}

int main(int args, char* argc[])
{
    cout << "Printing byte data as int from SDL_Renderer" << endl;
    // Print single byte until Segfault
    int i = 0;
    while(true)
    {
        cout << (int)Window[i] << " ";
        i++;
    }
    return 0;
}