#ifndef CHESSGAME_H_INCLUDED
#define CHESSGAME_H_INCLUDED

#include "Game.h"

class ChessGame: public Game
{
private:

protected:
    void onMouseMove(int x, int y);
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);

public:
    ChessGame(SDL_Window *window);
    void draw();
};

#endif // CHESSGAME_H_INCLUDED
