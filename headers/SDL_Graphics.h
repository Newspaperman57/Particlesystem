#ifndef __SDL_GRAPHICS
#define __SDL_GRAPHICS

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_image.h>
#include "Color.h"
#include "Vector2.h"

class SDL_Graphics
{
private:
	bool closed;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	Color OldColor;
public:
	SDL_Graphics();
	~SDL_Graphics();
	bool IsOpen();
	int SetColor(Color color); 
	bool Open(Vector2 windowSize, std::string title); // Initialize graphics, create window etc.
	void PutPixel(Vector2 position); // Put Pixel on screen
	void PutPixel(Vector2 position, Color color); // Put Pixel on screen with this color
	void DrawRect(Vector2 position, Vector2 size); // Draw rect
	void DrawRect(Vector2 position, Vector2 size, Color color); // Draw rect with this color
	SDL_Texture* LoadImage(std::string path);
	//void RenderTexture(Vector2 position, Image image);
	Vector2 WindowSize(); // Returns size of window
	void Close();
};

#endif