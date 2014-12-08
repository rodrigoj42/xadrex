#include <SDL.h>
#include <iostream>

#include "ChessGame.h"
#include "Settings.h"

int main( int argc, char* args[] )
{
	SDL_Window* window = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Cannot initialize STL" << "\n";
		std::cerr << "SDL_GetError: " << SDL_GetError() << "\n";

		return 0;
	}

	window = SDL_CreateWindow("Xadrex", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Settings::SCREEN_WIDTH, Settings::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
    {
        std::cerr << "Cannot create window" << "\n";
        std::cerr << "SDL_GetError: " << SDL_GetError() << "\n";

        SDL_Quit();

        return 0;
    }

    {
        ChessGame game(window);

        game.run();
    }

	SDL_DestroyWindow(window);

	SDL_Quit();

    return 0;
}
