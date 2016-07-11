#include "SDL_Graphics.h"

SDL_Graphics::SDL_Graphics() {
	printf("SDL_Graphics: instantiated\n");
	closed = true;
	OldColor = Color(0, 0, 0);
}

SDL_Graphics::~SDL_Graphics() {
	printf("SDL_Graphics: Destroyed\n");
	if(closed == false)
		Close();
}

bool SDL_Graphics::IsOpen() {
	return !closed;
}

bool SDL_Graphics::Open(Vector2 windowSize, std::string title) { // Initialize graphics, create window etc.
	printf("SDL_Graphics: Opened\n");
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

	window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize.X, windowSize.Y, SDL_WINDOW_SHOWN );
	if( window == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if( renderer == NULL )
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return false;
	}

	closed = false;
	return true;
}

int SDL_Graphics::SetColor(Color color) { // Returns 0 if color isnt already chosen
	if(color != OldColor) {
		SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
		return 0;
	}
	return 1;
}

void SDL_Graphics::PutPixel(Vector2 position, Color color) { // Put Pixel on screen
	SetColor(color);
	SDL_RenderDrawPoint(renderer, position.X, position.Y);
}

Vector2 SDL_Graphics::WindowSize() { // Returns size of window
	return Vector2();
}

void SDL_Graphics::Close() {
	//Destroy window	
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	closed = true;
}

void SDL_Graphics::DrawRect(Vector2 position, Vector2 size){ // Draw rect

}

void SDL_Graphics::DrawRect(Vector2 position, Vector2 size, Color color){ // Draw rect with this color

}
/*
void SDL_Graphics::DrawImage(Vector2 position, Image image){

}
*/
SDL_Texture* SDL_Graphics::LoadImage(std::string path) {
	//The final texture
	SDL_Texture* texture = NULL;

	//Load image at specified path
	SDL_Surface* surface = IMG_Load( path.c_str() );
	if( surface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	
	//Create texture from surface pixels
    texture = SDL_CreateTextureFromSurface( renderer, surface );
	if( texture == NULL )
	{
		printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	//Get rid of old loaded surface
	SDL_FreeSurface( surface );

	return texture;
}
