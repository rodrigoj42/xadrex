#include "BoardView.h"
#include "ChessGame.h"

#include <iostream>

const int BoardView::TILE_SIZE = 72;

BoardView::BoardView(ChessGame *game) : m_game(game)
{

}

void BoardView::draw(SDL_Surface* surface)
{
    SDL_Surface *background = m_game->resourceManager.loadBitmap("board.bmp");

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;

    SDL_BlitSurface(background, NULL, surface, &destRect);
}

void BoardView::onClick(int x, int y)
{
    int board_x = x / BoardView::TILE_SIZE;
    int board_y = y / BoardView::TILE_SIZE;

    m_game->onClickTile(board_x, board_y);
}
