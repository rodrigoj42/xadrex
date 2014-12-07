#include <iostream>

#include "ChessGame.h"
#include "Control.h"

ChessGame::ChessGame(SDL_Window* window) : Game(window)
{

}

void ChessGame::onMouseMove(int x, int y)
{
    //std::cout << "onMouseMove(" << x << ", " << y << ")\n";
    m_controlManager.onMouseMove(x, y);
}

void ChessGame::onMouseDown(int x, int y)
{
    std::cout << "onMouseDown(" << x << ", " << y << ")\n";
    m_controlManager.onMouseDown(x, y);
}

void ChessGame::onMouseUp(int x, int y)
{
    std::cout << "onMouseUp(" << x << ", " << y << ")\n";
    m_controlManager.onMouseUp(x, y);
}

void ChessGame::draw()
{
    SDL_Surface* screenSurface = SDL_GetWindowSurface(m_window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

    SDL_UpdateWindowSurface(m_window);
}
