#include <SDL.h>
#include <iostream>

#include "ResourceManager.h"

SDL_Surface *ResourceManager::loadBitmap(std::string filename)
{
    std::map<std::string, SDL_Surface *>::const_iterator it = surfaceStore.find(filename);

    if (it != surfaceStore.end()) {
        return it->second;
    }

    SDL_Surface *image = SDL_LoadBMP(filename.c_str());

    if (image == NULL) {
        std::cerr << "Cannot load bitmap " << filename << "\n";
        std::cerr << "SDL_GetError: " << SDL_GetError() << "\n";

        return NULL;
    }

    surfaceStore[filename] = image;

    return image;
}


ResourceManager::~ResourceManager()
{
    std::map<std::string, SDL_Surface *>::iterator it;

    for (it = surfaceStore.begin(); it != surfaceStore.end(); it++)
    {
        SDL_FreeSurface(it->second);
    }
}
