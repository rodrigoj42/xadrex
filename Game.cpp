#include <lua.hpp>
#include <iostream>

#include "Game.h"

bool GameSettings::timeLimitPlayerEnabled()
{
    return m_timeLimitPlayerEnabled;
}

unsigned int GameSettings::timeLimitPlayer()
{
    return m_timeLimitPlayer;
}

bool GameSettings::timeLimitTurnEnabled()
{
    return m_timeLimitTurnEnabled;
}

unsigned int GameSettings::timeLimitTurn()
{
    return m_timeLimitTurn;
}

GameSettings::GameSettings()
{
    lua_State *L = luaL_newstate();

    int err = luaL_dofile(L, GAMESETTINGS_FILENAME);
    if (err) {
        std::cerr << "Cannot run " << GAMESETTINGS_FILENAME << "\n";
        std::cerr << lua_tostring(L, -1) << "\n";

        m_timeLimitPlayerEnabled = false;
        m_timeLimitTurnEnabled = false;

        lua_close(L);
        return;
    }

    lua_getglobal(L, GAMESETTINGS_timeLimit_Player);

    if (lua_isboolean(L, -1)) {
        m_timeLimitPlayerEnabled = (bool)lua_toboolean(L, -1);

        if (m_timeLimitPlayerEnabled) {
            std::cerr << GAMESETTINGS_timeLimit_Player << " must be false or a number" << "\n";
            m_timeLimitPlayerEnabled = false;
        }
    }
    else if (lua_isnumber(L, -1)) {
        m_timeLimitPlayerEnabled = true;
        m_timeLimitPlayer = lua_tonumber(L, -1);
    }
    else {
        std::cerr << GAMESETTINGS_timeLimit_Player << " must be false or a number" << "\n";
        m_timeLimitPlayerEnabled = false;
    }

    lua_pop(L, 1);

    lua_getglobal(L, GAMESETTINGS_timeLimit_Turn);

    if (lua_isboolean(L, -1)) {
        m_timeLimitTurnEnabled = (bool)lua_toboolean(L, -1);

        if (m_timeLimitTurnEnabled) {
            std::cerr << GAMESETTINGS_timeLimit_Turn << " must be false or a number" << "\n";
            m_timeLimitTurnEnabled = false;
        }
    }
    else if (lua_isnumber(L, -1)) {
        m_timeLimitTurnEnabled = true;
        m_timeLimitTurn = lua_tonumber(L, -1);
    }
    else {
        std::cerr << GAMESETTINGS_timeLimit_Turn << " must be false or a number" << "\n";
        m_timeLimitTurnEnabled = false;
    }

    lua_close(L);
}
