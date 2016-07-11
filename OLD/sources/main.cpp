#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

#include "consts.h"

#ifndef DISABLE_SDL
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#endif

#include "threading.h"
#include "vector.h"
#include "imagemanager.h"
#include "particle.h"

const int SCREENSIZEX = 1000+20;
const int SCREENSIZEY = 500+20;

Particle particles[SIZE];

using namespace std;

#ifndef DISABLE_SDL
SDL_Window* Window;
SDL_Renderer* Renderer;
#endif

Color** image;

Color WHITE = {255, 255, 255};
Color BLACK = {0  , 0  , 0  };
Color BLUE =  {0  , 0  , 255};

#ifndef DISABLE_SDL
bool Init() { 
    bool success = true; 
    SDL_Init( SDL_INIT_VIDEO );
    SDL_CreateWindowAndRenderer(SCREENSIZEX, SCREENSIZEY, SDL_WINDOW_SHOWN, &Window, &Renderer );
    return success;
} 
#endif

void Putpixel(Vector pos, Color color, int size) {
    
    #ifndef DISABLE_SDL
    SDL_Rect* rect = new SDL_Rect;
    rect->x = pos.x-(size/2);
    rect->y = pos.y-(size/2);
    rect->w = size;
    rect->h = size;
    SDL_SetRenderDrawColor(Renderer, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(Renderer, rect); //Renders on middle of screen.
    #endif
    Imagemanager_FillRect(image, pos.x, pos.y, size, size, SCREENSIZEX, SCREENSIZEY, color);
}

int main(int args, char* argc[]) {
    //srand (time(NULL));
    srand(250);

    Vector pos;
    //SDL_Thread* threads[SIZE];
    
    #ifndef DISABLE_SDL
    assert(Init());
    #endif

    image = Imagemanager_AllocatePicture(SCREENSIZEX+20, SCREENSIZEY+20);
    // Init all particles

    for (int i = 0; i < SIZE; ++i)
    {
        pos.x = (rand() % SCREENSIZEX/8) + SCREENSIZEX/2-SCREENSIZEX/8;
        pos.y = (rand() % SCREENSIZEY/8) + SCREENSIZEY/2-SCREENSIZEY/8;

        particles[i].pos = pos;
        particles[i].weight = (rand() % 1) + 2;
        //if(!(rand()%100))
        //    particles[i].weight = 15;
        particles[i].color.TO_HSV(i*70, 255, 255);
    }
    /*
    particles[0].weight = 40;
    
    particles[0].pos.x = 0;
    particles[0].pos.y = 0;

    particles[0].vel.x = 0;
    particles[0].vel.y = 0;
    
    particles[1].pos.x = 100;
    particles[1].pos.y = 100;

    particles[1].vel.x = 0;
    particles[1].vel.y = 0;
    
    particles[2].pos.x = 100;
    particles[2].pos.y = 100;

    particles[2].vel.x = 0;
    particles[2].vel.y = 0;
    
    particles[3].pos.x = 300;
    particles[3].pos.y = 0;

    particles[3].vel.x = -16;
    particles[3].vel.y = 0;
    
    particles[1].pos.x = 200;
    particles[1].pos.y = 220;

    particles[2].pos.x = 220;
    particles[2].pos.y = 220;
    
    particles[3].pos.x = 220;
    particles[3].pos.y = 200;
    */
    bool end = false;

    #ifndef DISABLE_SDL

    SDL_Event e;
            
    SDL_Rect* windowRect = new SDL_Rect;
    windowRect->x = 0;
    windowRect->y = 0;
    windowRect->w = SCREENSIZEX;
    windowRect->h = SCREENSIZEY;

    #endif // DISABLE_SDL


    #ifndef NDEBUG
        Vector v1;
        Vector v2;
        v1.x = 2;
        v1.y = 2;
        v2.x = 1;
        v2.y = 1;
        Vector v3;
        Vector v4;
        v3 = v1 + v2;
        assert(v3.x == 3);
        assert(v3.y == 3);
        v3 = v1 - v2;
        assert(v3.x == 1);
        assert(v3.y == 1);
        
        v3 = v1 * 2;
        v4 = v1;
        v4 *= 2;
        assert(v3 == v4);

        v3 = v1 / 2;
        v4 = v1;
        v4 /= 2;
        assert(v3 == v4);


        pos.x = 10;
        pos.y = 10;
        double len1 = pos.GetLength();
        pos.Rotate(1231);
        assert(len1 == pos.GetLength());

    #endif // NDEBUG
    #ifndef DISABLE_SDL
        SDL_RenderClear(Renderer);
    #endif // DISBALE_SDL
    // LoopStart
    int ticks = 0;
    //int lastFrame = SDL_GetTicks();
    
    #ifndef DISABLE_SDL
    bool mousePressed = false;
    #endif
    
    while(!end)
    {
        ticks++;
        #ifndef DISABLE_SDL
        while( SDL_PollEvent( &e ) != 0 ) 
        { 
            if( e.type == SDL_QUIT ) 
            {
                end = true; 
            } else if(e.type == SDL_MOUSEBUTTONDOWN) {
                mousePressed = false;
            } else if(e.type == SDL_MOUSEBUTTONUP) {
                mousePressed = false;
            }
        }
        if(mousePressed) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            particles[0].pos.x = mouseX;
            particles[0].pos.y = mouseY;
        }
        #endif

        Vector direction;
        double length;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if(j != i) {
                    direction = particles[i].pos - particles[j].pos;
                    length = direction.GetLength();
                    direction.Normalize();
                    if(length == 0) {
                        direction.x = (double)((rand()%10)-5)/10;
                        direction.y = (double)((rand()%10)-5)/10;
                    }
                    if(length < 2)
                        length = 2;
                    
                    direction *= 1/(length*length);
                    particles[i].vel += direction*SPEED*pow(particles[j].weight/particles[i].weight, 2);
                }
            }
            if(particles[i].vel.GetLength() > maxVel) {
                particles[i].vel.x /= particles[i].vel.GetLength()/maxVel;
                particles[i].vel.y /= particles[i].vel.GetLength()/maxVel;
            }
            particles[i].vel.y += GRAVITY*SPEED; // Gravity if set
        }
        
        for (int i = 0; i < SIZE; ++i)
        {
            particles[i].Tick(SCREENSIZEX-20, SCREENSIZEY-20);
            Putpixel(particles[i].pos, particles[i].color, particles[i].weight);
        }
        //if(FPS == 0 || (SDL_GetTicks() - lastFrame) > 1000/(double)FPS || true) {
            //lastFrame = SDL_GetTicks();

            #ifndef DISABLE_SDL
            SDL_RenderPresent(Renderer);
            #endif

            string str = to_string(ticks);
            if(ticks < 10)
                str = "0000" + str;
            else if(ticks < 100)
                str = "000" + str;
            else if(ticks < 1000)
                str = "000" + str;
            else if(ticks < 10000)
                str = "0" + str;
            str = "output/" + str + ".pnm";

            Imagemanager_WriteToFile( image, (char*)str.c_str(), SCREENSIZEX, SCREENSIZEY );
            #ifndef DISABLE_SDL
            SDL_SetRenderDrawColor(Renderer, BLACK.r, BLACK.g, BLACK.b, 0);
            SDL_RenderClear(Renderer);
            #endif
            Imagemanager_ClearImage(image, BLACK, SCREENSIZEX, SCREENSIZEY);
            cout << "Tick " << ticks << "/" << 50/SPEED << endl;
        //}
        if(ticks >= 50/SPEED) {
            end = true;
        }
    }
    #ifndef DISABLE_SDL
    SDL_RenderPresent(Renderer);
    //SDL_Delay(3000);
    // LoopEnd
    SDL_DestroyRenderer( Renderer );
    SDL_DestroyWindow( Window );

    SDL_Quit();
    #endif
}