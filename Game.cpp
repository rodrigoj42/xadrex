#include <lua.hpp>
#include <iostream>

#include "Game.h"

Game::Game(SDL_Window *window)
{
    m_window = window;
}

void Game::run()
{
    draw();

    SDL_Event e;
    for (;;) {
        SDL_PollEvent(&e);

        switch (e.type) {
        case SDL_QUIT:
            return;
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(e.motion.x, e.motion.y);
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (e.button.button == SDL_BUTTON_LEFT) {
                onMouseDown(e.button.x, e.button.y);
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (e.button.button == SDL_BUTTON_LEFT) {
                onMouseUp(e.button.x, e.button.y);
            }
            break;
        }
    }
}

