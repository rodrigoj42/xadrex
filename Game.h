#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include "Settings.h"

class Game
{
protected:
    SDL_Window *m_window;
    virtual void onMouseMove(int x, int y) = 0;
    virtual void onMouseDown(int x, int y) = 0;
    virtual void onMouseUp(int x, int y) = 0;

public:
    Settings settings;

    Game(SDL_Window *window);

    void run();
    virtual void draw() = 0;
};

#endif // GAME_H_INCLUDED
