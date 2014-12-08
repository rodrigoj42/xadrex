#include <iostream>

#include "ChessGame.h"
#include "Control.h"

ChessGame::ChessGame(SDL_Window* window) : Game(window), boardView(this)
{
    resourceManager.loadBitmap("board.bmp");

    boardView.x = 12;
    boardView.y = 12;
    boardView.width = 8 * BoardView::TILE_SIZE;
    boardView.height = 8 * BoardView::TILE_SIZE;

    m_controlManager.controls.push_back(&boardView);

    L = luaL_newstate();

    luaL_openlibs(L);

    int err = luaL_dofile(L, "Xadrex.lua");

    if (err) {
        std::cerr << "Cannot run Xadrex.lua\n";
        std::cerr << lua_tostring(L, -1) << "\n";
    }
}

ChessGame::~ChessGame()
{
    lua_close(L);
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
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xEE, 0xEE, 0xEE));

    boardView.draw(screenSurface);

    SDL_UpdateWindowSurface(window);
}

void ChessGame::onClickTile(int board_x, int board_y)
{
    std::cout << "onClickTile(" << board_x << ", " << board_y << ")\n";

    lua_getglobal(L, "onClickTile");

    lua_pushnumber(L, board_x);
    lua_pushnumber(L, board_y);

    int err = lua_pcall(L, 2, 1, 0);

    if (err != LUA_OK) {
        std::cerr << "Cannot call onClickTile in lua\n";
        std::cerr << lua_tostring(L, -1) << "\n";
        lua_pop(L, 1);
        return;
    }

    if (!lua_isnumber(L, -1)) {
        std::cerr << "Return value must be a number\n";
        lua_pop(L, 1);
        return;
    }

    int ret = (int)lua_tointeger(L, -1);
    lua_pop(L, 1);

    std::cout << "Lua returned " << ret << "\n";

}
