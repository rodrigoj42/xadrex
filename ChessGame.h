#ifndef CHESSGAME_H_INCLUDED
#define CHESSGAME_H_INCLUDED

#include <lua.hpp>

#include "Game.h"
#include "ControlManager.h"
#include "ResourceManager.h"
#include "BoardView.h"

class ChessGame: public Game
{
private:
    ControlManager m_controlManager;
    BoardView boardView;
    lua_State *L;


protected:
    void onMouseMove(int x, int y);
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);

public:
    ResourceManager resourceManager;

    ChessGame(SDL_Window *window);
    ~ChessGame();
    void draw();
    void onClickTile(int board_x, int board_y);
};

#endif // CHESSGAME_H_INCLUDED
