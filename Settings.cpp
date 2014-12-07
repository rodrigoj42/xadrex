#include <lua.hpp>
#include <iostream>

#include "Game.h"

const char *SETTINGS_FILENAME = "GameSettings.lua";
const char *SETTINGS_timeLimit_Player = "timeLimit_Player";
const char *SETTINGS_timeLimit_Turn ="timeLimit_Turn";

const int Settings::SCREEN_WIDTH = 1280;
const int Settings::SCREEN_HEIGHT = 720;

bool Settings::timeLimitPlayerEnabled()
{
    return m_timeLimitPlayerEnabled;
}

unsigned int Settings::timeLimitPlayer()
{
    return m_timeLimitPlayer;
}

bool Settings::timeLimitTurnEnabled()
{
    return m_timeLimitTurnEnabled;
}

unsigned int Settings::timeLimitTurn()
{
    return m_timeLimitTurn;
}

Settings::Settings()
{
    lua_State *L = luaL_newstate();

    int err = luaL_dofile(L, SETTINGS_FILENAME);
    if (err) {
        std::cerr << "Cannot run " << SETTINGS_FILENAME << "\n";
        std::cerr << lua_tostring(L, -1) << "\n";

        m_timeLimitPlayerEnabled = false;
        m_timeLimitTurnEnabled = false;

        lua_close(L);
        return;
    }

    lua_getglobal(L, SETTINGS_timeLimit_Player);

    if (lua_isboolean(L, -1)) {
        m_timeLimitPlayerEnabled = (bool)lua_toboolean(L, -1);

        if (m_timeLimitPlayerEnabled) {
            std::cerr << SETTINGS_timeLimit_Player << " must be false or a number" << "\n";
            m_timeLimitPlayerEnabled = false;
        }
    }
    else if (lua_isnumber(L, -1)) {
        m_timeLimitPlayerEnabled = true;
        m_timeLimitPlayer = lua_tonumber(L, -1);
    }
    else {
        std::cerr << SETTINGS_timeLimit_Player << " must be false or a number" << "\n";
        m_timeLimitPlayerEnabled = false;
    }

    lua_pop(L, 1);

    lua_getglobal(L, SETTINGS_timeLimit_Turn);

    if (lua_isboolean(L, -1)) {
        m_timeLimitTurnEnabled = (bool)lua_toboolean(L, -1);

        if (m_timeLimitTurnEnabled) {
            std::cerr << SETTINGS_timeLimit_Turn << " must be false or a number" << "\n";
            m_timeLimitTurnEnabled = false;
        }
    }
    else if (lua_isnumber(L, -1)) {
        m_timeLimitTurnEnabled = true;
        m_timeLimitTurn = lua_tonumber(L, -1);
    }
    else {
        std::cerr << SETTINGS_timeLimit_Turn << " must be false or a number" << "\n";
        m_timeLimitTurnEnabled = false;
    }

    lua_close(L);
}
