#include "ChessGame.h"

ChessGame::ChessGame(SDL_Window* window) : Game(window)
{

}

void ChessGame::onMouseMove(int x, int y)
{

}

void ChessGame::onMouseDown(int x, int y)
{

}

void ChessGame::onMouseUp(int x, int y)
{
    draw();
}

void ChessGame::draw()
{
    SDL_Surface* screenSurface = SDL_GetWindowSurface(m_window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

    SDL_UpdateWindowSurface(m_window);
}
