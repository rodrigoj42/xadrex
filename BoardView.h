#ifndef BOARDVIEW_H_INCLUDED
#define BOARDVIEW_H_INCLUDED

#include <SDL.h>
#include "Control.h"

class ChessGame;

class BoardView: public Control
{
private:
    ChessGame *m_game;

public:
    static const int TILE_SIZE;
    BoardView(ChessGame *game);
    void draw(SDL_Surface *surface);

protected:
    //void onMouseEnter();
    //void onMouseLeave();
    //void onMouseDown();
    //void onMouseUp();
    void onClick(int x, int y);
};

#endif // BOARDVIEW_H_INCLUDED
